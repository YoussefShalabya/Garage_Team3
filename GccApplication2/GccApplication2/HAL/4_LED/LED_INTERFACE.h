#include "../../LIB/STD_TYPES.h"
#include "../../MCAL/DIO_INTERFACE.h"

#ifndef _LED_INTERFACE_H_ 
#define _LED_INTERFACE_H_
#define LED_NO_0 30
#define LED_NO_1 31
#define LED_NO_2 32
void LED_init(uint8 led_no);
void LED_on(uint8 led_no);
void LED_off(uint8 led_no);
#endif