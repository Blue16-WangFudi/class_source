#include "hc-sr04.h"
#include "tim.h"

Hcsr04InfoTypeDef Hcsr04Info;

/**
 * @description: ??????????????????
 * @param {TIM_HandleTypeDef} *htim
 * @param {uint32_t} Channel
 * @return {*}
 */
void Hcsr04Init(TIM_HandleTypeDef *htim, uint32_t Channel)
{
  /*--------[ Configure The HCSR04 IC Timer Channel ] */
  // MX_TIM2_Init();  // cubemx???
  Hcsr04Info.prescaler = htim->Init.Prescaler; //  72-1
  Hcsr04Info.period = htim->Init.Period;       //  65535

  Hcsr04Info.instance = htim->Instance;        //  TIM2
  Hcsr04Info.ic_tim_ch = Channel;
  if(Hcsr04Info.ic_tim_ch == TIM_CHANNEL_1)
  {
    Hcsr04Info.active_channel = HAL_TIM_ACTIVE_CHANNEL_1;             //  TIM_CHANNEL_4
  }
  else if(Hcsr04Info.ic_tim_ch == TIM_CHANNEL_2)
  {
    Hcsr04Info.active_channel = HAL_TIM_ACTIVE_CHANNEL_2;             //  TIM_CHANNEL_4
  }
  else if(Hcsr04Info.ic_tim_ch == TIM_CHANNEL_3)
  {
    Hcsr04Info.active_channel = HAL_TIM_ACTIVE_CHANNEL_3;             //  TIM_CHANNEL_4
  }
  else if(Hcsr04Info.ic_tim_ch == TIM_CHANNEL_4)
  {
    Hcsr04Info.active_channel = HAL_TIM_ACTIVE_CHANNEL_4;             //  TIM_CHANNEL_4
  }
  else if(Hcsr04Info.ic_tim_ch == TIM_CHANNEL_4)
  {
    Hcsr04Info.active_channel = HAL_TIM_ACTIVE_CHANNEL_4;             //  TIM_CHANNEL_4
  }
  /*--------[ Start The ICU Channel ]-------*/
  HAL_TIM_Base_Start_IT(htim);
  HAL_TIM_IC_Start_IT(htim, Channel);
}

/**
 * @description: HC-SR04??
 * @param {*}
 * @return {*}
 */
void Hcsr04Start()
{
  HAL_GPIO_WritePin(GPIOA,GPIO_PIN_5,GPIO_PIN_SET);
  Tims_delay_us(10);  //  10us�ӳ�
  HAL_GPIO_WritePin(GPIOA,GPIO_PIN_5,GPIO_PIN_RESET);
}

/**
 * @description: ?????????????
 * @param {*}    main.c????void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef* htim)
 * @return {*}
 */
void Hcsr04TimOverflowIsr(TIM_HandleTypeDef *htim)
{
  if(htim->Instance == Hcsr04Info.instance) //  TIM2
  {
    Hcsr04Info.tim_overflow_counter++;
  }
}

/**
 * @description: ???????????->??
 * @param {*}    main.c????void HAL_TIM_IC_CaptureCallback(TIM_HandleTypeDef *htim)
 * @return {*}
 */
void Hcsr04TimIcIsr(TIM_HandleTypeDef* htim)
{
  if((htim->Instance == Hcsr04Info.instance) && (htim->Channel == Hcsr04Info.active_channel))
  {
    if(Hcsr04Info.edge_state == 0)      //  ?????
    {
      // ?????????T1,???????????
      Hcsr04Info.t1 = HAL_TIM_ReadCapturedValue(htim, Hcsr04Info.ic_tim_ch);
      __HAL_TIM_SET_CAPTUREPOLARITY(htim, Hcsr04Info.ic_tim_ch, TIM_INPUTCHANNELPOLARITY_FALLING);
      Hcsr04Info.tim_overflow_counter = 0;  //  ??????????
      Hcsr04Info.edge_state = 1;        //  ????????????
    }
    else if(Hcsr04Info.edge_state == 1) //  ?????
    {
      // ???????T2,????????
      Hcsr04Info.t2 = HAL_TIM_ReadCapturedValue(htim, Hcsr04Info.ic_tim_ch);
      Hcsr04Info.t2 += Hcsr04Info.tim_overflow_counter * Hcsr04Info.period; //  ???????????
      Hcsr04Info.high_level_us = Hcsr04Info.t2 - Hcsr04Info.t1; //  ??????? = ?????? - ??????
      // ????
      Hcsr04Info.distance = (Hcsr04Info.high_level_us / 1000000.0) * 340.0 / 2.0 * 100.0;
      // ?????????
      Hcsr04Info.edge_state = 0;  //  ??????,??
      __HAL_TIM_SET_CAPTUREPOLARITY(htim, Hcsr04Info.ic_tim_ch, TIM_INPUTCHANNELPOLARITY_RISING);
    }
  }
}

/**
 * @description: ???? 
 * @param {*}
 * @return {*}
 */
float Hcsr04Read()
{
  // ??????
  if(Hcsr04Info.distance >= 500)
  {
    Hcsr04Info.distance = 500;
  }
  return Hcsr04Info.distance;
}


///**
//  * @brief  ?????us,Prescaler -> 32-1
//  * @param  us: <= 65535
//  * @retval None
//  */
//void Tims_delay_us(uint16_t nus)
//{
//	__HAL_TIM_SET_COUNTER(DLY_TIM_Handle, 0);
//	__HAL_TIM_ENABLE(DLY_TIM_Handle);
//	while (__HAL_TIM_GET_COUNTER(DLY_TIM_Handle) < nus)
//	{
//	}
//	__HAL_TIM_DISABLE(DLY_TIM_Handle);
//}
