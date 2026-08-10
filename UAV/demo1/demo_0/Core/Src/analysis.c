
#include "analysis.h"
#include "main.h"

void beep( )
{
	HAL_GPIO_WritePin(GPIOF,GPIO_PIN_8,GPIO_PIN_SET);
	HAL_Delay(50);
	HAL_GPIO_WritePin(GPIOF,GPIO_PIN_8,GPIO_PIN_RESET);
	HAL_Delay(50);
}

