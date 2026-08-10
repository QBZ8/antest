#include "cmsis_os2.h"
#include "LEDType.h"
#include "main.h"
#include "FreeRTOS.h"


 void StartLEDTask(void *argument)
 {
	 for(;;)
	 {
		 LEDMessage *message;
		 osMessageQueueGet(LEDQueueHandle,&message,0,osWaitForever);
		 switch(message->color)
		 {
			 case LEDColor_Red:
				 HAL_GPIO_WritePin(GPIOA,GPIO_PIN_6,message->state?GPIO_PIN_SET:GPIO_PIN_RESET);
				 break;
			 case LEDColor_Blue:
				 HAL_GPIO_WritePin(GPIOA,GPIO_PIN_7,message->state?GPIO_PIN_SET:GPIO_PIN_RESET);
				 break;
			 case LEDColor_Green:
				 HAL_GPIO_WritePin(GPIOB,GPIO_PIN_0,message->state?GPIO_PIN_SET:GPIO_PIN_RESET);
				 break;
		 }
		 vPortFree(message);
		 osDelay(10);
	 }
 }