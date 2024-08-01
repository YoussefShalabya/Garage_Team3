#include "LED_INTERFACE.h"

void LED_init(uint8 led_no)
{
	pinMode(led_no,OUTPUT);
}
void LED_on(uint8 led_no)
{
	digitalWrite(led_no,HIGH);
}
void LED_off(uint8 led_no)
{
	digitalWrite(led_no,LOW);
}

