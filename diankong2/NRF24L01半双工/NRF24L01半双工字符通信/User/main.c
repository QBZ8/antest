#include "stm32f10x.h"                  // Device header
#include "Delay.h"
#include "OLED.h"
#include "NRF24L01.h"
#include "Key.h"
#include "malloc.h"

int main(void)
{
	uint8_t Key = 0, TC = 0, RC = 0;
	uint8_t RxBuf[33], ShowBuf[32], TxBuf[] = {"123456789012345678901234567890"};
	OLED_Init();
	Key_Init();
	NRF24L01_Init();
	my_mem_init(SRAMIN);
	OLED_ShowString(1, 1, "Len:");
	OLED_ShowString(2, 1, "R:");
	OLED_ShowString(3, 1, "T:");
	OLED_ShowString(4, 1, "TC:00 RC:00");
	
	while (1)
	{
		Key = Key_GetNum();
		if (Key)
		{
			TC ++;
			NRF24L01_SendString((char *)TxBuf);			
			OLED_ShowString(3, 3, (char *)TxBuf);			
			OLED_ShowNum(4, 4, TC, 2);	
			for (uint16_t i = 0; i < sizeof(TxBuf) - 1; i ++)
			{
				TxBuf[i] ++;
			}
		}
		if (!NRF24L01_Get_Value_Flag())
		{
			RC ++;
			NRF24L01_GetRxBuf(RxBuf);
			for (uint16_t i = 0; i < 32; i ++)
			{
				ShowBuf[i] = RxBuf[i + 1];
			}
			OLED_ShowNum(1, 5, RxBuf[0], 2);
			OLED_ShowNum(4, 10, RC, 2);		
			OLED_ShowString(2, 3, (char *)ShowBuf);
		}
		Delay_ms(10);
	}
}
