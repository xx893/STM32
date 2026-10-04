#include "stm32f10x.h"                  // Device header
#include "Delay.h"
void Key_Init()
{
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB,ENABLE);
	GPIO_InitTypeDef GPIO_InitStruct;
	GPIO_InitStruct.GPIO_Mode = GPIO_Mode_IPU;//上拉模式（给它默认值为0），如果是推挽模式则电平一直为低
	GPIO_InitStruct.GPIO_Pin = GPIO_Pin_10|GPIO_Pin_0;
	GPIO_InitStruct.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOB,&GPIO_InitStruct);
}

uint8_t  Key_Number(void)
{
	uint8_t key_num = 0;
	if(GPIO_ReadInputDataBit(GPIOB,GPIO_Pin_10)==0)//读取PB10初始数据
	{
		Delay_ms(20);
		while(GPIO_ReadInputDataBit(GPIOB,GPIO_Pin_10)==0);
		Delay_ms(20);
		key_num = 1;
	}
	if(GPIO_ReadInputDataBit(GPIOB,GPIO_Pin_0)==0)//读取PB0初始数据
	{
		Delay_ms(20);
		while(GPIO_ReadInputDataBit(GPIOB,GPIO_Pin_0)==0);
		Delay_ms(20);
		key_num = 2;
	}
	return key_num;
}