#include "stm32f10x.h"                  // Device header
#include "Delay.h"
#include "OLED.h"
#include "TIMER.H"
uint16_t num = 0;
int main(void)
{
	OLED_Init();
	Timer_Init();
	while(1)
	{
		OLED_ShowNum(1,1,num,5);
		OLED_ShowNum(2,1,TIM_GetCounter(TIM2),5);
	}
}

void TIM2_IRQHandler(void)
{
	if(TIM_GetITStatus(TIM2,TIM_IT_Update)==SET)
	{
		num++;
		TIM_ClearITPendingBit(TIM2,TIM_IT_Update);
	}
}