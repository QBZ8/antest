#include "stm32f10x.h"                  // Device header
#include "Delay.h"
#include "OLED.h"
#include "Key.h"
#include "NRF24L01.h"

uint8_t KeyNum;

int main(void)
{
	OLED_Init();
	Key_Init();
	
	NRF24L01_Init();
	
//	NRF24L01_RxAddress[0] = ;
//	NRF24L01_RxAddress[1] = ;
//	NRF24L01_RxAddress[2] = ;
//	NRF24L01_RxAddress[3] = ;
//	NRF24L01_RxAddress[4] = ;
//	NRF24L01_UpdateRxAddress();
	
	while (1)
	{
		KeyNum = Key_GetNum();
		
		if (KeyNum == 1)
		{
//			NRF24L01_TxAddress[0] = ;
//			NRF24L01_TxAddress[1] = ;
//			NRF24L01_TxAddress[2] = ;
//			NRF24L01_TxAddress[3] = ;
//			NRF24L01_TxAddress[4] = ;
			
			NRF24L01_TxPacket[0] = 0x55;
			NRF24L01_TxPacket[1] = 0x66;
			NRF24L01_TxPacket[2] = 0xAA;
			NRF24L01_TxPacket[3] = 0xBB;
			
			NRF24L01_Send();
		}
		
		if (NRF24L01_Receive() == 1)
		{
			OLED_ShowHexNum(4, 1, NRF24L01_RxPacket[0], 2);
			OLED_ShowHexNum(4, 4, NRF24L01_RxPacket[1], 2);
			OLED_ShowHexNum(4, 7, NRF24L01_RxPacket[2], 2);
			OLED_ShowHexNum(4, 10, NRF24L01_RxPacket[3], 2);
		}
	}
}
