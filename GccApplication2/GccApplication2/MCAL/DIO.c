/*
 * IncFile1.h
 *
 * Created: 2/13/2024 1:09:00 PM
 *  Author: hamdy ayman
 */
#include "DIO_INTERFACE.h"



void pinMode(uint8 pin_num ,uint8 DIR)
{
	uint8 port;
	uint8 pin;
	port = pin_num/10; 
	pin = pin_num%10; 
	
	switch(DIR)
	{
		case OUTPUT:
			switch(port)
			{
				case A:
				SET_BIT(DDRA,pin);
				break;
				case B:
				SET_BIT(DDRB,pin);
				break;
				case C:
				SET_BIT(DDRC,pin);
				break;
				case D:
				SET_BIT(DDRD,pin);
				break;

			}
			break;
		case INPUT:
			switch(port)
			{
				case A:
				CLR_BIT(DDRA,pin);
				break;
				case B:
				CLR_BIT(DDRB,pin);
				break;
				case C:
				CLR_BIT(DDRC,pin);
				break;
				case D:
				CLR_BIT(DDRD,pin);
				break;
			}
			break;

	}
}


void digitalWrite(uint8 pin_num ,uint8 STATE)
{
	uint8 port;
	uint8 pin;
	port = pin_num/10;
	pin  = pin_num%10;
	switch(STATE)
	{
		case HIGH:
		switch(port)
		{
			case A:
			SET_BIT(PORTA,pin);
			break;
			case B:
			SET_BIT(PORTB,pin);
			break;
			case C:
			SET_BIT(PORTC,pin);
			break;
			case D:
			SET_BIT(PORTD,pin);
			break;

		}
		break;
		case LOW:
		switch(port)
		{
			case A:
			CLR_BIT(PORTA,pin);
			break;
			case B:
			CLR_BIT(PORTB,pin);
			break;
			case C:
			CLR_BIT(PORTC,pin);
			break;
			case D:
			CLR_BIT(PORTD,pin);
			break;
		}
		break;
	}
	
}


uint8 digitalRead(uint8 pin_num)
{
	uint8 flag = 0;
	uint8 port;
	uint8 pin;
	port = pin_num/10;
	pin  = pin_num%10;
	switch(port)
	{
		case A:
		flag = GET_BIT(PINA,pin);
		break;
		case B:
		flag = GET_BIT(PINB,pin);
		break;
		case C:
		flag = GET_BIT(PINC,pin);
		break;
		case D:
		flag = GET_BIT(PIND,pin);
		break;
	}
	return (flag);
	
}