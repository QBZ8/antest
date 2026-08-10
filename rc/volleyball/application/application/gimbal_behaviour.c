#include "main.h"
#include "remote_control.h"
#include "gimbal_behaviour.h"
#include "stdio.h"
#include "protocol_mt.h"
#include "detect_task.h"
static gimbal_behaviour_e gimbal_behaviour ;
//云台状态机
static void gimbal_behaviour_set(gimbal_control_t *gimbal_mode_set);
static void gimbal_rc_control_set(fp32 *add_pitch, gimbal_control_t *gimbal_control_set);
void gimbal_spin_control_set(fp32 *yaw, gimbal_control_t *gimbal_spin_set);

void gimbal_behaviour_mode_set(gimbal_control_t *gimbal_mode_set)
{
	if(gimbal_mode_set == NULL)
	{
		return;
	}
	
    //云台行为状态机设置
    gimbal_behaviour_set(gimbal_mode_set);
	
	  //设置电机状态机
	  if(gimbal_behaviour == POWERLESS )
		{
			gimbal_mode_set->gimbal_yaw_motor.gimbal_motor_mode = GIMBAL_POWERLESS;
		}
		
	  else if(gimbal_behaviour == GIMBAL_AUTO_AIMING)
		{
			gimbal_mode_set->gimbal_yaw_motor.gimbal_motor_mode = AUTO_AIMING;
		}
		else if(gimbal_behaviour == GIMBAL_RC)
		{
			gimbal_mode_set->gimbal_yaw_motor.gimbal_motor_mode = GIMBAL_MOTOR_RC;
		}
		else if(gimbal_behaviour == SPIN)
		{
			gimbal_mode_set->gimbal_yaw_motor.gimbal_motor_mode = CHASSIS_SPIN;
			//printf("chassis_spin\r\n");
		}
		
		
}
//云台行为控制
void gimbal_behaviour_control_set( fp32 *add_yaw, gimbal_control_t *gimbal_control_set)
{
	if(add_yaw == NULL||gimbal_control_set == NULL)
	{
		return;
	}
	
	
	
	if(gimbal_behaviour == GIMBAL_RC)
	{
		gimbal_rc_control_set(add_yaw,gimbal_control_set);
	}
	else if(gimbal_behaviour == SPIN )
	{
		gimbal_spin_control_set(add_yaw,gimbal_control_set);
	}
	
}
fp32 cou_auto;
//云台行为状态机
static void gimbal_behaviour_set(gimbal_control_t *gimbal_mode_set)
{
	 if(gimbal_mode_set == NULL)
	 {
		 return;
	 }
	 //开关控制云台状态
	 /*
	  if(switch_is_up(get_rc_s_point()->s_1))
	 {
		 gimbal_behaviour = GIMBAL_AUTO_AIMING;
	 }
	 */
	  if(get_channel_measure_point()->channel_3 > 700)
	 {
		 cou_auto = 0;
		 gimbal_behaviour = POWERLESS;                        
	 }
	 else if(switch_is_down(get_rc_s_point()->s_1))
	 {
		 cou_auto++;
		 if(cou_auto == 500)
		 {
			 cou_auto = 0;
		   gimbal_behaviour = GIMBAL_AUTO_AIMING;
		 }
	 }
	 else if(get_channel_measure_point()->Q) 
	 {
		 if(gimbal_behaviour != GIMBAL_AUTO_AIMING )
		 gimbal_behaviour  = GIMBAL_AUTO_AIMING;
	 }
	 else if(switch_is_up(get_rc_s_point()->s_0))
	 { 
		 cou_auto = 0;
		 if(gimbal_behaviour != GIMBAL_AUTO_AIMING||(gimbal_behaviour  == GIMBAL_AUTO_AIMING && get_channel_measure_point()->Q))
		 gimbal_behaviour = SPIN;
		 
		 //printf("spin\r\n");
	 }
	 else if(switch_is_down(get_rc_s_point()->s_0)||switch_is_mid(get_rc_s_point()->s_0))
	 {
		 cou_auto = 0;
		 if(gimbal_behaviour != GIMBAL_AUTO_AIMING||(gimbal_behaviour  == GIMBAL_AUTO_AIMING && get_channel_measure_point()->Q))
		 gimbal_behaviour = GIMBAL_RC;                                 //遥控器控制（键盘）
	 }
	 
	
	 
}

static void gimbal_rc_control_set( fp32 *yaw, gimbal_control_t *gimbal_control_set)
{
	if(yaw == NULL||gimbal_control_set == NULL)
	{
		return;
	}
	*yaw = -get_channel_measure_point()->channel_0/10;
}
void gimbal_spin_control_set(fp32 *yaw, gimbal_control_t *gimbal_spin_set)
{
	
	if(yaw == NULL||gimbal_spin_set == NULL)
	{
		return;
	}
	*yaw = get_yaw_measure_point()->yaw;
}