/*
 * BUZZER_PROGRAM.c
 *
 * Created: 3/21/2024 2:11:25 AM
 *  Author: Right Click
 */ 
#include "BUZZER_INTERFACEh.h"


void BUZZER_init()
{
	pinMode(BUZZER_PIN,OUTPUT);
}
void BUZZER_on()
{
	digitalWrite(BUZZER_PIN,HIGH);
}
void BUZZER_off()
{
	digitalWrite(BUZZER_PIN,LOW);
}