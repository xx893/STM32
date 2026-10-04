#include "stm32f10x.h"                  // Device header

void LED_Init()
{
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA,ENABLE);
	GPIO_InitTypeDef GPIO_InitStruct;
	GPIO_InitStruct.GPIO_Mode = GPIO_Mode_Out_PP;
	GPIO_InitStruct.GPIO_Pin =  GPIO_Pin_0|GPIO_Pin_1;
	GPIO_InitStruct.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOA,&GPIO_InitStruct);
	GPIO_SetBits(GPIOA, GPIO_Pin_All);//给小灯初始值
}

void LED1_Turn()//翻转LED1小灯
{
	if(GPIO_ReadOutputDataBit(GPIOA,GPIO_Pin_0)==0)//读取PA0端口值
		GPIO_WriteBit(GPIOA,GPIO_Pin_0,Bit_SET);
	else
		GPIO_WriteBit(GPIOA,GPIO_Pin_0,Bit_RESET);
}

void LED2_Turn()//翻转LED2小灯
{
	if(GPIO_ReadOutputDataBit(GPIOA,GPIO_Pin_1)==0)//读取PA1端口值
		GPIO_WriteBit(GPIOA,GPIO_Pin_1,Bit_SET);
	else
		GPIO_WriteBit(GPIOA,GPIO_Pin_1,Bit_RESET);
}