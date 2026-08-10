#ifndef TRIGGER_TASK_H
#define TRIGGER_TASK_H

#include "protocol_mt.h"
#include "pid.h"
#include "remote_control.h"
#include "struct_typedef.h"
//#include "trigger_behaviour.h"

#define trigger_speed_pid_out_max 16000.0f
#define trigger_speed_pid_iout_max 2000.0f
#define M3508_TRIGGER_MOTOR_SPEED_PID_KP 8.0f //10.1
#define M3508_TRIGGER_MOTOR_SPEED_PID_KI 0.3f  //0.8
#define M3508_TRIGGER_MOTOR_SPEED_PID_KD 8.7f //10.5 

//*************************里程碑栈法的控制参数***********//
#define MILESTONE_NEAR_THRESHHOLD 2000
#define MILESTONE_NUMBER 3
#define ECD_FULL_ROUND 8191

#define SHOOT_TASK_INIT_TIME 500

extern void trigger_task(void const *pvParameters);

//**********拨弹轮ECD圈数监控器
struct milestoneStack_s {
    uint8_t head;
    uint8_t stack[MILESTONE_NUMBER+1];
};

typedef struct
{
	const rm_recv_data_t* triiger_motor_meature;
	pid_type_def trigger_motor_rc_pid;
	const RC_ctrl_t *trigger_rc_ctrl;
	
	fp32 rc_cmd_current;
	fp32 given_current;
	fp32 current_set;
	//拨弹轮圈数监控
	fp32 nowECD;
	fp32 initECD;
	fp32 nowRound;
	struct milestoneStack_s mstack; //里程碑栈
}trigger_motor_t;

extern void shootTaskTrggMonitor(void const *pvParameters);


#endif
