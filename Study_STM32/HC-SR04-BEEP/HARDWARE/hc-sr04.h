#ifndef HCSR04_H_
#define HCSR04_H_

#include "main.h"


//#define DLY_TIM_Handle (&htim1)  

typedef struct
{
	uint8_t  edge_state;
	uint16_t tim_overflow_counter;
	uint32_t prescaler;
	uint32_t period;
	uint32_t t1;	//	?????
	uint32_t t2;	//	?????
	uint32_t high_level_us;	//	???????
	float    distance;
	TIM_TypeDef* instance;
    uint32_t ic_tim_ch;
	HAL_TIM_ActiveChannel active_channel;
}Hcsr04InfoTypeDef;

extern Hcsr04InfoTypeDef Hcsr04Info;

/**
 * @description: ??????????????????
 * @param {TIM_HandleTypeDef} *htim
 * @param {uint32_t} Channel
 * @return {*}
 */
void Hcsr04Init(TIM_HandleTypeDef *htim, uint32_t Channel);

/**
 * @description: HC-SR04??
 * @param {*}
 * @return {*}
 */
void Hcsr04Start();

/**
 * @description: ?????????????
 * @param {*}    main.c????void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef* htim)
 * @return {*}
 */
void Hcsr04TimOverflowIsr(TIM_HandleTypeDef *htim);

/**
 * @description: ???????????->??
 * @param {*}    main.c????void HAL_TIM_IC_CaptureCallback(TIM_HandleTypeDef *htim)
 * @return {*}
 */
void Hcsr04TimIcIsr(TIM_HandleTypeDef* htim);

/**
 * @description: ???? 
 * @param {*}
 * @return {*}
 */
float Hcsr04Read();
//void Tims_delay_us(uint16_t nus);

#endif /* HCSR04_H_ */