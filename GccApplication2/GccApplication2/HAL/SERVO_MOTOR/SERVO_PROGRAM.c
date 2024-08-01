/*
 * SERVO_PROGRAM.c
 *
 * Created: 4/22/2024 10:35:58 PM
 *  Author: Right Click
 */ 
#include "SERVO_INTERFACE.h"

#include "../../LIB/delay_imp.h"

//angle 0 --> 180
//return micro
float angleToTime(uint8 angle){ 
	return 1000.0*(angle/180.0 + 1.0);
}

void servo_motor_init(void)
{
	pinMode(motor_1,OUTPUT);
	pinMode(motor_2,OUTPUT);
}

void servo_motor_degree(uint8 motor_pin,uint8 mode)
{
	switch(mode)
	{
		case ON_SERVO_MOTOR:
		digitalWrite(motor_pin,HIGH);
		delay_Imp(angleToTime(250));
		digitalWrite(motor_pin,LOW);
		delay_Imp(50*1000 - angleToTime(250));	
		break;
		
		case OFF_SERVO_MOTOR:
		digitalWrite(motor_pin,HIGH);
		delay_Imp(angleToTime(0));
		//_delay_ms(1);
		digitalWrite(motor_pin,LOW);
		//_delay_ms(49);
		delay_Imp(50*1000 - angleToTime(0));
		break;
		default:
		break;
		
	}
	
	
}