#include "stm32f10x.h"                  // Device header
#include "Delay.h"

#include "DHT11.h"

#define DHT11_GPIO GPIOB
#define DHT11_PIN GPIO_Pin_9



 
//��ʼ��Ϊ���
 
void DHT11_GPIO_OUT(void)
{
	GPIO_InitTypeDef  GPIO_InitStructure;
	
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB,ENABLE);    //��������GPIO������APB2
		
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_9;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP; //�������������Ҳ����Ч
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_Init(GPIOB, &GPIO_InitStructure);		

}


//��ʼ��Ϊ����
 
 
void DHT11_GPIO_IN(void)
{
	GPIO_InitTypeDef  GPIO_InitStructure;
	
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB,ENABLE);
		
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_9;	
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING; //�������룬���������
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_Init(GPIOB, &GPIO_InitStructure);					
}



uint8_t DHT11_ReadByte(void)
{
	uint8_t temp;
	uint8_t ReadDat=0;
	
	uint8_t retry = 0;	
	uint8_t i;
	//����������ʮ��Ϊ����
	
	
	
	for(i=0;i<8;i++)
	{
		//����׼���źŵ͵�ƽ50us
		while(GPIO_ReadInputDataBit(GPIOB,GPIO_Pin_9)==0&&retry<100)
		{
			Delay_us(1);	
			retry++;		
		}
		retry=0;
		
		
		//��Ȼ0�źų���ʱ��Ϊ28us��retryѭ���ǳ����
		//��������,�൱�����һֱ��0�Ļ����Ա�����ʱ�����Ķ��ʱ��
		Delay_us(30);//�����0����temp=0�����ã���0����Ȼ�ڸߵ�ƽʱ����
		
		//��Ϊ���������0�Ļ�����ʱ��̣�����Ԥ��0���򻯴��롣
		
		temp=0;//�����ź�0��temp=0
		//����0�źŸߵ�ƽ����28us������1�źŸߵ�ƽ70us����ʱ30us��ȷ������0��1
		if(GPIO_ReadInputDataBit(GPIOB,GPIO_Pin_9)==1) 
		{
			temp=1;
		}			
			//����1�źŸߵ�ƽʣ��40us
		while(GPIO_ReadInputDataBit(GPIOB,GPIO_Pin_9)==1&&retry<100)
		{		
			Delay_us(1);
			retry++;
		}
		retry=0;
		//<<=���Ƹ�ֵ���ţ�|=�Ȼ��ٸ�ֵ���õ�1λ���ݣ���8bit
		ReadDat<<=1;
		ReadDat|=temp;
	}	
	return ReadDat;


}

void DHT11_ReadData(uint8_t *temp, uint8_t *humi)
{
    uint8_t i,data[5];
		uint8_t retry=0;
    
	
	
	//stm32 PB14����Ϊ��������Ϳ�ʼ�źŵ͵�ƽ18ms���ߵ�ƽ40us
	DHT11_GPIO_OUT();
	GPIO_ResetBits(GPIOB,GPIO_Pin_9);//�������������ƽ
	Delay_ms(18);//��֤dht11���յ���ʼ�ź�
	
	
	
	GPIO_SetBits(GPIOB,GPIO_Pin_9);//�������������ƽ
	Delay_us(40);//��ʱ40us���ȴ�dht11��Ӧ�ź�
	
	
	//stm32 PB14����Ϊ���룬��鲢������Ӧ�źŵ͵�ƽ80us���ߵ�ƽ80us
	DHT11_GPIO_IN();//���Բ��л���ֱ������ߵ�ƽ������Ҳ�ǿ�����
	Delay_us(20);
	//��ʱ20us��dht11��Ӧ�͵�ƽ80us����ʣ60us������Ƿ��ǵ͵�ƽ��ȷ���Ƿ�����Ӧ�ź�

		
		
		
	if(GPIO_ReadInputDataBit(GPIOB,GPIO_Pin_9)==0)
	{	//��һ��ѭ��������Ӧ�͵�ƽ60us
		while(GPIO_ReadInputDataBit(GPIOB,GPIO_Pin_9)==0&&retry<100)//������Ӧ�źŵ͵�ƽʣ��60us
		{
			Delay_us(1);
			retry++;		
		}
		
		
		retry=0;//����100us�Զ��������У����⿨��
		//����dht11����80us
		while(GPIO_ReadInputDataBit(GPIOB,GPIO_Pin_9)==1&&retry<100)//������Ӧ�źŸߵ�ƽ80us
		{
			Delay_us(1);
			retry++;			
		}
		retry=0;
		
		//����8�ֽ�����,ÿ����1bit֮ǰ�Ƚ�������50us
		//������5λ���ݣ�40bit
		for(i=0;i<5;i++)
		{
			data[i]=DHT11_ReadByte();
		}
		Delay_us(50);//DHT11��������50us��Ϊһ�ֽڽ����źţ�����ʹ���������
        if ((data[0] + data[1] + data[2] + data[3]) == data[4])
        {
            *humi = data[0];
            *temp = data[2];
        }	
				
		

	}

}

