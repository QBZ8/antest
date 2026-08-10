#ifndef _CONTROL_H
#define _CONTROL_H

#include "sysconfig.h"


uint8_t toradarpoint(float error_x,float error_y,float error_z,float error_r,float seterror);
s16* GetCtrlData (void);
uint8_t test(void);
uint8_t z_pid(float error_z);
float XYZ(void);
float get_z(void);
//float getheight();
#endif
