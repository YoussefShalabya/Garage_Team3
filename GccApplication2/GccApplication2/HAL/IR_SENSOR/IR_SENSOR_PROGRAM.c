/*
 * IR_SENSOR_PROGRAM.c
 *
 * Created: 7/8/2024 7:14:10 PM
 *  Author: Right Click
 */ 
#include "IR_SENSOR_INTERFACE.h"

void ir_sensor_intialize()
{
	pinMode(IR_OUTPUT,INPUT);
	pinMode(IR_OUTPUT_1,INPUT);
}
uint8 get_ir_value(uint8 IR)
{
	uint8 ret_value = 0;
	ret_value = digitalRead(IR);
	return(ret_value);
}