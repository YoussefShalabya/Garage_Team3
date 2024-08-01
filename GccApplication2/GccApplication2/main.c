/*
 * GccApplication2.c
 *
 * Created: 2/13/2024 12:32:41 PM
 * Author : hamdy ayman
 */ 
#define F_CPU 1000000
#include "C:\Users\Administrator\Documents\Atmel Studio\7.0\GccApplication2\GccApplication2\MCAL\DIO_INTERFACE.h"
#include "C:\Users\Administrator\Documents\Atmel Studio\7.0\GccApplication2\GccApplication2\HAL\DC_MOTOR\DC_MOTOR_INTERFACE.h"
#include "C:\Users\Administrator\Documents\Atmel Studio\7.0\GccApplication2\GccApplication2\HAL\4_LED\LED_INTERFACE.h"
#include "C:\Users\Administrator\Documents\Atmel Studio\7.0\GccApplication2\GccApplication2\HAL\BUTTON\BUTTON_INTERFACE.h"
int main(void)
{
	MOTOR_init();
	LED_init();
	BUTTON_init();
	//uint8 enable = 0;
    /* Replace with your application code */
    while (1) 
    {
		
		
		/* if (enable == 0)
		{
		LED_off(LED_NO_0);
		LED_off(LED_NO_1);
		LED_off(LED_NO_2);
		BUTTON_stop();
		if(BUTTON_pressed(BUTTON_FORWARD))
		{
		MOTOR_ON(MOTOR_A,LEFT);
		MOTOR_ON(MOTOR_B,LEFT);
		}
		else if(BUTTON_pressed(BUTTON_RIGHT))
		{
		LED_on(LED_NO_0);
		MOTOR_ON(MOTOR_A,LEFT);
		MOTOR_ON(MOTOR_B,RIGHT);
		
		}
		else if(BUTTON_pressed(BUTTON_LEFT))
		{
		LED_on(LED_NO_1);
		MOTOR_ON(MOTOR_A,RIGHT);
		MOTOR_ON(MOTOR_B,LEFT);
		
		}
		else
		{
		MOTOR_ON(MOTOR_A,RIGHT);
		MOTOR_ON(MOTOR_B,RIGHT);
		}
		}
		else
		{
		LED_on(LED_NO_2);
		enable = BUTTON_stop();
		MOTOR_OFF();
		}*/
		
	}
}

