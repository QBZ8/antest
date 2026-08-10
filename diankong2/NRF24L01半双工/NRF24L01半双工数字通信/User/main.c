#include "stm32f10x.h"                  // Device header
#include "Delay.h"
#include "OLED.h"
#include "NRF24L01.h"
#include "Key.h"
#include "malloc.h"
#include "math.h"

int main(void)
{
	uint32_t Num = 1200000, RxNum;
	uint8_t Key = 0, TC = 0, RC = 0;
	OLED_Init();
	Key_Init();
	NRF24L01_Init();
	my_mem_init(SRAMIN);
	OLED_ShowString(1, 1, "R:");
	OLED_ShowString(2, 1, "T:");
	OLED_ShowString(3, 1, "TC:00 RC:00");
	
	while (1)
	{
		Key = Key_GetNum();
		if (Key)
		{
			TC ++;
			NRF24L01_SendNum(Num);
			OLED_ShowNum(2, 3, Num, 8);			
			OLED_ShowNum(3, 4, TC, 2);	
			Num ++;
		}
		if (!NRF24L01_Get_Value_Flag())
		{
			RC ++;
			RxNum = NRF24L01_GetNum();
			OLED_ShowNum(3, 10, RC, 2);		
			OLED_ShowNum(1, 3, RxNum, 8);						
		}
		Delay_ms(10);
	}
}
