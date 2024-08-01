/*
 * SERVO_INTERFACE.h
 *
 * Created: 4/22/2024 10:36:38 PM
 *  Author: Right Click
 */ 


#ifndef SERVO_INTERFACE_H_
#define SERVO_INTERFACE_H_
#include "../../MCAL/DIO_INTERFACE.h"
#define motor_1 10
#define motor_2 11
#define ON_SERVO_MOTOR  1
#define OFF_SERVO_MOTOR 0
void servo_motor_init(void);
void servo_motor_degree(uint8 motor_pin,uint8 mode);
#endif /* SERVO_INTERFACE_H_ */