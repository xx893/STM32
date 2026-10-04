#include "stm32f10x.h"                  // Device header
#include "Delay.h"
#include "OLED.h"
#include "CountSensor.h"
int main(void)
{
	uint16_t Count = 0;
	OLED_Init();
	CountSensor_Init();
	while(1)
	{
		Count = CountSensor_Get();
		OLED_ShowString(1,1,"Count:");
		OLED_ShowNum(1,7,Count,5);
	}
}