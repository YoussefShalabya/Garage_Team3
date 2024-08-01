/*
 * BUTTON_PROGRAM.c
 *
 * Created: 2/28/2024 8:12:02 PM
 *  Author: Right Click
 */ 
#include "BUTTON_INTERFACE.h"

void BUTTON_init()
{
	pinMode(20,INPUT);
	pinMode(21,INPUT);
	pinMode(22,INPUT);
}
uint8 BUTTON_pressed(uint8 BUTTON_Choice)
{
	uint8 flag_pressed = 0;
	uint8 val = 0;
	switch(BUTTON_Choice)
	{
		case 20:
		flag_pressed = digitalRead(20);
		if (flag_pressed == 1)
		{
			val = 0x31;
		}
		else{}
		break;
		case 21:
		flag_pressed = digitalRead(21);
		if (flag_pressed == 1)
		{
			val = 0x32;
		}
		else{}
		break;
		case 22:
		flag_pressed = digitalRead(22);
		if (flag_pressed == 1)
		{
			val = 0x33;
		}
		else{}
		break;
	}
	return (val);
}
