#include "stm32f10x.h"                  // Device header
#include "Delay.h"
#include "LED.h"
#include "Key.h"
#include "OLED.h"
#include "Encoder.h"
int16_t num = 0;
int16_t count = 0;
int main(void)
{
	
	OLED_Init();
	Encoder_Init();
	while(1)
	{
		 count += num;
		OLED_ShowSignedNum(1,1,num,5);
	}
}