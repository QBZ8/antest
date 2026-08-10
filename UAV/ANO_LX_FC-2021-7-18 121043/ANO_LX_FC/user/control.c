#include "control.h"
#include "ANO_DT_LX.h"
#include "math.h"                  
#include "pid.h"
#include "LX_FC_Fun.h"
#include "DT_PS.h"
#include "Drv_AnoOf.h"
pid_param_t speed_xy=PID_CREATE(0.78,0.025,0.63,0.5,50,8,40);
//pid_param_t speed_z= PID_CREATE(1.2,0,0.2,0.15,80,50,50);//3s
pid_param_t speed_z= PID_CREATE(2.1,1.5,0.15,0.5,80,50,50);//4s
pid_param_t speed_r= PID_CREATE(2,0,0.1,0.5,50,0,30);
s16 sp_z,sp_x,sp_y,sp_r;

float XYZ_Data[3];
float XYZ_Target[3];
float XYZ_error[3];
float z;
static uint16_t langtimecnt;


float XYZ(void)
{
	XYZ_Target[2]=50;
	XYZ_Data[2]=(float)ano_of.of_alt_cm;
	XYZ_error[2]=XYZ_Target[2]-XYZ_Data[2];
	return XYZ_error[2];
}

float get_z(void)
{
	//z=XYZ();
	return XYZ_Target[2];
}




uint8_t z_pid(float error_z)
{
	sp_z=pid_solve(&speed_z,error_z);
	if(error_z < 5 && error_z > -5)
	{
		sp_z = 0;
	}	
	dt.fun[0xf1].WTS=1;

	if(sp_z==0)	{		return 1;	}
	else	                                  {		return 0;	}
	
}
/*uint8_t toradarpoint(float error_x,float error_y,float error_z,float error_r,float seterror)
{	
   //-----change to world coordinate-----//
	 float angle=get_angle ();
	 double x_r=error_x*cos((double)angle) + error_y*sin((double)angle);
	 double y_r=-error_x*sin((double)angle) + error_y*cos((double)angle);
   //-----pid calculate-----//
	 s16 error_xy=sqrt((double)(x_r*x_r+y_r*y_r));
	 s16 sp_xy=pid_solve(&speed_xy,error_xy);
	 sp_z=pid_solve(&speed_z,error_z); 
	 sp_r=pid_solve(&speed_r,error_r*100);
	 if (error_xy < 0.00001f) 
	 {
    sp_x = 0;
    sp_y = 0;
	 } 
	 else
	 {
    sp_x = sp_xy * (x_r / error_xy);
    sp_y = sp_xy * (y_r / error_xy);
   }


	if(error_x < seterror && error_x > -seterror)
	{
		sp_x = 0;
	}	
	if(error_y < seterror && error_y > -seterror)
	{
		sp_y = 0;
	}	
	if(error_z < 5 && error_z > -5)
	{
		sp_z = 0;
	}	  
	if(error_r < 0.10f && error_r > -0.10f)
	{
		sp_r = 0;
	}	
//	 //############(实时控制帧，自主开发闭环控制，在这里赋值即可)##############
//		//实时XYZ-YAW期望速度(实时控制帧)
////		rt_tar.st_data.yaw_dps = 0;  //航向转动角速度，度每秒，逆时针为正
////		rt_tar.st_data.vel_x = 0;    //头向速度，厘米每秒
////		rt_tar.st_data.vel_y = 0;    //左向速度，厘米每秒
////		rt_tar.st_data.vel_z = 0;	 //天向速度，厘米每秒
//		//########################################################################

//	rt_tar.st_data.vel_x=sp_x;
//	rt_tar.st_data.vel_y=sp_y;
//	rt_tar.st_data.vel_z=sp_z;
//	rt_tar.st_data.yaw_dps =sp_r;
//	rt_tar.st_data.yaw_dps =sp_r;
//	//real ctrl frame
//	dt.fun[0x41].WTS=1;
	
	//ctrl data
	dt.fun[0xf2].WTS=1;

	if(sp_x==0&&sp_y==0&&sp_z==0&&sp_r==0)	{		return 1;	}
	else	                                  {		return 0;	}		
}*/
s16 CtrlData[4];
s16* GetCtrlData (void)
{
	CtrlData[0]=sp_x;
	CtrlData[1]=sp_y;
	CtrlData[2]=sp_z;
	CtrlData[3]=sp_r;
	return CtrlData;
}


uint8_t test(void)
{
	XYZ();
	//dt.fun[0xf1].WTS=1;
	//dt.fun[0xf2].WTS=1;
	if(z_pid(XYZ_error[2]))
	{
		if(langtimecnt < 800)
		{
			langtimecnt+=20;
			return 0;
		}
		else
		{
//		  alltimecnt=0;
		  langtimecnt=0;
			return 1;		  
		}
	}
	else
	{
		langtimecnt=0;
		return 0;
	}
	
}
