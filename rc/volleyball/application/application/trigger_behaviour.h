#ifndef TRIGGER_BEHAVIOUR_H
#define TRIGGER_BEHAVIOUR_H

#include "trigger_task.h"
//按键时间监控
#define PRESS_LONG_TIME     700    //长时间按住的定义为700ms，700个时钟周期
#define SHOOT_CTRL_TIME 5

#define CRAZY_SPEED 16000
#define TRIGGER_SPEED 4000
extern void gimbal_behaviour_mode_set(trigger_motor_t *trigger_mode_set);
typedef enum
{
	TRIGGER_CLOSE,
	TRIGGER_READY,
	TRIGGER_ONE_SHOT,
	TRIGGER_CONTINUE_SHOT,
	CRAZY_MODE,
}trigger_behaviour_e;


#endif
