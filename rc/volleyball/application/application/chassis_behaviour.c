#include "stdio.h"
#include "chassis_task.h"
#include "chassis_behaviour.h"
#include "remote_control.h"
#include "arm_math.h"
#include "protocol_mt.h"
#include "detect_task.h"
#define MOV_SPEED 5800
//自定义函数
static void chassis_vector_rotational_mode(fp32* vx_set, fp32*vy_set, fp32* angle_set, chassis_move_t* chassis_move_control);
static void chassis_vector_raw(fp32* vx_set, fp32*vy_set, fp32* angle_set, chassis_move_t* chassis_move_control);
static void chassis_vector_back(fp32* vx_set, fp32*vy_set, fp32* angle_set, chassis_move_t* chassis_move_control);
//static void chassis_vector_back(fp32* vx_set, fp32*vy_set, fp32* angle_set, chassis_move_t* chassis_move_control);
void refreshECD(chassis_move_t * relative_angle);
chassis_move_mode_t chassis_behaviour;
chassis_move_mode_t last_chassis_behaviour;

void chassis_behaviour_mode_set(chassis_move_t* chassis_move_mode)
{
	
	if(get_channel_measure_point()->channel_3 >700 && get_channel_measure_point()->channel_3 <1500 )//遥控器离线
	{
		chassis_behaviour = POWERLESS;
		chassis_move_mode->chassis_move_mode = POWERLESS;
	}
	
	else if(switch_is_down(get_rc_s_point()->s_0))
	{
		chassis_behaviour = BACK_TO_GIMBAL;
		chassis_move_mode->chassis_move_mode = BACK_TO_GIMBAL;
	}
	else if(switch_is_up(get_rc_s_point()->s_0))
	{
		chassis_behaviour = CHASSIS_VECTOR_ROTATIONAL;
		chassis_move_mode->chassis_move_mode = CHASSIS_VECTOR_ROTATIONAL;
	}
	
	else if((switch_is_mid(get_rc_s_point()->s_0)))
	{
		
		chassis_behaviour = CHASSIS_VECTOR_RAW;
		chassis_move_mode->chassis_move_mode = CHASSIS_VECTOR_RAW;
	}
	
}

void chassis_behaviour_control_set(fp32* vx_set, fp32*vy_set, fp32* angle_set, chassis_move_t* chassis_move_control)
{
	if(vx_set == NULL || vy_set == NULL||angle_set == NULL||chassis_move_control  == NULL) return;
	
	if(chassis_behaviour == CHASSIS_VECTOR_ROTATIONAL)
	{
    chassis_vector_rotational_mode(vx_set,vy_set,angle_set,chassis_move_control);
	}
	if(chassis_behaviour == CHASSIS_VECTOR_RAW)
	{
		chassis_vector_raw(vx_set,vy_set,angle_set,chassis_move_control);
	}
	
	if(chassis_behaviour == BACK_TO_GIMBAL)
	{
		chassis_vector_back(vx_set,vy_set,angle_set,chassis_move_control);
	}
	
}
/*
//开关下位，停止运行
static void chassis_vector_stop_mode(fp32* vx_set, fp32*vy_set, fp32* angle_set, chassis_move_t* chassis_move_control)
{
	if(vx_set == NULL || vy_set == NULL||angle_set == NULL||chassis_move_control  == NULL) return;
	*vx_set=0.0f;
  *vy_set=0.0f;
	*angle_set =0.0f;
}
*/
//开关上位，小陀螺模式
static void chassis_vector_rotational_mode(fp32* vx_set, fp32*vy_set, fp32* angle_set, chassis_move_t* chassis_move_control)
{
	if(vx_set == NULL || vy_set == NULL||angle_set == NULL||chassis_move_control  == NULL) return;
	refreshECD(chassis_move_control);
	fp32 sin_yaw,cos_yaw,vx_chassis_axis,vy_chassis_axis;
	sin_yaw=arm_sin_f32(chassis_move_control ->gimbal_Angle_From_Chassis);
	cos_yaw=arm_cos_f32(chassis_move_control ->gimbal_Angle_From_Chassis);
	//printf("%lf\r\n",chassis_move_control ->gimbal_Angle_From_Chassis);
	if(get_channel_measure_point()->W||(get_channel_measure_point()->channel_3 > 50 &&get_channel_measure_point()->channel_3 <700))
	{
		vx_chassis_axis = -MOV_SPEED;
	}
	if(get_channel_measure_point()->S||get_channel_measure_point()->channel_3 < -50)
	{
		vx_chassis_axis = MOV_SPEED;
	}
	if(get_channel_measure_point()->A||get_channel_measure_point()->channel_2 < -50)
	{
		vy_chassis_axis = -MOV_SPEED;
	}
	if(get_channel_measure_point()->D||(get_channel_measure_point()->channel_2 > 50 &&get_channel_measure_point()->channel_2 <700))
	{
		vy_chassis_axis = MOV_SPEED;
	}
	
	*vx_set=cos_yaw*vx_chassis_axis-sin_yaw*vy_chassis_axis;
	*vy_set=sin_yaw*vx_chassis_axis+cos_yaw*vy_chassis_axis;
	/*
	*vx_set=0;
	*vy_set=0;
	*/
	
	*angle_set=ROTATIONAL_SPEED;
}
//开关中位，底盘不跟随云台
static void chassis_vector_raw(fp32* vx_set, fp32*vy_set, fp32* angle_set, chassis_move_t* chassis_move_control)
{
	if(vx_set == NULL || vy_set == NULL||angle_set == NULL||chassis_move_control  == NULL) return;
//	*vx_set = chassis_move_control->chassis_RC->rc.ch[3] * CHASSIS__RC_TO_DATA;
//	*vy_set = chassis_move_control->chassis_RC->rc.ch[2]* CHASSIS__RC_TO_DATA;
//	*angle_set =chassis_move_control->chassis_RC->rc.ch[0]* CHASSIS__RC_TO_DATA;
	
	//printf("%d,%d\r\n",get_channel_measure_point()->channel_0,get_channel_measure_point()->W);
	
	refreshECD(chassis_move_control);
	fp32 sin_yaw,cos_yaw,vx_chassis_axis,vy_chassis_axis,vx,vy,target_ECD;
	sin_yaw=arm_sin_f32(chassis_move_control ->gimbal_Angle_From_Chassis);
	cos_yaw=arm_cos_f32(chassis_move_control ->gimbal_Angle_From_Chassis);
	//sin_yaw=arm_sin_f32(0);
	//cos_yaw=arm_cos_f32(0);
	//printf("%lf\r\n",chassis_move_control ->gimbal_Angle_From_Chassis);
	if(get_channel_measure_point()->W||(get_channel_measure_point()->channel_3 > 50 &&get_channel_measure_point()->channel_3 <700))
	{
		vx_chassis_axis = -MOV_SPEED;
	}
	if(get_channel_measure_point()->S||get_channel_measure_point()->channel_3 < -50)
	{
		vx_chassis_axis = MOV_SPEED;
	}
	if(get_channel_measure_point()->A||get_channel_measure_point()->channel_2 < -50)
	{
		vy_chassis_axis = -MOV_SPEED;
	}
	if(get_channel_measure_point()->D||(get_channel_measure_point()->channel_2 > 50 &&get_channel_measure_point()->channel_2 <700))
	{
		vy_chassis_axis = MOV_SPEED;
	}
	
	
	*vx_set=cos_yaw*vx_chassis_axis-sin_yaw*vy_chassis_axis;
	*vy_set=sin_yaw*vx_chassis_axis+cos_yaw*vy_chassis_axis;
	*angle_set=0;
}
pid_type_def pid_back_to_front;
//开关下位，底盘跟随云台
static void chassis_vector_back(fp32* vx_set, fp32*vy_set, fp32* angle_set, chassis_move_t* chassis_move_control)
{
	if(vx_set == NULL || vy_set == NULL||angle_set == NULL||chassis_move_control  == NULL) return;
//	*vx_set = chassis_move_control->chassis_RC->rc.ch[3] * CHASSIS__RC_TO_DATA;
//	*vy_set = chassis_move_control->chassis_RC->rc.ch[2]* CHASSIS__RC_TO_DATA;
//	*angle_set =chassis_move_control->chassis_RC->rc.ch[0]* CHASSIS__RC_TO_DATA;
	
	//printf("%d,%d\r\n",get_channel_measure_point()->channel_0,get_channel_measure_point()->W);
	
	refreshECD(chassis_move_control);
	fp32 sin_yaw,cos_yaw,vx_chassis_axis,vy_chassis_axis,vx,vy,target_ECD;
	sin_yaw=arm_sin_f32(chassis_move_control ->gimbal_Angle_From_Chassis);
	cos_yaw=arm_cos_f32(chassis_move_control ->gimbal_Angle_From_Chassis);
	//printf("%lf\r\n",chassis_move_control ->gimbal_Angle_From_Chassis);
	if(get_channel_measure_point()->W||(get_channel_measure_point()->channel_3 > 50 &&get_channel_measure_point()->channel_3 <700))
	{
		vx_chassis_axis = -MOV_SPEED;
	}
	if(get_channel_measure_point()->S||get_channel_measure_point()->channel_3 < -50 )
	{
		vx_chassis_axis = MOV_SPEED;
	}
	if(get_channel_measure_point()->A||get_channel_measure_point()->channel_2 < -50)
	{
		vy_chassis_axis = -MOV_SPEED;
	}
	if(get_channel_measure_point()->D||(get_channel_measure_point()->channel_2 > 50 &&get_channel_measure_point()->channel_2 <700))
	{
		vy_chassis_axis = MOV_SPEED;
	}
	
	
	*vx_set=cos_yaw*vx_chassis_axis-sin_yaw*vy_chassis_axis;
	*vy_set=sin_yaw*vx_chassis_axis+cos_yaw*vy_chassis_axis;
	//*angle_set=0;
	
	//底盘跟随云台相关
	target_ECD = YAW_INIT_ECD;
	
	if(target_ECD - get_lk_recv_data(1)->encoder > FULL_ROUND_ECD/2 ) target_ECD -= FULL_ROUND_ECD;
	if(target_ECD - get_lk_recv_data(1)->encoder < -FULL_ROUND_ECD/2 ) target_ECD += FULL_ROUND_ECD;
	
	if(chassis_move_control->gimbal_Angle_From_Chassis< 0.05 &&chassis_move_control->gimbal_Angle_From_Chassis > -0.05)
		*angle_set=0;
	else
	*angle_set = PID_calc(&chassis_move_control->follow_gimbal_pid,get_lk_recv_data(1)->encoder,target_ECD,1);
	 //printf("%f,%d\r\n",chassis_move_control->gimbal_Angle_From_Chassis,0);
}
void refreshECD(chassis_move_t * relative_angle)
{
	//relative_angle->now_Gimbal_Yaw_ECD = get_lk_recv_data(1)->encoder;
	relative_angle->gimbal_Angle_From_Chassis = -( YAW_INIT_ECD - get_lk_recv_data(1)->encoder ) / FULL_ROUND_ECD*2*PI;
}
/*
static void chassis_vector_back(fp32* vx_set, fp32*vy_set, fp32* angle_set, chassis_move_t* chassis_move_control)
{
	if(vx_set == NULL || vy_set == NULL||angle_set == NULL||chassis_move_control  == NULL) return;
	fp32 now_ECD,data_angle;
	now_ECD = get_lk_recv_data(1)->encoder;
	refreshECD (chassis_move_control);
	*vx_set = 0;
	*vy_set = 0;
	*angle_set = 0;
	
}
*/