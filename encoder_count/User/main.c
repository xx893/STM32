#include "stm32f10x.h"                  // Device header
#include "Delay.h"
#include "OLED.h"
#include "Encoder.h"
int main(void)
{
	int16_t num;
	OLED_Init();
	Encoder_Init();
	while(1)
	{
		num += Encoder_Get();
		OLED_ShowSignedNum(1,1,num,5);
	}
}