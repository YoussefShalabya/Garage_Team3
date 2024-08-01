/*
 * Ultra_sonic_program.c
 *
 * Created: 7/11/2024 9:11:47 PM
 *  Author: Right Click
 */ 
#include "Ultra_sonic_interface.h"

void ultrasonic_trigger(void);



void Ultra_Sonic_Init(void)
{
	pinMode(ECHO_PIN,INPUT);
	pinMode(TRIG_PIN,OUTPUT);
	digitalWrite(TRIG_PIN,LOW);
}
uint8 Ultra_sonic_read_distance(void)
{
	uint16 count = 0;
	uint16 distance = 0;
	
	ultrasonic_trigger();
	while(digitalRead(ECHO_PIN) == HIGH)
	{
		if(count != 60000)
		{
			count++;
		}
		else
		{
			return(0xFF);
		}
	}
	count = 0;
	while(digitalRead(ECHO_PIN) != HIGH)
	{
		count++;
		_delay_us(1);
	}
	distance = (count * 0.0343) / 2;
	return distance;
}

void ultrasonic_trigger(void)
{
	digitalWrite(TRIG_PIN,HIGH);
	_delay_us(10);
	digitalWrite(TRIG_PIN,LOW);
}