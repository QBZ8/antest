#include "stm32f10x.h"                  // Device header
#include "Delay.h"
#include "OLED.h"
#include "Key.h"
#include "NRF24L01.h"

uint8_t KeyNum;


uint8_t SendFlag;								//发送标志位
uint8_t SendSuccessCount, SendFailedCount;		//发送成功计次，发送失败计次

uint8_t ReceiveFlag;							//接收标志位
uint8_t ReceiveSuccessCount, ReceiveFailedCount;//接收成功计次，接收失败计次

uint8_t sendData[100]={  0x8F,0x14,0xE3,0x5D,0xBB,0x9A,0x2C,0x71,0xD9,0x06,
						 0xA7,0x3E,0x82,0x4B,0xF0,0xC5,0x39,0x6E,0x53,0x1D,
						 0xFC,0x28,0x97,0x63,0xAD,0x40,
	                     0x7B,0xE8,0x15,0xCE,
						 0x22,0x89,0x56,0xB4,0x0F,0x3A,0xD7,0x60,0x9C,0x77,
						 0x4D,0xEA,0x31,0x8B,0x12,0xF9,0x64,0xA3,0x0C,0x5F,
						 0x91,0x7E,
	                     0xC2,0x29,0x54,0xBF,0x18,0xE6,0x43,0xAA,0x35,0x80,
	                     0xFD,0x1A,0x67,0xBE,0x09,0xD2,0x4E,0x95,
						 0x78,0x26,0xB3,0x0A,0xE1,0x5C,0x87,0x3B,
	                     0x44,0xAF,
						 0x10,0xDB,0x75,0x8E,0x21,0xFA,0x6D,0x34,0x99,0xC6,
						 0x2B,0x50,0xED,0x86,0x1F,0x72,0xBC,0x07,0x48,0xF3};
uint8_t sendData1[26]={0};
uint8_t sendData2[26]={0};
uint8_t sendData3[26]={0};
uint8_t sendData4[10]={0};
uint8_t total=0;
uint8_t error=0;
uint8_t errordata=0;
int main(void)
{
	/*初始化*/
	OLED_Init();
	Key_Init();
	NRF24L01_Init();
	
	/*OLED显示静态字符串*/
	OLED_ShowString(1, 1, "T:000-000-0rec");		//格式为：T:发送成功计次-发送失败计次-发送标志位
	OLED_ShowString(3, 1, "R:000-000-0");		//格式为：R:接收成功计次-接收失败计次-接收标志位
	
	/*初始化测试数据，此处值为任意设定，便于观察实验现象*/
	NRF24L01_TxPacket[0] = 0xAA;
	NRF24L01_TxPacket[1] = 0x00;
	NRF24L01_TxPacket[2] = 0x01;//0x00无分片，0x01有分片，0x02误码率数据
	NRF24L01_TxPacket[3] = 0x1A;
	
	uint8_t count=0;
	
	while (1)
	{
		KeyNum = Key_GetNum();			//读取按键，获取键码
		uint8_t sumcheck=0;
		uint8_t addcheck=0;
		uint8_t rx_sumcheck=0;
		uint8_t rx_addcheck=0;
		if (KeyNum == 1)				//K1按下
		{
			
			if(count>3)
			{
				count=0;
			}
			if(count==3)
			{
				NRF24L01_TxPacket[2] = 0x00;
			}
			else
			{
				NRF24L01_TxPacket[2] = 0x01;
			}
			for(int i=0;i<26;i++)
			{
				NRF24L01_TxPacket[i+4]=sendData[i+26*count];
				
			}
			for(int j=0;j<30;j++)
			{
				sumcheck+=NRF24L01_TxPacket[j];
				addcheck+=sumcheck;
			}
			count+=1;
			NRF24L01_TxPacket[30] = sumcheck;
	        NRF24L01_TxPacket[31] = addcheck;
			/*调用NRF24L01_Send函数，发送数据，同时返回发送标志位，方便用户了解发送状态*/
			/*发送标志位与发送状态的对应关系，可以转到此函数定义上方查看*/
			SendFlag = NRF24L01_Send();
			
			if (SendFlag == 1)			//发送标志位为1，表示发送成功
			{
				SendSuccessCount ++;	//发送成功计次变量自增
			}
			else						//发送标志位不为1，即2/3/4，表示发送不成功
			{
				SendFailedCount ++;		//发送失败计次变量自增
			}
			
			OLED_ShowNum(1, 3, SendSuccessCount, 3);	//显示发送成功次数
			OLED_ShowNum(1, 7, SendFailedCount, 3);		//显示发送失败次数
			OLED_ShowNum(1, 11, SendFlag, 1);			//显示最近一次的发送标志位
			
			/*显示发送数据*/
			OLED_ShowHexNum(2, 1, NRF24L01_TxPacket[0], 2);
			OLED_ShowHexNum(2, 3, NRF24L01_TxPacket[1], 2);
			OLED_ShowHexNum(2, 5, NRF24L01_TxPacket[2], 2);
			OLED_ShowHexNum(2, 7, NRF24L01_TxPacket[3], 2);
			OLED_ShowHexNum(2, 9, NRF24L01_TxPacket[30], 2);
			OLED_ShowHexNum(2, 11, NRF24L01_TxPacket[31], 2);
			OLED_ShowHexNum(2, 14, NRF24L01_TxPacket[4], 2);
			
			/*TX字符串闪烁一次，表明发送了一次数据*/
			OLED_ShowString(1, 15, "TX");
			Delay_ms(100);
			OLED_ShowString(1, 15, "  ");
		}
		if (KeyNum == 2)				//K2按下接收与发送的区别在此，接收机发送误码率，发送机发送错误数据，模拟收到干扰导致信号出错
		{
			
			
			NRF24L01_TxPacket[2] = 0x02;
			NRF24L01_TxPacket[4]=errordata;
			for(int i=0;i<26;i++)
			{
				NRF24L01_TxPacket[i+4]=0;
				
			}
			NRF24L01_TxPacket[4]=errordata;
			for(int j=0;j<30;j++)
			{
				sumcheck+=NRF24L01_TxPacket[j];
				addcheck+=sumcheck;
			}
			NRF24L01_TxPacket[30] = sumcheck;
	        NRF24L01_TxPacket[31] = addcheck;
			/*调用NRF24L01_Send函数，发送数据，同时返回发送标志位，方便用户了解发送状态*/
			/*发送标志位与发送状态的对应关系，可以转到此函数定义上方查看*/
			SendFlag = NRF24L01_Send();
			
			if (SendFlag == 1)			//发送标志位为1，表示发送成功
			{
				SendSuccessCount ++;	//发送成功计次变量自增
			}
			else						//发送标志位不为1，即2/3/4，表示发送不成功
			{
				SendFailedCount ++;		//发送失败计次变量自增
			}
			
			OLED_ShowNum(1, 3, SendSuccessCount, 3);	//显示发送成功次数
			OLED_ShowNum(1, 7, SendFailedCount, 3);		//显示发送失败次数
			OLED_ShowNum(1, 11, SendFlag, 1);			//显示最近一次的发送标志位
			
			/*显示发送数据*/
			OLED_ShowHexNum(2, 1, NRF24L01_TxPacket[0], 2);
			OLED_ShowHexNum(2, 3, NRF24L01_TxPacket[1], 2);
			OLED_ShowHexNum(2, 5, NRF24L01_TxPacket[2], 2);
			OLED_ShowHexNum(2, 7, NRF24L01_TxPacket[3], 2);
			OLED_ShowHexNum(2, 9, NRF24L01_TxPacket[30], 2);
			OLED_ShowHexNum(2, 11, NRF24L01_TxPacket[31], 2);
			OLED_ShowHexNum(2, 14, NRF24L01_TxPacket[4], 2);
			
			/*TX字符串闪烁一次，表明发送了一次数据*/
			OLED_ShowString(1, 15, "TX");
			Delay_ms(100);
			OLED_ShowString(1, 15, "  ");
		}
		
		/*主循环内循环执行NRF24L01_Receive函数，接收数据，同时返回接收标志位，方便用户了解接收状态*/
		/*接收标志位与接收状态的对应关系，可以转到此函数定义上方查看*/
		ReceiveFlag = NRF24L01_Receive();
		
		if (ReceiveFlag)				//接收标志位不为0，表示收到了一个数据包
		{
			
			
			if (ReceiveFlag == 1)		//接收标志位为1，表示接收成功
			{
				ReceiveSuccessCount ++;	//接收成功计次变量自增
			}
			else	//接收标志位不为0也不为1，即2/3，表示此次接收产生了错误，错误接收的数据不应该使用
			{
				ReceiveFailedCount ++;	//接收失败计次变量自增
			}
			for(int j=0;j<30;j++)
			{
				rx_sumcheck+=NRF24L01_RxPacket[j];
				rx_addcheck+=rx_sumcheck;
			}
			
			
			
			if(rx_sumcheck==NRF24L01_RxPacket[30]&&rx_addcheck==NRF24L01_RxPacket[31])
			/*显示接收数据*/
			{
				total+=1;
				errordata=100*error/total;
			OLED_ShowHexNum(4, 1, NRF24L01_RxPacket[0], 2);
			OLED_ShowHexNum(4, 3, NRF24L01_RxPacket[1], 2);
			OLED_ShowHexNum(4, 5, NRF24L01_RxPacket[2], 2);
			OLED_ShowHexNum(4, 7, NRF24L01_RxPacket[3], 2);
			OLED_ShowHexNum(4, 9, NRF24L01_RxPacket[30], 2);
			OLED_ShowHexNum(4, 11, NRF24L01_RxPacket[31], 2);
			OLED_ShowNum(4, 14, errordata, 2);
			
			}
			else
			{
				total+=1;
				error+=1;
				errordata=100*error/total;
				OLED_ShowHexNum(4, 1, NRF24L01_RxPacket[0], 2);
			    OLED_ShowHexNum(4, 3, NRF24L01_RxPacket[1], 2);
			    OLED_ShowHexNum(4, 5, NRF24L01_RxPacket[2], 2);
			    OLED_ShowHexNum(4, 7, NRF24L01_RxPacket[3], 2);
			    OLED_ShowHexNum(4, 9, NRF24L01_RxPacket[30], 2);
			    OLED_ShowHexNum(4, 11, NRF24L01_RxPacket[31], 2);
				OLED_ShowNum(4, 14, errordata, 2);
			}
			OLED_ShowNum(3, 3, total, 3);	//显示总接收次数
			OLED_ShowNum(3, 7, error, 3);	//显示接收错误次数
			OLED_ShowNum(3, 11, ReceiveFlag, 1);		//显示最近一次的接收标志位
			
			/*RX字符串闪烁一次，表明接收到了一次数据*/
			OLED_ShowString(3, 15, "RX");
			Delay_ms(100);
			OLED_ShowString(3, 15, "  ");
		}
	}
}
