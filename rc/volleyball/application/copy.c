//include
#include "stdio.h"
#include "can.h"
#include "chassis_pid.h"
#include "chassis_controll.h"


extern CAN_HandleTypeDef hcan2;
extern CAN_HandleTypeDef hcan1;

static uint8_t can_tx_data[8];
static uint8_t can_rx_data[8];
//自定义函数
static void chassis_init(chassis_move_t* chassis_move_init);
static void chassis_set_mode(chassis_move_t* chassis_move_mode);
static void chassis_mode_change_control_transit(chassis_move_t* chassis_move_transit);
static void chassis_feedback_update(chassis_move_t* chassis_move_update);
static void chassis_set_control(chassis_move_t* chassis_move_control);
static void chassis_control_loop(chassis_move_t* chassis_move_PID);
static const can_send_data_channel_s* channel_data;
static const can_send_data_s * yaw_data;
void rm_send_can2(mt_cmd_id_e mt_cmd_id, int16_t motor1, int16_t motor2, int16_t motor3);
		
#if INCLUDE_uxTaskGetStackHighWaterMark
uint32_t chassis_high_water;
#endif

chassis_move_t chassis_move;
 static fp32 power;
 static fp32 buffer;
 //imu中yaw角度&nuc发送的目标角度
//const can_send_data_s *get_yaw_measure_point()
//{
	//return &yaw_data;
//}
 void chassis_task(void const *pvParameters)
{
   //chassis init
    //底盘初始化
    chassis_init(&chassis_move);
	
	while (1)
    {
        HAL_CAN_RxFifo0MsgPendingCallback(&hcan1); 
   			//channel_data = get_channel_measure_point();
			 // yaw_data = get_yaw_measure_point();
			  //printf("%d,%lf\r\n",channel_data->channel_0,yaw_data->yaw);
			  //printf("666\r\n");
			  HAL_CAN_RxFifo0MsgPendingCallback(&hcan2); //can2通道
			  //set chassis control mode
        //设置底盘控制模式
        //chassis_set_mode(&chassis_move);
        //when mode changes, some data save
        //模式切换数据保存
        //chassis_mode_change_control_transit(&chassis_move);
        //chassis data update
        //底盘数据更新
        chassis_feedback_update(&chassis_move);
        //set chassis control set-point 
        //底盘控制量设置
        chassis_set_control(&chassis_move);
        //chassis control pid calculate
        //底盘控制PID计算
        chassis_control_loop(&chassis_move);
			  //printf("pid\r\n");
				//if(chassis_move.chassis_move_mode == POWERLESS)
				//{
					//rm_send_can2(RM_C620_L_ID,0,0,0,0);
				//}
				//else
				//{
			  //发送控制电流
			  rm_send_can2(RM_C620_L_ID,chassis_move.motor_chassis[0].give_current,chassis_move.motor_chassis[1].give_current,
												          chassis_move.motor_chassis[2].give_current);
				//}
			  //CAN_cmd_gimbal(chassis_move.motor_chassis[4].give_current,0,0,0);
//			    printf("%.1lf,%d,%d,%d,%d\n",chassis_move.vx_set,chassis_move.motor_chassis[0].motor_mesure->speed_rpm,-chassis_move.motor_chassis[1].motor_mesure->speed_rpm,
//			                                                     chassis_move.motor_chassis[2].motor_mesure->speed_rpm,-chassis_move.motor_chassis[3].motor_mesure->speed_rpm); 
        //get_chassis_power_and_buffer(&power,&buffer);
        //printf("%lf\n",power);				
				 HAL_Delay(1);
			#if INCLUDE_uxTaskGetStackHighWaterMark
					chassis_high_water = uxTaskGetStackHighWaterMark(NULL);
			#endif
		}
}
 static void chassis_init(chassis_move_t* chassis_move_init)
{
	if(chassis_move_init == NULL) return;
	//速度环PID初始化
	const static fp32 speed_PID[3]={M3508_MOTOR_SPEED_PID_KP,M3508_MOTOR_SPEED_PID_KI,M3508_MOTOR_SPEED_PID_KD};
	//底盘跟随云台PID初始化
	//const static fp32 yaw_PID[3]={M3508_MOTOR_YAW_PID_KP,M3508_MOTOR_YAW_PID_KI,M3508_MOTOR_YAW_PID_KD};
	//const static fp32 follow_gimbal_PID[3]={FOLLOW_GIMBAL_PID_KP,FOLLOW_GIMBAL_PID_KI,FOLLOW_GIMBAL_PID_KD};
//	//获取遥控器指针
//	chassis_move_init->chassis_RC = get_remote_control_point();
	//获取底盘数据指针&PID初始化
	for(int i=0;i<3;i++)
	{
		//chassis_move_init->motor_chassis[i].motor_mesure=get_rm_recv_data(i+1);
		PID_init(&chassis_move_init->chassis_speed_pid[i],PID_DELTA,speed_PID,chassis_speed_pid_out_max,chassis_speed_pid_iout_max);
	}
	//PID_init(&chassis_move_init->follow_gimbal_pid,PID_POSITION ,follow_gimbal_PID,FOLLOW_GIMBAL_PID_OUT_MAX,FOLLOW_GIMBAL_PID_IOUT_MAX);
	//最大最小运动速度限制
	chassis_move_init ->vx_min_speed =NORMAL_MAX_CHASSIS_SPEED_X;
	chassis_move_init ->vx_max_speed =-NORMAL_MAX_CHASSIS_SPEED_X;
	
	chassis_move_init ->vy_min_speed =NORMAL_MAX_CHASSIS_SPEED_Y;
	chassis_move_init ->vy_max_speed =-NORMAL_MAX_CHASSIS_SPEED_Y;
	
	//更新底盘数据
	chassis_feedback_update(chassis_move_init);
	//for(int i=0;i<500;i++)
	//lk_send_can2(LK_MULTIPLE_ID,0,0,0,0);
	//chassis_move_init ->init_Gimbal_Yaw_ECD = get_lk_recv_data(1)->encoder;
}

//static void chassis_set_mode(chassis_move_t* chassis_move_mode)
//{
	//if(chassis_move_mode == NULL) return;
	//chassis_behaviour_mode_set(chassis_move_mode);
//}
int spin_flag;
//模式切换数据保存
//static void chassis_mode_change_control_transit(chassis_move_t* chassis_move_transit)
//{
	//if(chassis_move_transit->chassis_last_move_mode != chassis_move_transit->chassis_move_mode&&chassis_move_transit->chassis_move_mode == CHASSIS_VECTOR_ROTATIONAL)
	//{
		//spin_flag ++;
		//if(spin_flag == 3)
		//spin_flag =1;
	//}
	//if(chassis_move_transit->chassis_last_move_mode!=chassis_move_transit->chassis_move_mode)
	//{
		//for(int i=0;i<4;i++)
		//{
		//	chassis_move_transit->chassis_speed_pid[i].Dbuf[0]=chassis_move_transit->chassis_speed_pid[i].Dbuf[1]=chassis_move_transit->chassis_speed_pid[i].Dbuf[2]=0.0f;
			//chassis_move_transit->chassis_speed_pid[i].Dout=chassis_move_transit->chassis_speed_pid[i].Iout=chassis_move_transit->chassis_speed_pid[i].Pout=0.0f;
			//chassis_move_transit->chassis_speed_pid[i].error[0]=chassis_move_transit->chassis_speed_pid[i].error[1]=chassis_move_transit->chassis_speed_pid[i].error[2]=0.0f;
			
		//	PID_clear(&chassis_move_transit->chassis_speed_pid[i]);
		//}
		
	//}
	//chassis_move_transit->chassis_last_move_mode=chassis_move_transit->chassis_move_mode;
//}
//底盘数据更新
static void chassis_feedback_update(chassis_move_t* chassis_move_update)
{
	if(chassis_move_update ==NULL) return;
	//电机速度更新
	for(int i=0;i<3;i++)
	{
		chassis_move_update->motor_chassis[i].speed=chassis_move_update->motor_chassis[i].speed_rpm * M3508_MOTOR_RPM_TO_VECTOR;
	}
	//移动速度更新
	  chassis_move_update -> vx=(- chassis_move_update ->motor_chassis[0].speed - chassis_move_update ->motor_chassis[1].speed
	                             + chassis_move_update ->motor_chassis[2].speed )*MOTOR_SPEED_TO_CHASSIS_SPEED_VX;
		chassis_move_update -> vy=(chassis_move_update ->motor_chassis[0].speed - chassis_move_update ->motor_chassis[1].speed
	                             - chassis_move_update ->motor_chassis[2].speed )*MOTOR_SPEED_TO_CHASSIS_SPEED_VY;
		chassis_move_update -> wz=(- chassis_move_update ->motor_chassis[0].speed - chassis_move_update ->motor_chassis[1].speed
	                             - chassis_move_update ->motor_chassis[2].speed )*MOTOR_SPEED_TO_CHASSIS_SPEED_WZ;
}

//底盘控制量设置
static void chassis_set_control(chassis_move_t* chassis_move_control)
{
	//if(chassis_move_control == NULL) return;
	fp32 vx_set=0.0f,vy_set=0.0f,wz_set=0.0f;
	
	
	//获取控制量（三向速度）
	//chassis_behaviour_control_set(&vx_set, &vy_set, &wz_set, chassis_move_control);
	
	chassis_move_control->vx_set=vx_set;
	chassis_move_control->vy_set=vy_set;
	//if(spin_flag == 1 || chassis_move_control->chassis_move_mode == BACK_TO_GIMBAL)
	chassis_move_control->wz_set=wz_set;
	//else if(spin_flag == 2)
	//chassis_move_control->wz_set=-wz_set;	
	
}

//麦轮运动分解
static void chassis_vector_to_mecanum_wheel_speed(const fp32 vx_set, const fp32 vy_set, const fp32 wz_set, fp32 wheel_speed[4])
{
    
 
	  wheel_speed[0] = -vx_set*0 + vy_set - (CHASSIS_WZ_SET_SCALE - 1.0f) * MOTOR_DISTANCE_TO_CENTER * wz_set;
    wheel_speed[1] = -0.866*vx_set -0.5* vy_set - (CHASSIS_WZ_SET_SCALE - 1.0f) * MOTOR_DISTANCE_TO_CENTER * wz_set;
    wheel_speed[2] = 0.866*vx_set - 0.5*vy_set - (-CHASSIS_WZ_SET_SCALE - 1.0f) * MOTOR_DISTANCE_TO_CENTER * wz_set;
//	  wheel_speed[0] = -vx_set + vy_set ;
//    wheel_speed[1] = vx_set + vy_set ;
//    wheel_speed[2] = vx_set - vy_set ;
//    wheel_speed[3] = -vx_set - vy_set ;
}
static void chassis_control_loop(chassis_move_t* chassis_move_PID)
{
	
	
	//printf("loop\r\n");
	
	fp32 max_vector=0.0f,vector_rate=0.0f;
  fp32 wheel_speed[3] = {0.0f, 0.0f, 0.0f};
	fp32 temp=0.0f;
	if(chassis_move_PID==NULL) return;
	chassis_vector_to_mecanum_wheel_speed(chassis_move_PID ->vx_set,chassis_move_PID ->vy_set,chassis_move_PID ->wz_set,wheel_speed);
	/*
	if(chassis_move_PID->chassis_move_mode == CHASSIS_VECTOR_STOP)
	{
		 for(int i=0;i<4;i++)
	  {
		  chassis_move_PID->motor_chassis[i].give_current=0.0f;
	  }
		return;
	}
	*/
	//计算最大速度
	for(int i=0;i<3;i++)
	{
		chassis_move_PID->motor_chassis[i].speed_set=wheel_speed[i];
		temp=fabs(chassis_move_PID->motor_chassis[i].speed_set);
		if(temp > max_vector)
		{
			max_vector=temp;
		}
	}
	/*
	//把电机速度限制在最大范围内
	if(max_vector > MAX_WHEEL_SPEED)
	{
		vector_rate=MAX_WHEEL_SPEED/max_vector;
		for(int i=0;i<4;i++)
		{
			chassis_move_PID->motor_chassis[i].speed_set*=vector_rate;
		}
	}
	*/
  //计算PID
	for(int i=0;i<3;i++)
	{
		PID_calc(&chassis_move_PID->chassis_speed_pid[i],chassis_move_PID->motor_chassis[i].speed_rpm,chassis_move_PID->motor_chassis[i].speed_set,1);
		//printf("%.1lf\n",chassis_move_PID->chassis_speed_pid[i].Pout);
	}
	
	//底盘功率控制
	//chassis_power_control(chassis_move_PID);
	
	//printf("power_control\r\n");
	//赋值电流
	//osDelay(50);
	for(int i=0;i<3;i++)
	{
		chassis_move_PID->motor_chassis[i].give_current=(int16_t)(chassis_move_PID->chassis_speed_pid[i].out);
	}	
	
}
void rm_send_can2(mt_cmd_id_e mt_cmd_id, int16_t motor1, int16_t motor2, int16_t motor3)
{
	CAN_TxHeaderTypeDef tx_hander;
	tx_hander.StdId = mt_cmd_id;
	tx_hander.IDE = CAN_ID_STD;
	tx_hander.RTR = CAN_RTR_DATA;
	tx_hander.DLC = 0x08;
	
	can_tx_data[0] = (motor1 >> 8);
	can_tx_data[1] = motor1;
	can_tx_data[2] = (motor2 >> 8);
	can_tx_data[3] = motor2;
	can_tx_data[4] = (motor3 >> 8);
	can_tx_data[5] = motor3;
	can_tx_data[6] = 0;
	can_tx_data[7] = 0;
	
	uint32_t send_mail_box;
	HAL_CAN_AddTxMessage(&hcan2, &tx_hander, can_tx_data, &send_mail_box);
}