#ifndef GIMBAL_BEHAVIOUR_H
#define GIMBAL_BEHAVIOUR_H

#include "struct_typedef.h"
#include "gimbal_task.h"

extern void gimbal_behaviour_mode_set(gimbal_control_t *gimbal_mode_set);
extern void gimbal_behaviour_control_set( fp32 *add_pitch, gimbal_control_t *gimbal_control_set);

typedef enum
{
  GIMBAL_RC,
	GIMBAL_AUTO_AIMING,
	SPIN,
	POWERLESS,
	/*
	GIMBAL_ZERO_FORCE = 0, 
  GIMBAL_INIT,           
  GIMBAL_CALI,           
  GIMBAL_ABSOLUTE_ANGLE, 
  GIMBAL_RELATIVE_ANGLE, 
  GIMBAL_MOTIONLESS,     
	*/
} gimbal_behaviour_e;

#endif
