/**
  ************************************* Copyright ****************************** 
  *
  *                 (C) Copyright 2023,HEAS,China, GCU.
  *                            All Rights Reserved
  *                              
  *                     By(HEAS)
  *                     
  *    
  * FileName   : main.c   
  * Version    : v1.0		
  * Author     : HEAS			
  * Date       : 2023-05-29         
  * Description:  
									DHT11 数据脚连接 GPIOB14脚
									OLED  SCL-----PB8
												SDA-----PB9
  * Function List:  
  	1. ....
  	   <version>: 		
  <modify staff>:
  		  <data>:
   <description>:  
  	2. ...
  ******************************************************************************
 */
#include "stm32f10x.h"                  // Device header
#include "Delay.h"
#include "OLED.h"
#include "DHT11.h"
#include "stdio.h"


uint8_t temp, humi;

int main(void)
{


	
	while (1)
	{
		OLED_Init();
    OLED_Clear();

    while (1)
    {

		
		//温湿度传感器
		
        //DHT11_ReadData(&temp, &humi);
      
        Delay_ms(1000);
		OLED_ShowString(1,1,"Southwest Univer");
		OLED_ShowString(2,1,"sity - ROBOCON");
		//OLED_ShowString(3, 1, "temp:");
				//OLED_ShowString(4, 1, " humid");
			  //OLED_ShowNum(3, 6,temp,2);
			  //OLED_ShowNum(4, 6,humi,2);
    }
	}
}
