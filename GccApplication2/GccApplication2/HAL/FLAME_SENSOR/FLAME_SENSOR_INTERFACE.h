/*
 * FLAME_SENSOR_INTERFACE.h
 *
 * Created: 7/8/2024 8:16:36 PM
 *  Author: Right Click
 */ 


#ifndef FLAME_SENSOR_INTERFACE_H_
#define FLAME_SENSOR_INTERFACE_H_

#include "../../MCAL/DIO_INTERFACE.h"

#define FLAME_OUPTUT PB4

void flame_sensor_intialize();
uint8 get_flame_value();


#endif /* FLAME_SENSOR_INTERFACE_H_ */