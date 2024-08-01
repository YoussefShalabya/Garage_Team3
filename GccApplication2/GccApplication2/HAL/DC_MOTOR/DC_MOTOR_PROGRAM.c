/*
 * DC_MOTOR_PROGRAM.c
 *
 * Created: 2/28/2024 4:02:02 PM
 *  Author: Right Click
 */ 
#include "DC_MOTOR_INTERFACE.h"

void MOTOR_init()
{
	pinMode(MOTOR_PIN_A,OUTPUT);
	pinMode(MOTOR_PIN_A_1,OUTPUT);
	pinMode(MOTOR_PIN_B,OUTPUT);
	pinMode(MOTOR_PIN_B_1,OUTPUT);
}
void MOTOR_ON(uint8 MOTOR,uint8 direction)
{
	switch(MOTOR)
	{
		case MOTOR_A:
		switch(direction)
		{
			case LEFT:
			digitalWrite(MOTOR_PIN_A,HIGH);
			digitalWrite(MOTOR_PIN_A_1,LOW);
			break;
			case RIGHT:
			digitalWrite(MOTOR_PIN_A,LOW);
			digitalWrite(MOTOR_PIN_A_1,HIGH);
			break;
		}
		break;
		case MOTOR_B:
		switch(direction)
		{
			case LEFT:
			digitalWrite(MOTOR_PIN_B,HIGH);
			digitalWrite(MOTOR_PIN_B_1,LOW);
			break;
			case RIGHT:
			digitalWrite(MOTOR_PIN_B,LOW);
			digitalWrite(MOTOR_PIN_B_1,HIGH);
			break;
		}
		break;
	}
}
void MOTOR_OFF()
{
	digitalWrite(MOTOR_PIN_A,LOW);
	digitalWrite(MOTOR_PIN_A_1,LOW);
	digitalWrite(MOTOR_PIN_B,LOW);
	digitalWrite(MOTOR_PIN_B_1,LOW);
}