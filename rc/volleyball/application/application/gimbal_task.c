#include "gimbal_task.h"
#include "struct_typedef.h"
#include "protocol_mt.h"
#include "bsp_can.h"
#include "bsp_rc.h"
#include "remote_control.h"
#include "main.h"
#include "gimbal_behaviour.h"
#include "cmsis_os.h"
#include "stdio.h"
#include "can.h"


void usart_printf(const char *fmt,...);
//云台初始化
static void gimbal_init(gimbal_control_t *init);
//设置云台控制模式
static void gimbal_set_mode(gimbal_control_t *set_mode);
//设置云台控制设定值
static void gimbal_set_control(gimbal_control_t *set_control);
//云台数据反馈
static void gimbal_feedback_update(gimbal_control_t *feedback_update);
//云台PID计算
static void gimbal_control_loop(gimbal_control_t *control_loop);


//遥控器控制云台
static void gimbal_motor_rc_angle_control(gimbal_motor_t *gimbal_motor);
//小陀螺模式
static void chassis_spin_control(gimbal_motor_t *gimbal_motor);
//自瞄
static void gimbal_auto_aiming_control(gimbal_motor_t *gimbal_motor);

gimbal_control_t gimbal_control;

static fp32 angle_target,angle_current,vel_current;

static fp32 target_angle;
fp32 calc_target(fp32 ref, fp32 set);
int delay_flag;
void gimbal_task(void const *pvParameters)
{
	osDelay(5);
	//云台初始化
	gimbal_init(&gimbal_control);
	while(1)
	{
		HAL_CAN_RxFifo0MsgPendingCallback(&hcan2);
		HAL_CAN_RxFifo0MsgPendingCallback(&hcan1);
		//printf("%.2lf,%.2lf,%d\r\n",get_yaw_measure_point()->yaw,-1.3,get_channel_measure_point()->s_1);
		//printf("%d\r\n",get_channel_measure_point()->channel_0);
		//printf("%lf,%d\r\n",get_yaw_measure_point()->yaw,get_channel_measure_point()->channel_4 );
		//printf("%d,%d\r\n",get_channel_measure_point()->channel_4,get_rc_s_point()->s_0);
		gimbal_set_mode(&gimbal_control);                    //设置云台控制模式
		gimbal_set_control(&gimbal_control);                 //设置云台控制设定值
		gimbal_feedback_update(&gimbal_control);             //云台数据更新
		gimbal_control_loop(&gimbal_control);                //云台控制PID计算
	  if(gimbal_control.gimbal_yaw_motor.gimbal_motor_mode == GIMBAL_POWERLESS)
		{
			lk_send_can2(LK_MULTIPLE_ID,0,0,0,0);  //yaw轴电机驱动
			//rm_send_can2(RM_C620_H_ID,0,0,0,0);
		}
		else
		{
		  if(delay_flag == 0)
			{
				osDelay(100);
				delay_flag = 1;
			}
			lk_send_can2(LK_MULTIPLE_ID,gimbal_control.gimbal_yaw_motor.given_current,0,0,0);  //yaw轴电机驱动
		//lk_send_can2(LK_MULTIPLE_ID,0,0,0,0);  //yaw轴电机驱动
			//lk_send_can2(LK_MULTIPLE_ID,0,0,0,0);//yaw电机编码值读取
			//rm_send_can2(RM_C620_H_ID,gimbal_control.gimbal_pitch_motor.given_current,0,0,0);
		}
		osDelay(10);
		
	}
	
}

//云台初始化
void gimbal_init(gimbal_control_t *init)
{
	
	const static fp32 gimbal_PID[3]={GM6020_MOTOR_SPEED_PID_KP,GM6020_MOTOR_SPEED_PID_KI,GM6020_MOTOR_SPEED_PID_KD};//yaw、pitch 6020
	const static fp32 trigger_PID[3]={M3508_TRIGGER_MOTOR_SPEED_PID_KP,M3508_TRIGGER_MOTOR_SPEED_PID_KI,M3508_TRIGGER_MOTOR_SPEED_PID_KD};//3508 拨弹电机
	//小陀螺
	const static fp32 yaw_spin_PID[3]={SPIN_PID_KP,SPIN_PID_KI,SPIN_PID_KD};
	const static fp32 yaw_spin_speed_PID[3]={SPIN_SPEED_PID_KP,SPIN_SPEED_PID_KI,SPIN_SPEED_PID_KD};
	//串级PID
	const static fp32 gimbal_position_PID[3]={MF7025_MOTOR_POSITION_PID_KP,MF7025_MOTOR_POSITION_PID_KI,MF7025_MOTOR_POSITION_PID_KD};
	const static fp32 gimbal_speed_PID[3]={MF7025_MOTOR_SPEED_PID_KP,MF7025_MOTOR_SPEED_PID_KI,MF7025_MOTOR_SPEED_PID_KD};
	//const static fp32 gimbal_position_PID[3]={GM6020_MOTOR_POSITION_PID_KP,GM6020_MOTOR_POSITION_PID_KI,GM6020_MOTOR_POSITION_PID_KD};
	//const static fp32 gimbal_speed_PID[3]={GM6020_MOTOR_SPEED_PID_KP,GM6020_MOTOR_SPEED_PID_KI,GM6020_MOTOR_SPEED_PID_KD};
	 
	//初次上电标记
	delay_flag = 0;
	
	//电机数据指针获取
    init->gimbal_yaw_motor.gimbal_motor_measure = get_lk_recv_data(1);
	//遥控器数据指针获取
    init->gimbal_rc_ctrl = get_remote_control_point();
	//初始化yaw电机PID
	  /*
	  PID_init(&init->gimbal_yaw_motor.gimbal_motor_rc_pid,PID_DELTA,gimbal_PID,gimbal_speed_pid_out_max,gimbal_speed_pid_iout_max);
	*/
	  PID_init(&init->gimbal_yaw_motor.chassis_spin_pid,PID_POSITION,yaw_spin_PID,yaw_spin_pid_out_max,yaw_spin_pid_iout_max);
	  PID_init(&init->gimbal_yaw_motor.chassis_spin_speed_pid,PID_POSITION,yaw_spin_speed_PID,yaw_spin_speed_pid_out_max,yaw_spin_speed_pid_iout_max);
	
	
	  PID_init(&init->gimbal_yaw_motor.gimbal_motor_rc_position_pid,PID_POSITION,gimbal_position_PID,MF7025_MOTOR_POSITION_PID_MAX_OUT,MF7025_MOTOR_POSITION_PID_MAX_IOUT);
	  PID_init(&init->gimbal_yaw_motor.gimbal_motor_rc_speed_pid,PID_POSITION,gimbal_speed_PID,MF7025_MOTOR_SPEED_PID_MAX_OUT,MF7025_MOTOR_SPEED_PID_MAX_IOUT);
	  
	//PID清除
	  PID_clear(&init->gimbal_yaw_motor.gimbal_motor_rc_pid);
	  init->gimbal_yaw_motor.init_yaw = get_yaw_measure_point()->yaw;
		HAL_Delay(200);
//		for (int i=0;i<500;i++)
//		lk_send_can2(LK_MULTIPLE_ID,0,0,0,0);
   	//angle_target = get_lk_recv_data(1)->encoder;
		init->gimbal_yaw_motor.init_encode = get_lk_recv_data(1)->encoder; 
	  target_angle = get_yaw_measure_point()->yaw;
}

//云台控制模式设置
static void gimbal_set_mode(gimbal_control_t *set_mode)
{
    if (set_mode == NULL)
    {
        return;
    }
    gimbal_behaviour_mode_set(set_mode);
}


//云台控制值设定
static void gimbal_set_control(gimbal_control_t *set_control)
{
    if (set_control == NULL)
    {
        return;
    }
		
		fp32 add_yaw_angle = 0.0f;
		
		gimbal_behaviour_control_set(&add_yaw_angle,set_control);
		
		//yaw电机模式控制
		if(set_control->gimbal_yaw_motor.gimbal_motor_mode == GIMBAL_MOTOR_RC )
		{
			//遥控器控制模式下，直接传入数据
			set_control->gimbal_yaw_motor.rc_cmd_current = add_yaw_angle;
		}
		else if(set_control->gimbal_yaw_motor.gimbal_motor_mode == CHASSIS_SPIN)
		{
			set_control->gimbal_yaw_motor.rc_cmd_current = add_yaw_angle;
		}
}

//云台数据反馈
static void gimbal_feedback_update(gimbal_control_t *feedback_update)
{
    if (feedback_update == NULL)
    {
        return;
    }
		feedback_update ->gimbal_yaw_motor.gimbal_motor_measure = get_lk_recv_data(1);
		//printf("speed:%d\r\n",feedback_update ->gimbal_pitch_motor.gimbal_motor_measure->speed_rpm);
}

//云台控制PID计算
static void gimbal_control_loop(gimbal_control_t *control_loop)
{
    if (control_loop == NULL)
    {
        return;
    }
    
    if (control_loop->gimbal_yaw_motor.gimbal_motor_mode == GIMBAL_MOTOR_RC)
    {
        gimbal_motor_rc_angle_control(&control_loop->gimbal_yaw_motor);
    }
		else if(control_loop->gimbal_yaw_motor.gimbal_motor_mode == CHASSIS_SPIN)
		{
			//printf("goto_spin\r\n");
			 chassis_spin_control(&control_loop->gimbal_yaw_motor);
		}
		else if(control_loop->gimbal_yaw_motor.gimbal_motor_mode == AUTO_AIMING)
		{
			 gimbal_auto_aiming_control(&control_loop->gimbal_yaw_motor);
		}
}


//瓴控角度计算
fp32 calc_angle_target(fp32 ref, fp32 set)
{
	fp32 err = set - ref;
	while (err > 180.0)
	{
		set -= 360.0;
		err = set - ref;
	}
	while (err <= -180.0)
	{
		set += 360.0;
		err = set - ref;
	}
	
	return set;
}
fp32 delta_angle = 0.0;
//fp32 count = 1000;
//遥控器控制云台
static void gimbal_motor_rc_angle_control(gimbal_motor_t *gimbal_motor)
{
	 if(gimbal_motor == NULL)
    {
        return;
    }
		
		//printf("PID\r\n");
		/*
		gimbal_motor->current_set = gimbal_motor->rc_cmd_current;
		PID_calc(&gimbal_motor->gimbal_motor_rc_pid,gimbal_motor->gimbal_motor_measure->speed_dps,gimbal_motor->current_set,1);
		gimbal_motor->given_current = gimbal_motor->gimbal_motor_rc_pid.out;
		
		angle_current = get_lk_recv_data(1)->encoder *360.0/65536.0;
		vel_current = get_lk_recv_data(1)->speed_dps/360.0;
		//angle_target = angle_current-get_channel_measure_point()->channel_0*10.0/660.0;
		
		angle_target-=get_yaw_measure_point()->nuc_yaw*15;
		
		//printf("%f,%f\r\n",get_yaw_measure_point()->nuc_yaw,delta_angle);
		//delta_angle = 0;
		PID_calc(&gimbal_motor->gimbal_motor_rc_position_pid,angle_current,calc_angle_target(angle_current, angle_target),1);
		PID_calc(&gimbal_motor->gimbal_motor_rc_speed_pid,vel_current,gimbal_motor->gimbal_motor_rc_position_pid.out,1);
		gimbal_motor->given_current = gimbal_motor->gimbal_motor_rc_speed_pid.out;
		
		printf("%f,%f,%f,%f,%f,%f\r\n",angle_target, angle_current, gimbal_motor->gimbal_motor_rc_speed_pid.out,
		                                                         gimbal_motor->gimbal_motor_rc_speed_pid.Pout,
		                                                         gimbal_motor->gimbal_motor_rc_speed_pid.Iout,
		                                                         gimbal_motor->gimbal_motor_rc_speed_pid.Dout
		                                                                             );
		*/
		
		target_angle -= get_yaw_measure_point()->nuc_yaw+get_channel_measure_point()->channel_0/50000.0; // rc+keyboard
		target_angle = calc_target(get_yaw_measure_point()->yaw, target_angle);
		PID_calc(&gimbal_motor->chassis_spin_pid,get_yaw_measure_point()->yaw,target_angle,1);
    //usart_printf("%f,%f,%f,%f\r\n",get_yaw_measure_point()->yaw,target_angle,get_lk_recv_data(1)->speed_dps/360.0,gimbal_motor->chassis_spin_pid.out);	
		//printf("%f,%f,%f,%f\r\n",get_yaw_measure_point()->yaw,target_angle,get_lk_recv_data(1)->speed_dps/360.0,gimbal_motor->chassis_spin_pid.out);
		PID_calc(&gimbal_motor->gimbal_motor_rc_speed_pid,get_lk_recv_data(1)->speed_dps/360.0,gimbal_motor->chassis_spin_pid.out,1);
		gimbal_motor->given_current = gimbal_motor->gimbal_motor_rc_speed_pid.out;
		death_limit(gimbal_motor->given_current,20);
		//usart_printf("%f,%f,%f\r\n",gimbal_motor->given_current,get_lk_recv_data(1)->speed_dps/360.0,gimbal_motor->chassis_spin_pid.out);
}

#define PI 3.1415926

fp32 calc_target(fp32 ref, fp32 set)
{
	fp32 err = set - ref;
	while (err > PI)
	{
		set -= 2*PI;
		err = set - ref;
	}
	while (err < -PI)
	{
		set += 2*PI;
		err = set - ref;
	}
	return set;
}

int count = 0;
//小陀螺模式
static void chassis_spin_control(gimbal_motor_t *gimbal_motor)
{
	 if(gimbal_motor == NULL)
    {
        return;
    }
    target_angle -= get_yaw_measure_point()->nuc_yaw+get_channel_measure_point()->channel_0/50000.0; // rc+keyboard
		target_angle = calc_target(get_yaw_measure_point()->yaw, target_angle);
		PID_calc(&gimbal_motor->chassis_spin_pid,get_yaw_measure_point()->yaw,target_angle,1);
		//PID_calc(&gimbal_motor->chassis_spin_speed_pid,get_lk_recv_data(1)->speed_dps/360.0,gimbal_motor->chassis_spin_pid.out,1);
		
		PID_calc(&gimbal_motor->chassis_spin_speed_pid,get_lk_recv_data(1)->speed_dps/360.0,gimbal_motor->chassis_spin_pid.out,1);
		gimbal_motor->given_current = gimbal_motor->chassis_spin_speed_pid.out;
		death_limit(gimbal_motor->given_current,20);
		
}
//自瞄
static void gimbal_auto_aiming_control(gimbal_motor_t *gimbal_motor)
{
	 if(gimbal_motor == NULL)
    {
        return;
    }
    target_angle = get_yaw_measure_point()->nuc_yaw; // rc+keyboard
		target_angle = calc_target(get_yaw_measure_point()->yaw, target_angle);
		PID_calc(&gimbal_motor->chassis_spin_pid,get_yaw_measure_point()->yaw,target_angle,1);
		PID_calc(&gimbal_motor->chassis_spin_speed_pid,get_lk_recv_data(1)->speed_dps/360.0,gimbal_motor->chassis_spin_pid.out,1);
		gimbal_motor->given_current = gimbal_motor->chassis_spin_speed_pid.out;
		death_limit(gimbal_motor->given_current,20);
		
	}

