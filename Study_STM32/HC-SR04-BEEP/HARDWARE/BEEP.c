#include "BEEP.h"
#include "oled.h"
#include "gpio.h"
#include "dht11.h"

void alarm()
{
	OLED_ShowCN_STR(0,0,0,5);
	
	if(DHT11_READ_DATA() < 10)
	{
		OLED_ShowCN_STR(90,0,0,1);
		HAL_GPIO_WritePin(GPIOB,GPIO_PIN_8,GPIO_PIN_SET);
	}
	else if(DHT11_READ_DATA() >= 10)
	{
		OLED_ShowCN_STR(90,0,1,1);
		HAL_GPIO_WritePin(GPIOB,GPIO_PIN_8,GPIO_PIN_RESET);
	}
}