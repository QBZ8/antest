#include "test.h"
#include "math.h"
#include "Drv_AnoOf.h"
#include "ANO_DT_LX.h"

static float XYZ_Data[3];
static float angle;
void fresh_position( float* position_data)
{
	XYZ_Data[0]= *(position_data);
	XYZ_Data[1]= *(position_data+1);
	XYZ_Data[2] = (float)ano_of.of_alt_cm;
	angle=*(position_data+3);
}
float* get_XYZ_Data(void)
{
	return XYZ_Data;
}
float get_angle(void)
{	
  return angle;
}
