#include "trigger_behaviour.h"
#include "remote_control.h"
//#include "trigger_task.h"
#include "stdio.h"
static trigger_behaviour_e trigger_behaviour;
//拨弹电机状态机
static void trigger_behaviour_set(trigger_motor_t *trigger_mode_set);
//static void gimbal_rc_control_set(fp32 *add_pitch, gimbal_control_t *gimbal_control_set);
//按键时长监控
uint32_t pressTime=0;
void trigger_behaviour_mode_set(trigger_motor_t *trigger_mode_set)
{
	if(trigger_mode_set == NULL)
	{
		
		return;
	}
	  //printf("go\r\n"); 
    //云台行为状态机设置
    trigger_behaviour_set(trigger_mode_set);
	
	  //设置电机状态机
	  if(trigger_behaviour == TRIGGER_CLOSE)
		{
			trigger_mode_set->rc_cmd_current = 0 + get_rc_s_point()->ch_4*3;
		}
		else if(trigger_behaviour == TRIGGER_ONE_SHOT || get_channel_measure_point()->channel_3 > 1500)
		{
			//trigger_mode_set->rc_cmd_current = trigger_mode_set->trigger_rc_ctrl->rc.ch[4]*3;
			if(trigger_mode_set->nowRound <=16)
			trigger_mode_set->rc_cmd_current = TRIGGER_SPEED + get_rc_s_point()->ch_4*3;
			else if(trigger_mode_set->nowRound ==18)
			{
				trigger_mode_set->rc_cmd_current = 0 + get_rc_s_point()->ch_4*3;
				trigger_mode_set->nowRound = 0;
				trigger_behaviour = TRIGGER_CLOSE;
			}
			else if(trigger_mode_set->nowRound > 18)
			{
				trigger_mode_set->rc_cmd_current = -TRIGGER_SPEED/4;
			}
		}
		
		//爆管模式
		else if(trigger_behaviour == CRAZY_MODE)
		{
			trigger_mode_set->rc_cmd_current = CRAZY_SPEED;
		}
		
}
/*
//云台行为控制
void gimbal_behaviour_control_set( fp32 *speed, trigger_motor_t *gimbal_control_set)
{
	if(add_pitch == NULL||gimbal_control_set == NULL)
	{
		return;
	}
	
	
	
	if(trigger_behaviour == GIMBAL_RC)
	{
		trigger_rc_control_set(speed,gimbal_control_set);
	}
	
}
*/
//拨弹盘行为状态机
static void trigger_behaviour_set(trigger_motor_t * trigger_mode_set)
{
	 if(trigger_mode_set == NULL)
	 {
		 return;
	 }
	 //开关控制云台状态
	 //printf("%d\r\n",get_rc_s_point()->s_1);
	 
		 //拨弹电机开启
		 if(switch_is_down(get_rc_s_point()->s_1)||get_channel_measure_point()->mouse_press_l)
		 {
			 
            if(pressTime<PRESS_LONG_TIME)
                pressTime+=SHOOT_CTRL_TIME;
						/*
            else    //已经按了足够长的时间了，可以不用再增加了，
            {
                trigger_behaviour = TRIGGER_CONTINUE_SHOT;
            }
						*/
      }  
      else if(switch_is_mid(get_rc_s_point()->s_1)||!(get_channel_measure_point()->mouse_press_l))   //左键抬起
       {
            if(pressTime<PRESS_LONG_TIME)   //拨下并很快抬起，发射一颗
						{
                if(pressTime>0)
                {
                    trigger_behaviour = TRIGGER_ONE_SHOT; 
									
                }
							}
           pressTime=0;
      }                                 
//	 else if(switch_is_up(get_rc_s_point()->s_1)||switch_is_mid(get_rc_s_point()->s_1))
//	 {
//		 
//		 //拨弹电机关闭
//		 trigger_behaviour = TRIGGER_CLOSE;                                  
//	 }
	
	 
//	 else if(get_channel_measure_point()->Q)
//	 {
//		 trigger_behaviour = CRAZY_MODE;
//	 }
	
}
/*
static void trigger_rc_control_set( fp32 *speed, trigger_motor_t *trigger_control_set)
{
	if(speed == NULL||trigger_control_set == NULL)
	{
		return;
	}
	*speed = trigger_control_set->trigger_rc_ctrl->rc.ch[4];
}
*/
