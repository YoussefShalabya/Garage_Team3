/*
 * KEYPAD_PROGRAM.c
 *
 * Created: 3/18/2024 9:14:39 PM
 *  Author: Right Click
 */ 

#include "KEYPAD_INTERFACE.h"
#include <avr/delay.h>


const uint8 keypad[4][4] = {
	{'7', '8', '9', '/'},
	{'4', '5', '6', '*'},
	{'1', '2', '3', '-'},
	{'C', '0', '=', '+'}
};
void KEYPAD_init()
{
	uint8 pin;
	for (pin = KPD_ROW_INIT;pin <= KPD_ROW_END; pin++)
	{
		pinMode(pin,INPUT);
	}
	for (pin = KPD_ROW_INIT;pin <= KPD_ROW_END; pin++)
	{
		digitalWrite(pin,HIGH);
	}
	
	for (pin = KPD_COL_INIT;pin <= KPD_COL_END; pin++)
	{
		pinMode(pin,OUTPUT);
	}
	for (pin = KPD_COL_INIT;pin <= KPD_COL_END; pin++)
	{
		digitalWrite(pin,HIGH);	
	}
}


uint8 KEYPAD_scan()
{
	uint8 col;
	uint8 row;
	uint8 flag;
	uint8 key = NOT_PRESSED;
	for (col = 0 + KPD_COL_INIT ;col <(KPD_COL_END+1) ;col++)
	{
		digitalWrite(col,LOW);
		for(row = 0 +KPD_ROW_INIT ;row <(KPD_ROW_END +1); row++)
		{
			flag = digitalRead(row);
			if (flag ==0)
			{
				_delay_ms(50);
				flag = digitalRead(row);
				if (flag ==0)
				{
					key =keypad[row - KPD_ROW_INIT][col - KPD_COL_INIT];
				}
				while(0 == flag)
				{
					flag = digitalRead(row);
				}
				break;
			}
		}
		digitalWrite(col,HIGH);	
	}
	return key;
}


