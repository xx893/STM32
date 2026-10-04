#include "stm32f10x.h"                  // Device header

uint16_t CountSensor_Count = 0;
void CountSensor_Init(void)
{
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB,ENABLE);
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_AFIO,ENABLE);
	
	GPIO_InitTypeDef GPIO_InitStruct;
	GPIO_InitStruct.GPIO_Mode = GPIO_Mode_IPU;
	GPIO_InitStruct.GPIO_Pin = GPIO_Pin_14;
	GPIO_InitStruct.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOB,&GPIO_InitStruct);
	
	GPIO_EXTILineConfig(GPIO_PortSourceGPIOB,GPIO_PinSource14);
	
  EXTI_InitTypeDef  EXTI_InitStuct;
	EXTI_InitStuct.EXTI_Line = EXTI_Line14;
	EXTI_InitStuct.EXTI_LineCmd = ENABLE;
	EXTI_InitStuct.EXTI_Mode = EXTI_Mode_Interrupt;
	EXTI_InitStuct.EXTI_Trigger = EXTI_Trigger_Falling;
	EXTI_Init(&EXTI_InitStuct);
	
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);
	
	NVIC_InitTypeDef NVIC_InitStruct;
	NVIC_InitStruct.NVIC_IRQChannel = EXTI15_10_IRQn;
	NVIC_InitStruct.NVIC_IRQChannelCmd = ENABLE;
	NVIC_InitStruct.NVIC_IRQChannelPreemptionPriority = 1;
	NVIC_InitStruct.NVIC_IRQChannelSubPriority = 1;
	NVIC_Init(&NVIC_InitStruct);
}	


uint16_t CountSensor_Get(void)
{
	return(CountSensor_Count);
}
void EXTI15_10_IRQHandler() 
{
	if(EXTI_GetITStatus(EXTI_Line14)==SET)
	{
		//if(GPIO_ReadInputDataBit(GPIOB,GPIO_Pin_14)==1)´íÓëÏÂ½µÑØ²»·û
		CountSensor_Count++;
		EXTI_ClearITPendingBit(EXTI_Line14);
	}
}