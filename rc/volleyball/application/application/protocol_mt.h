#ifndef PROTOCOL_MT_H
#define PROTOCOL_MT_H

#include "struct_typedef.h"
#include "main.h"

typedef enum
{
		LK_SINGLE_ID = 0x140,
		LK_MULTIPLE_ID = 0x280,
	   
	  LK_M1_ID = 0x141,
	
		RM_C620_L_ID = 0x200,
		RM_C620_H_ID = 0x1FF,
	  
	  RM_C620_M1_ID = 0x201,
		RM_C620_M2_ID = 0x202,
	  RM_C620_M3_ID = 0x203,
	  RM_C620_M4_ID = 0x204,
	  RM_C620_M5_ID = 0x205,
	  
	  YAW_DATA = 0x002,
	  
	  RC_DATA = 0x003,
	  RC_S = 0x004,
} mt_cmd_id_e;

typedef struct
{
	uint8_t flag;
	uint8_t temperature;
	int16_t iq;
	int16_t speed_dps;
	int16_t encoder;
} lk_recv_data_t;

typedef struct
{
 uint16_t ecd;
 int16_t speed_rpm;
 int16_t given_current;
 uint8_t temperate;
 int16_t last_ecd;
} rm_recv_data_t;

enum RobotState_e
{
	RobotState_e_Powerless=0,
	
	RobotState_e_GimbalCar=1,
	
	RobotState_e_Spinner=2,
	
	RobotState_e_CommonCar=3,
};
typedef struct
{
	int16_t channel_0;
	int16_t channel_2;
	int16_t channel_3;
	//int16_t channel_4;
	//int16_t s_1;
//	uint8_t s_0;
	//enum RobotState_e mode;
	uint8_t keyboard;
}can_send_encode_data_s;

typedef struct
{
	int16_t channel_0;
	int16_t channel_2;
	int16_t channel_3;
	//enum RobotState_e mode;
	bool_t W;
	bool_t A;
	bool_t S;
	bool_t D;
	bool_t mouse_press_l;
	bool_t Q;
	bool_t G;
}can_send_data_channel_s;

typedef struct
{
	fp32 yaw;
	fp32 nuc_yaw;
	fp32 auto_aiming_yaw;
}can_send_data_s;

typedef struct
{
	uint8_t s_0;
	uint8_t s_1;
	int16_t ch_4;
}can_send_channel_s;

typedef struct
{
	int a;
}can_send_data_keyboard_s;
extern void  lk_send_can2(mt_cmd_id_e mt_cmd_id, int16_t motor1, int16_t motor2, int16_t motor3, int16_t motor4);
extern void  rm_send_can2(mt_cmd_id_e mt_cmd_id, int16_t motor1, int16_t motor2, int16_t motor3, int16_t motor4);
extern const lk_recv_data_t *get_lk_recv_data(uint8_t motor_id);
extern const rm_recv_data_t *get_rm_recv_data(uint8_t motor_id);
extern const can_send_data_s *get_yaw_measure_point();
extern const can_send_data_channel_s *get_channel_measure_point();
extern void CAN2_send_super_c_control(int16_t a,int16_t b,int16_t c);
extern void CAN2_send_super_c_buffer(int16_t buffer);
extern const can_send_channel_s * get_rc_s_point();
#endif
