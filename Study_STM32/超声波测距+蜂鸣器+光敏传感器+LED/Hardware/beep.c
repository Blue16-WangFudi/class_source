#include "stm32f10x.h"
#include "Delay.h"
#include "LED.h"

#define IO GPIO_Pin_15		//HC-SR04模块的Echo脚接GPIOB6

void beep_Init(void){
		RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);
	
	GPIO_InitTypeDef GPIO_InitStructure;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
	GPIO_InitStructure.GPIO_Pin = IO;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOB, &GPIO_InitStructure);
	GPIO_ResetBits(GPIOB, IO);
}
void beep(void){
	LED1_ON();
		GPIO_ResetBits(GPIOB, IO);
		Delay_ms(500);
	LED1_OFF();
		GPIO_SetBits(GPIOB, IO);
	Delay_ms(500);
	LED2_ON();
			GPIO_ResetBits(GPIOB, IO);
		Delay_ms(500);
	LED2_OFF();
			GPIO_SetBits(GPIOB, IO);
	Delay_ms(500);
}
