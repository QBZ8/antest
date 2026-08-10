#ifndef CHASSIS_BEHAVIOUR_H
#define CHASSIS_BEHAVIOUR_H
#include "chassis_task.h"
#include "chassis_behaviour.h"
//自定义函数
extern void chassis_behaviour_mode_set(chassis_move_t *chassis_move_mode);
extern void chassis_behaviour_control_set(fp32* vx_set, fp32*vy_set, fp32* angle_set, chassis_move_t* chassis_move_control);
extern void refreshECD(chassis_move_t * relative_angle);

#ifndef PI
#define PI 3.14
#endif

//小陀螺旋转速度
#define ROTATIONAL_SPEED 3000.0f
//遥控器数据转为发送到can的数据比例
#define CHASSIS__RC_TO_DATA 10
//完整圈数
#define FULL_ROUND_ECD 65535.0

#define YAW_INIT_ECD 16982

#endif
