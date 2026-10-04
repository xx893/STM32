#include "stm32f10x.h"                  // Device header

void LightSensor_Init()
{
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB,ENABLE);
	GPIO_InitTypeDef GPIO_InitStruct;
	GPIO_InitStruct.GPIO_Mode = GPIO_Mode_IN_FLOATING;//光敏传感器模块数据输出模式本来就有上拉电阻
	GPIO_InitStruct.GPIO_Pin =  GPIO_Pin_5;
	GPIO_InitStruct.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOB,&GPIO_InitStruct);
}

uint8_t LightSensor_Set(void)
{
	return GPIO_ReadInputDataBit(GPIOB,GPIO_Pin_5);
}