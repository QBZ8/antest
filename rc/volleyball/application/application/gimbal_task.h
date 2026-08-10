#ifndef GIMBAL_TASK_H
#define GIMBAL_TASK_H

#include "protocol_mt.h"
#include "remote_control.h"
#include "pid.h"
#include "struct_typedef.h"
//单级PID
#define gimbal_speed_pid_out_max 16000.0f
#define gimbal_speed_pid_iout_max 2000.0f



#define GM6020_MOTOR_SPEED_PID_KP 50.5f 
#define GM6020_MOTOR_SPEED_PID_KI 10.0f  
#define GM6020_MOTOR_SPEED_PID_KD 2.5f 
#define GM6020_MOTOR_SPEED_PID_MAX_OUT  16000.0f  //2000.0f
#define GM6020_MOTOR_SPEED_PID_MAX_IOUT 5000.0f //2000.0f

#define GM6020_MOTOR_POSITION_PID_KP 40.0f 
#define GM6020_MOTOR_POSITION_PID_KI 0.0f  
#define GM6020_MOTOR_POSITION_PID_KD 120.5f 
#define GM6020_MOTOR_POSITION_PID_MAX_OUT 2000.0f   //1.0f
#define GM6020_MOTOR_POSITION_PID_MAX_IOUT 20.0f  //0.1f

#define M3508_TRIGGER_MOTOR_SPEED_PID_KP 8.8f //10.1
#define M3508_TRIGGER_MOTOR_SPEED_PID_KI 0.3f  //0.8
#define M3508_TRIGGER_MOTOR_SPEED_PID_KD 8.7f //10.5 

#define yaw_spin_pid_out_max 12000.0f
#define yaw_spin_pid_iout_max 1200.0f
#define SPIN_PID_KP 1.5f  //2.0
#define SPIN_PID_KI 0.0f 
#define SPIN_PID_KD 10.0f  //6.5

#define yaw_spin_speed_pid_out_max 2000.0f
#define yaw_spin_speed_pid_iout_max 2000.0f
#define SPIN_SPEED_PID_KP 2500.0f
#define SPIN_SPEED_PID_KI 0.0f 
#define SPIN_SPEED_PID_KD 200.0f

//串级PID
//串级PID

//lk motor position PID
#define MF7025_MOTOR_POSITION_PID_KP 1.0f  //180.0f
#define MF7025_MOTOR_POSITION_PID_KI 0.0f
#define MF7025_MOTOR_POSITION_PID_KD 0.0f //0.3
#define MF7025_MOTOR_POSITION_PID_MAX_OUT 1000.0f
#define MF7025_MOTOR_POSITION_PID_MAX_IOUT 18.0f

//lk motor speed PID
#define MF7025_MOTOR_SPEED_PID_KP 2500.0f //350 date2.15
#define MF7025_MOTOR_SPEED_PID_KI 35.0f
#define MF7025_MOTOR_SPEED_PID_KD 1.0f//1.0 date2.15
#define MF7025_MOTOR_SPEED_PID_MAX_OUT 3500.0f
#define MF7025_MOTOR_SPEED_PID_MAX_IOUT 1500.0f


#define death_limit(a, b) a = (a > 0 && a < b) ? 0 : ((a < 0 && a > -b) ? 0 : a)
extern lk_recv_data_t lk_recv_data[4];
//云台6020电机控制
typedef enum
{
    GIMBAL_MOTOR_RAW = 0, //电机原始值控制
    GIMBAL_MOTOR_GYRO,    //电机陀螺仪角度控制
    GIMBAL_MOTOR_ENCONDE, //电机编码值角度控制
	  GIMBAL_MOTOR_RC,      //遥控器控制
	  CHASSIS_SPIN,         //小陀螺
	  GIMBAL_POWERLESS,     //无力模式
	  AUTO_AIMING,          //自瞄
} gimbal_motor_mode_e;

typedef struct 
{
	const lk_recv_data_t * gimbal_motor_measure;
	//const rm_recv_data_t * gimbal_motor_measure;
	gimbal_motor_mode_e gimbal_motor_mode;
	pid_type_def gimbal_motor_rc_pid;
	pid_type_def chassis_spin_pid;
	pid_type_def chassis_spin_speed_pid;
	pid_type_def gimbal_motor_rc_position_pid;
	pid_type_def gimbal_motor_rc_speed_pid;
	
	fp32 rc_cmd_current;
	fp32 given_current;
	fp32 current_set;
	fp32 init_yaw;
	fp32 init_encode;
	
}gimbal_motor_t;

typedef struct
{
    const RC_ctrl_t *gimbal_rc_ctrl;
    const fp32 *gimbal_INT_angle_point;
    const fp32 *gimbal_INT_gyro_point;
    gimbal_motor_t gimbal_yaw_motor;
    gimbal_motor_t gimbal_pitch_motor;
	  
    //gimbal_step_cali_t gimbal_cali;
} gimbal_control_t;




extern void gimbal_task(void const *pvParameters);
#endif
