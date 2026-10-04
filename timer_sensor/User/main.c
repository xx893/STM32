#include "stm32f10x.h"                  // Device header
#include "Delay.h"
#include "OLED.h"
#include "Timer.h"
uint16_t num = 0;

int main(void)
{
	Timer_Init();
	OLED_Init();
	OLED_ShowString(1,1,"NUM");
	OLED_ShowString(2,1,"CNT");
//	TIM_PrescalerConfig(TIM2, 0, TIM_PSCReloadMode_Update);//选的不是TIM_PSCReloadMode_Immediate，所以要在第一个时事件结束才能用
	//TIM_CounterModeConfig(TIM2,TIM_CounterMode_Down);
	while(1)
	{
		OLED_ShowNum(1,4,num,5);
		OLED_ShowNum(2,4,Timer_GetCounter(),5);
	}
}

void TIM2_IRQHandler()
{
	if(TIM_GetITStatus(TIM2,TIM_IT_Update) == SET)
	{
		num++;
		TIM_ClearITPendingBit(TIM2,TIM_IT_Update);
	}
}