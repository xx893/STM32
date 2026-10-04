#include "stm32f10x.h"                  // Device header
#include "Delay.h"
#include "LED.h"
#include "Key.h"
int main(void)
{
	uint8_t key_num = 0;
	LED_Init();
	Key_Init();
	while(1)
	{
		key_num = Key_Number();
		if(key_num == 1)
			LED1_Turn();
		if(key_num == 2)
			LED2_Turn();
	}
}