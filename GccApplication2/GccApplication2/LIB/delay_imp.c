/*
 * delay_imp.c
 *
 * Created: 7/16/2024 7:17:28 PM
 *  Author: DELL
 */ 
#define F_CPU 8000000UL

#include <util/delay.h>

void delay_Imp(double us){
	while(us >= 1000){
		_delay_us(1000);
		us -= 1000;
	}
	
	while(us >= 100){
		_delay_us(100);
		us -= 100;
	}
	while(us >= 10){
		_delay_us(10);
		us -= 10;
	}
	while(us > 0){
		_delay_us(1);
		us -= 1;
	}
}