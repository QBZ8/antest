#include "trigger_behaviour.h"
#include "trigger_task.h"
#include "main.h"
#include "can.h"
#include "cmsis_os.h"
#include "bsp_can.h"
#include "bsp_rc.h"
#include "stdio.h"
//初始化拨弹电机
static void trigger_init(trigger_motor_t* init); 
/*
//设置拨弹电机控制模式
static void trigger_set_mode(trigger_motor_t* set_mode);
*/
//设置拨弹电机控制设定值
static void trigger_set_control(trigger_motor_t* set_control);
//拨弹电机数据更新
static void trigger_feedback_update(trigger_motor_t* feedback_update);
//拨弹电机控制PID计算
static void trigger_control_loop(trigger_motor_t* control_loop);
				
trigger_motor_t trigger_control;

void trigger_task(void const *pvParameters)
{
	//初始化拨弹电机
	trigger_init(&trigger_control);
	while(1)
	{
		HAL_CAN_RxFifo0MsgPendingCallback(&hcan2); //can2通道
		HAL_CAN_RxFifo0MsgPendingCallback(&hcan1); //can1通道
		//printf("%d,%d,%d\r\n",get_channel_measure_point()->channel_4,get_channel_measure_point()->s_1,get_channel_measure_point()->s_0);
		//trigger_set_mode(&trigger_control);                    //设置拨弹电机控制模式
		trigger_set_control(&trigger_control);                 //设置拨弹电机控制设定值
		trigger_feedback_update(&trigger_control);             //拨弹电机数据更新
		trigger_control_loop(&trigger_control);                //拨弹电机控制PID计算
	  
		rm_send_can2(RM_C620_H_ID,trigger_control.given_current,0,0,0);  //拨弹电机驱动
		HAL_Delay(5);
	}
}
//初始化拨弹电机
static void trigger_init(trigger_motor_t* init)
{
	//PID参数设定
	const static fp32 trigger_PID[3]={M3508_TRIGGER_MOTOR_SPEED_PID_KP,M3508_TRIGGER_MOTOR_SPEED_PID_KI,M3508_TRIGGER_MOTOR_SPEED_PID_KD};//3508 拨弹电机
	//电机数据指针获取
    init->triiger_motor_meature = get_rm_recv_data(5);
	//遥控器数据指针获取
    init->trigger_rc_ctrl = get_remote_control_point();
	//初始化pitch电机PID
	  PID_init(&init->trigger_motor_rc_pid,PID_DELTA,trigger_PID,trigger_speed_pid_out_max,trigger_speed_pid_iout_max);
	//PID清除
	  PID_clear(&init->trigger_motor_rc_pid);
}

//设置拨弹电机控制设定值
static void trigger_set_control(trigger_motor_t* set_control)
{
	if (set_control == NULL)
    {
        return;
    }
    trigger_behaviour_mode_set(set_control);
}
//拨弹电机数据更新
static void trigger_feedback_update(trigger_motor_t* feedback_update)
{
	if(feedback_update == NULL)
	{
		return;
	}
	feedback_update->triiger_motor_meature = get_rm_recv_data(5);
}
//拨弹电机控制PID计算
static void trigger_control_loop(trigger_motor_t* control_loop)
{
	if(control_loop == NULL)
	{
		return;
	}
	PID_calc(&control_loop->trigger_motor_rc_pid,control_loop->triiger_motor_meature->speed_rpm,control_loop->rc_cmd_current,1);
	//printf("%d,%.1f\r\n",control_loop->triiger_motor_meature->speed_rpm,control_loop->rc_cmd_current);
	control_loop->given_current = control_loop->trigger_motor_rc_pid.out;
}


/**
 * @brief 将ECD差值等化为(0,8191)范围
 * 
 * @param rawECD 
 * @return uint16_t 
 */
static uint16_t ECDFormat(int16_t rawECD)     //test done
{
    while(rawECD<0)
        rawECD+=ECD_FULL_ROUND;
    while(rawECD>=ECD_FULL_ROUND)
        rawECD-=ECD_FULL_ROUND;
    return (uint16_t)rawECD;
}


//拨弹电机圈数计数器
static void monitorTriggerECDRound(void)
{
    uint8_t j;
    // 更新ECD
    trigger_control.nowECD=get_rm_recv_data(5)->ecd;

    for(j=0;j<MILESTONE_NUMBER;j++)    //枚举每一个里程碑所在位置
    {
        fp32 relativeRealECD;
        relativeRealECD=ECDFormat((int16_t)trigger_control.nowECD-(int16_t)trigger_control.initECD);
        //失败原因是0的比较出现了问题
        
        if(ECDFormat(relativeRealECD-j*ECD_FULL_ROUND/MILESTONE_NUMBER)<MILESTONE_NEAR_THRESHHOLD)
                //当前位置落在相应里程碑点所在区域内
        {
            if(j!=(trigger_control.mstack.stack[trigger_control.mstack.head]))
               //不等说明到达了一个新位置，将此新位置加入栈中
            {
                trigger_control.mstack.head++;
                #ifdef WATCH_ARRAY_OUT
                if(c->mstack.head>=MILESTONE_NUMBER)
                {
                    itHappens();    //  让usb task输出此数组越界信息
                    c->mstack.head=MILESTONE_NUMBER-1;
                }
                    
                #endif
                trigger_control.mstack.stack[trigger_control.mstack.head]=j;
            }
        }
    }
    if(((trigger_control.mstack.head)-2)>=0)
    {
        if(trigger_control.mstack.stack[trigger_control.mstack.head]==trigger_control.mstack.stack[trigger_control.mstack.head-2])
            (trigger_control.mstack.head)-=2;
    }
    if(((trigger_control.mstack.head)-3)>=0)
    {
        if(trigger_control.mstack.stack[trigger_control.mstack.head]==trigger_control.mstack.stack[trigger_control.mstack.head-3])
        {//到达了一圈
            if(trigger_control.mstack.stack[1]==1)//正向旋转（逆时针）
                trigger_control.nowRound +=1;
            else
                trigger_control.nowRound -=1;
            trigger_control.mstack.head=0;     // 清空栈，回到初始为0的时候
        }
    }
}

void shootTaskTrggMonitor(void const *pvParameters)
{
    osDelay(SHOOT_TASK_INIT_TIME);
    while(1)
    {
        // if(triggerMonitorSubOn)
            monitorTriggerECDRound();
        osDelay(1);
    }
}