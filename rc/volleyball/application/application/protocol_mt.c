#include "protocol_mt.h"
#include "referee.h"
#include "stdio.h"
extern CAN_HandleTypeDef hcan2;
extern CAN_HandleTypeDef hcan1;

static uint8_t can_tx_data[8];
static uint8_t can_rx_data[8];

static uint8_t can1_tx_data[8];
static uint8_t can1_rx_data[8];

lk_recv_data_t lk_recv_data[4];
rm_recv_data_t rm_recv_data[8];


static can_send_encode_data_s      yaw_encode_data;
static can_send_data_channel_s channel_data;
static can_send_data_s yaw_data;
static can_send_channel_s rc_s_data;

void lk_recv_decoder(lk_recv_data_t *ptr, const uint8_t *data)
{
	ptr->flag = 1;
	ptr->temperature = (uint8_t)data[1];
	ptr->iq = (int16_t)((data[2]) | data[3] << 8);
	ptr->speed_dps = (int16_t)((data[4]) | data[5] << 8);
	ptr->encoder = (int16_t)((data[6]) | data[7] << 8);
}

void rm_recv_decoder(rm_recv_data_t *ptr, const uint8_t *data)
{
	ptr->last_ecd = ptr->ecd;
	ptr->ecd = (uint16_t)((data)[0] << 8 | (data)[1]);
	ptr->speed_rpm = (uint16_t)((data)[2] << 8 | (data)[3]);
	ptr->given_current = (uint16_t)((data)[4] << 8 | (data)[5]);
	ptr->temperate = (data)[6];
}

void lk_send_can2(mt_cmd_id_e mt_cmd_id, int16_t motor1, int16_t motor2, int16_t motor3, int16_t motor4)
{
	CAN_TxHeaderTypeDef tx_hander;
	tx_hander.StdId = mt_cmd_id;
	tx_hander.IDE = CAN_ID_STD;
	tx_hander.RTR = CAN_RTR_DATA;
	tx_hander.DLC = 0x08;
	
	can_tx_data[0] = motor1;
	can_tx_data[1] = (motor1 >> 8);
	can_tx_data[2] = motor2;
	can_tx_data[3] = (motor2 >> 8);
	can_tx_data[4] = motor3;
	can_tx_data[5] = (motor3 >> 8);
	can_tx_data[6] = motor4;
	can_tx_data[7] = (motor4 >> 8);
	
	uint32_t send_mail_box;
	HAL_CAN_AddTxMessage(&hcan2, &tx_hander, can_tx_data, &send_mail_box);
}

void rm_send_can2(mt_cmd_id_e mt_cmd_id, int16_t motor1, int16_t motor2, int16_t motor3, int16_t motor4)
{
	CAN_TxHeaderTypeDef tx_hander;
	tx_hander.StdId = mt_cmd_id;
	tx_hander.IDE = CAN_ID_STD;
	tx_hander.RTR = CAN_RTR_DATA;
	tx_hander.DLC = 0x08;
	
	can_tx_data[0] = (motor1 >> 8);
	can_tx_data[1] = motor1;
	can_tx_data[2] = (motor2 >> 8);
	can_tx_data[3] = motor2;
	can_tx_data[4] = (motor3 >> 8);
	can_tx_data[5] = motor3;
	can_tx_data[6] = (motor4 >> 8);
	can_tx_data[7] = motor4;
	
	uint32_t send_mail_box;
	HAL_CAN_AddTxMessage(&hcan2, &tx_hander, can_tx_data, &send_mail_box);
}

void HAL_CAN_RxFifo0MsgPendingCallback(CAN_HandleTypeDef *hcan)
{
    
	  CAN_RxHeaderTypeDef rx_header;
    HAL_CAN_GetRxMessage(hcan, CAN_RX_FIFO0, &rx_header, can_rx_data);
	  
    switch(rx_header.StdId)
		{
			case RM_C620_M1_ID:
			case RM_C620_M2_ID:
			case RM_C620_M3_ID:
			case RM_C620_M4_ID:
			case RM_C620_M5_ID:
			{
				uint8_t rm_receive_id;
			  rm_receive_id = rx_header.StdId - RM_C620_L_ID;
			  rm_recv_decoder(&rm_recv_data[rm_receive_id - 1], can_rx_data);
				//printf("receive\r\n");
				break;
			}
			
			case LK_M1_ID:
			{
				uint8_t lk_receive_id;
			  lk_receive_id = rx_header.StdId - LK_SINGLE_ID;
			  lk_recv_decoder(&lk_recv_data[lk_receive_id - 1], can_rx_data);
				break;
			}
			case RC_DATA:
				{
					//printf("success\r\n");
					typedef union
					{
						can_send_encode_data_s data_s;
						uint8_t data_uint8_0[sizeof(can_send_encode_data_s)];
					}data_u_0;
					data_u_0 data_0;
					for(int i = 0;i < sizeof(can_send_encode_data_s);i++)
					{
						data_0.data_uint8_0[i] = can_rx_data[i];
					}
					yaw_encode_data = data_0.data_s;
					channel_data.channel_0=yaw_encode_data.channel_0;
					channel_data.channel_2=yaw_encode_data.channel_2;
					channel_data.channel_3=yaw_encode_data.channel_3;
					//channel_data.channel_4=yaw_encode_data.channel_4;
					
					//channel_data.mode = yaw_encode_data.mode;
					
					channel_data.W = ((yaw_encode_data.keyboard & 128) == 128);
					channel_data.A = ((yaw_encode_data.keyboard & 64) == 64);
					channel_data.S = ((yaw_encode_data.keyboard & 32) == 32);
					channel_data.D = ((yaw_encode_data.keyboard & 16) == 16);
					channel_data.mouse_press_l = ((yaw_encode_data.keyboard & 8) == 8);
					channel_data.Q = ((yaw_encode_data.keyboard & 4) == 4); //底盘回正按钮
					channel_data.G = ((yaw_encode_data.keyboard & 2)==  2);
					//printf("%d\r\n",channel_data.channel_0);
					break;
				}
				case YAW_DATA:
				{
					typedef union
					{
						can_send_data_s data_s1;
						uint8_t data_uint8_1[sizeof(can_send_data_s)];
					}data_u_1;
					data_u_1 data_1;
					for(int i = 0;i < sizeof(can_send_data_s);i++)
					{
						data_1.data_uint8_1[i] = can_rx_data[i];
					}
					yaw_data.yaw=data_1.data_s1.yaw;
					yaw_data.nuc_yaw=data_1.data_s1.nuc_yaw;
					yaw_data.auto_aiming_yaw=data_1.data_s1.auto_aiming_yaw;
				//usart_printf("1\r\n");
					break;
				}
				
				case RC_S:
				{
					typedef union
	        {
						can_send_channel_s data;
						uint8_t data_s[sizeof(can_send_channel_s)];
	        }data_s_1;
					data_s_1 data_rc_s;
					for(int i=0;i<sizeof(can_send_channel_s);i++)
					{
						data_rc_s.data_s[i]=can_rx_data[i];
					}
					rc_s_data.s_0 = data_rc_s.data.s_0;
					rc_s_data.s_1 = data_rc_s.data.s_1;
					rc_s_data.ch_4 = data_rc_s.data.ch_4;
				}
				default :
				{
					 //printf("error\r\n");
					 break;
				}
		}
	 /*
		if (rx_header.StdId & LK_SINGLE_ID)
		{
			uint8_t lk_receive_id;
			lk_receive_id = rx_header.StdId - LK_SINGLE_ID;
			lk_recv_decoder(&lk_recv_data[lk_receive_id - 1], can_rx_data);
		}
		else if (rx_header.StdId & RM_C620_L_ID || rx_header.StdId & RM_C620_H_ID)
		{
			//printf("receive\r\n");
			uint8_t rm_receive_id;
			rm_receive_id = rx_header.StdId - RM_C620_L_ID;
			rm_recv_decoder(&rm_recv_data[rm_receive_id - 1], can_rx_data);
		}
	  else if(rx_header.StdId & RC_DATA)
		{
			    //printf("receive\r\n");
			    typedef union
					{
						can_send_encode_data_s data_s;
						uint8_t data_uint8_0[sizeof(can_send_encode_data_s)];
					}data_u_0;
					data_u_0 data_0;
					for(int i = 0;i < sizeof(can_send_encode_data_s);i++)
					{
						data_0.data_uint8_0[i] = can_rx_data[i];
					}
					yaw_encode_data = data_0.data_s;
					channel_data.channel_0=yaw_encode_data.channel_0;
					channel_data.channel_2=yaw_encode_data.channel_2;
					channel_data.channel_3=yaw_encode_data.channel_3;
					channel_data.mode = yaw_encode_data.mode;
					
					channel_data.W = ((yaw_encode_data.keyboard & 128) == 128);
					channel_data.A = ((yaw_encode_data.keyboard & 64) == 64);
					channel_data.S = ((yaw_encode_data.keyboard & 32) == 32);
					channel_data.D = ((yaw_encode_data.keyboard & 16) == 16);
					channel_data.E = ((yaw_encode_data.keyboard & 8) == 8);
					channel_data.F = ((yaw_encode_data.keyboard & 4) == 4);
					channel_data.G = ((yaw_encode_data.keyboard & 2)==  2);
		}
		*/
}

//给超级电容发送剩余buffer
static uint8_t can2_send_super_c_buffer[8];
CAN_TxHeaderTypeDef   can2_tx_message_super_c_buffer;
void CAN2_send_super_c_buffer(int16_t buffer)
{
	  uint32_t send_mail_box;
	  can2_tx_message_super_c_buffer.StdId=0x2E;
		can2_tx_message_super_c_buffer.IDE=CAN_ID_STD;
	  can2_tx_message_super_c_buffer.RTR=CAN_RTR_DATA;
		can2_tx_message_super_c_buffer.DLC=0x08;
		can2_send_super_c_buffer[0]=buffer>>8;
		can2_send_super_c_buffer[1]=buffer;	
	  HAL_CAN_AddTxMessage(&hcan2,&can2_tx_message_super_c_buffer,can2_send_super_c_buffer,&send_mail_box);
}

//给云台转发裁判数据
static uint8_t can1_send_referee[8];
CAN_TxHeaderTypeDef can1_tx_message_referee;
typedef struct {
	int16_t shootspeed;
	uint8_t robot_id;
}can_send_referee_s;
void CAN1_send_referee(int16_t shootspeed,uint8_t robot_color){
	uint32_t send_mail_box;
	typedef union{
		can_send_referee_s data_s_refree;
		uint8_t data[sizeof(can_send_data_keyboard_s)];
	}can_send_referee_u;
	can_send_referee_u data_u;
	data_u.data_s_refree.shootspeed=get_shoot_speed();
	data_u.data_s_refree.robot_id=get_robot_id();
	for(int i=0;i<sizeof(can_send_referee_u);i++){
	can1_send_referee[i]=data_u.data[i];
	}
	can1_tx_message_referee.StdId=0x004;
	can1_tx_message_referee.IDE=CAN_ID_STD;
	can1_tx_message_referee.RTR=CAN_RTR_DATA;
	can1_tx_message_referee.DLC=0x08;
	HAL_CAN_AddTxMessage(&hcan1,&can1_tx_message_referee,can1_send_referee,&send_mail_box);
}

//给超级电容发送控制包
uint8_t can2_send_super_c_ctrl[8];
CAN_TxHeaderTypeDef	can2_tx_message_super_c_ctrl;
void CAN2_send_super_c_control(int16_t a,int16_t b,int16_t c){
	uint32_t send_mail_box;
	can2_tx_message_super_c_ctrl.StdId=0x2F;
	can2_tx_message_super_c_ctrl.IDE=CAN_ID_STD;
	can2_tx_message_super_c_ctrl.RTR=CAN_RTR_DATA;
	can2_tx_message_super_c_ctrl.DLC=0x08;
	can2_send_super_c_ctrl[0]=a>>8;
	can2_send_super_c_ctrl[1]=a;
	can2_send_super_c_ctrl[2]=b>>8;
	can2_send_super_c_ctrl[3]=b;
	can2_send_super_c_ctrl[4]=c>>8;
	can2_send_super_c_ctrl[5]=c;
	can2_send_super_c_ctrl[6]=0x3F;
	can2_send_super_c_ctrl[7]=0x3f;
	HAL_CAN_AddTxMessage(&hcan2,&can2_tx_message_super_c_ctrl,can2_send_super_c_ctrl,&send_mail_box);
}
const lk_recv_data_t *get_lk_recv_data(uint8_t motor_id)
{
	return &lk_recv_data[motor_id - 1];
}

const rm_recv_data_t *get_rm_recv_data(uint8_t motor_id)
{
	return &rm_recv_data[motor_id - 1];
}
//imu中yaw角度&nuc发送的目标角度
const can_send_data_s *get_yaw_measure_point()
{
	return &yaw_data;
}
//遥控器通道值
const can_send_data_channel_s *get_channel_measure_point()
{
	return &channel_data;
}
//遥控器拨杆值
const can_send_channel_s * get_rc_s_point()
{
	return &rc_s_data;
} 
//瓴控电机数据


