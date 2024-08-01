/*
 * FLAME_SENSOR_PROGRAM.c
 *
 * Created: 7/8/2024 8:16:10 PM
 *  Author: Right Click
 */ 
#include "FLAME_SENSOR_INTERFACE.h"
void flame_sensor_intialize()
{
	pinMode(FLAME_OUPTUT,INPUT);
}
uint8 get_flame_value()
{
	uint8 ret_value = 0;
	ret_value = digitalRead(FLAME_OUPTUT);
	return(ret_value);
}