/*
 * _7SEGMANT_PROGRAM.c
 *
 * Created: 3/21/2024 1:23:34 AM
 *  Author: Right Click
 */ 
#include "../../MCAL/DIO_INTERFACE.h"
#include "7SEGMANT_INTERFACE.h"
#include "../../LIB/STD_TYPES.h"
#include "../../MCAL/REG.h"
uint8 array[9][7] = {{0,1,1,0,0,0,0},
					 {1,1,0,1,1,0,1},
					 {1,1,1,1,0,0,1},	 
					 {0,1,1,0,0,1,1},
					 {1,0,1,1,0,1,1},
					 {1,0,1,1,1,1,1},
					 {1,1,1,0,0,0,0},
					 {1,1,1,1,1,1,1},
					 {1,1,1,1,0,1,1}};
void LED_7SEGMANT_init()
{
	uint8 pin;
	for (pin = (0 +START_PIN); pin < (END_PIN + 1); pin++)
	{
		pinMode(pin,OUTPUT);
	}
}
void COUNT_DOWN()
{
	sint8 index;
	uint8 led_count;
	for(index = (NUMBERS_7SEGMANT-1) ; index >= 0 ; index--)
	{
		for(led_count = (0 + START_PIN) ; led_count < (END_PIN + 1); led_count++)
		{
			digitalWrite(led_count,array[index][led_count-START_PIN]);
		}
		_delay_ms(1000);
	}
}









