/*
 * DC_MOTOR_INTERFACE.h
 *
 * Created: 2/28/2024 4:02:15 PM
 *  Author: Right Click
 */ 

#include "../../LIB/STD_TYPES.h"
#include "../../MCAL/DIO_INTERFACE.h"
#ifndef DC_MOTOR_INTERFACE_H_
#define DC_MOTOR_INTERFACE_H_
#define MOTOR_A 1
#define MOTOR_B 0
//===============================
#define MOTOR_PIN_A PA0
#define MOTOR_PIN_A_1 PA1
#define MOTOR_PIN_B PA2
#define MOTOR_PIN_B_1 PA3
//===============================
#define LEFT 1
#define RIGHT 0
void MOTOR_init();
void MOTOR_ON(uint8 MOTOR,uint8 direction);
void MOTOR_OFF();



#endif /* DC_MOTOR_INTERFACE_H_ */