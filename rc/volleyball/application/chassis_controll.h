//Include
#ifndef CHASSIS_CONTROLL_H
#define CHASSIS_CONTROLL_H
#include "struct_typedef.h"
//#include "protocol_mt.h"
#include "chassis_pid.h"
#include "main.h"

//函数申明
extern void chassis_task(void const *pvParameters);

//变量申明
typedef enum
{
	POWERLESS,//停止运行
	CHASSIS_VECTOR_RAW, //直接输入电流，正常供电
	CHASSIS_VECTOR_ROTATIONAL,//小陀螺
	
	BACK_TO_GIMBAL,     //底盘回正
}chassis_move_mode_t;
typedef struct
{
	//const rm_recv_data_t * motor_mesure;
	int16_t speed_rpm;
	int16_t give_current;
	fp32 speed;
	fp32 speed_set;
}chassis_motor_data;
typedef struct
{
  //const RC_ctrl_t *chassis_RC;//获取遥控器数据指针
	chassis_motor_data motor_chassis[3];//底盘电机数据
	pid_type_def chassis_speed_pid[3];//速度环PID
	//pid_type_def follow_gimbal_pid;//角度环PID
	//chassis_move_mode_t chassis_move_mode;//底盘运动模式
	//chassis_move_mode_t chassis_last_move_mode;//底盘上一运动模式
	
	
	fp32 vx;
	fp32 vy;
	fp32 wz;
	fp32 vx_set;
	fp32 vy_set;
	fp32 wz_set;
	
	fp32 vx_max_speed;  //max forward speed, unit m/s.前进方向最大速度 单位m/s
  fp32 vx_min_speed;  //max backward speed, unit m/s.后退方向最大速度 单位m/s
  fp32 vy_max_speed;  //max letf speed, unit m/s.左方向最大速度 单位m/s
  fp32 vy_min_speed;  //max right speed, unit m/s.右方向最大速度 单位m/s
	
	fp32 now_Gimbal_Yaw_ECD;
	fp32 gimbal_Angle_From_Chassis;
	fp32 init_Gimbal_Yaw_ECD;
	
	int16_t rotational_current[3];
	//const rm_recv_data_t* capture_motor_data;
	int16_t rc_current[3];
	int16_t chassis_speed_target[3];
}chassis_move_t;

typedef struct
{
	int16_t channel_0;
	int16_t channel_2;
	int16_t channel_3;
	//enum RobotState_e mode;
	bool_t W;
	bool_t A;
	bool_t S;
	bool_t D;
	bool_t mouse_press_l;
	bool_t Q;
	bool_t G;
}can_send_data_channel_s;

typedef struct
{
	fp32 yaw;
	fp32 nuc_yaw;
	fp32 auto_aiming_yaw;
}can_send_data_s;

typedef enum
{
		LK_SINGLE_ID = 0x140,
		LK_MULTIPLE_ID = 0x280,
	   
	  LK_M1_ID = 0x141,
	
		RM_C620_L_ID = 0x200,
		RM_C620_H_ID = 0x1FF,
	  
	  RM_C620_M1_ID = 0x201,
		RM_C620_M2_ID = 0x202,
	  RM_C620_M3_ID = 0x203,
	  RM_C620_M4_ID = 0x204,
	  RM_C620_M5_ID = 0x205,
	  
	  YAW_DATA = 0x002,
	  
	  RC_DATA = 0x003,
	  RC_S = 0x004,
} mt_cmd_id_e;

typedef struct
{
 uint16_t ecd;
 int16_t speed_rpm;
 int16_t given_current;
 uint8_t temperate;
 int16_t last_ecd;
} rm_recv_data_t;

typedef struct
{
	uint8_t flag;
	uint8_t temperature;
	int16_t iq;
	int16_t speed_dps;
	int16_t encoder;
} lk_recv_data_t;
#define rotational_speed_current 2000

//速度环PID
#define chassis_speed_pid_out_max 16000.0f
#define chassis_speed_pid_iout_max 2000.0f
#define M3508_MOTOR_SPEED_PID_KP 0.0f
#define M3508_MOTOR_SPEED_PID_KI 0.0f
#define M3508_MOTOR_SPEED_PID_KD 0.0f

//角度环PID
#define chassis_yaw_pid_out_max 0.0f
#define chassis_yaw_pid_iout_max 0.0f
#define M3508_MOTOR_YAW_PID_KP 0.0f
#define M3508_MOTOR_YAW_PID_KI 0.0f
#define M3508_MOTOR_YAW_PID_KD 0.0f 


//底盘跟随云台PID
#define FOLLOW_GIMBAL_PID_KP 0.5f
#define FOLLOW_GIMBAL_PID_KI 0.0f
#define FOLLOW_GIMBAL_PID_KD 0.05f
#define FOLLOW_GIMBAL_PID_OUT_MAX  30000.0f
#define FOLLOW_GIMBAL_PID_IOUT_MAX 1200.0f

//m3508转化成底盘速度(m/s)的比例，
#define M3508_MOTOR_RPM_TO_VECTOR 0.000415809748903494517209f
#define M3508_MOTOR_RPM_TO_VECTOR_2 0.000415809748903494517209f
//电机速度转化为机器人运动速度(m/s)
#define MOTOR_SPEED_TO_CHASSIS_SPEED_VX  0.57735f//0.25f
#define MOTOR_SPEED_TO_CHASSIS_SPEED_VY  0.5f//0.25f
#define MOTOR_SPEED_TO_CHASSIS_SPEED_WZ 0.25f
//底盘运动过程最大前进速度
#define NORMAL_MAX_CHASSIS_SPEED_X 2.0f
//chassis left or right max speed
//底盘运动过程最大平移速度
#define NORMAL_MAX_CHASSIS_SPEED_Y 1.5f
//底盘运动过程最大旋转速度
#define CHASSIS_WZ_SET_SCALE 0.1f
#define MOTOR_DISTANCE_TO_CENTER 0.6f
//单个电机最大轮速
#define MAX_WHEEL_SPEED 2000.0f
//死区限制
#define DEADLINE 10
//功率限制
#define MAX_Power_1 60
#define MAX_Power_2 80
#define MAX_Power_3 120
#define voltage 24
extern void  rm_send_can2(mt_cmd_id_e mt_cmd_id, int16_t motor1, int16_t motor2, int16_t motor3);
extern void  rm_send_can2(mt_cmd_id_e mt_cmd_id, int16_t motor1, int16_t motor2, int16_t motor3);
#endif