/*
 * IR_SENSOR_INTERFACE.h
 *
 * Created: 7/8/2024 7:14:33 PM
 *  Author: Right Click
 */ 


#ifndef IR_SENSOR_INTERFACE_H_
#define IR_SENSOR_INTERFACE_H_
#include "../../MCAL/DIO_INTERFACE.h"

#define IR_OUTPUT   15
#define IR_OUTPUT_1 16

void ir_sensor_intialize();
uint8 get_ir_value(uint8 IR);
#endif /* IR_SENSOR_INTERFACE_H_ */