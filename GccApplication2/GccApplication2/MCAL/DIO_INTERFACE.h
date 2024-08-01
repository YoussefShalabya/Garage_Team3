/*
 * IncFile1.h
 *
 * Created: 2/13/2024 1:09:00 PM
 *  Author: hamdy ayman
 */ 

#ifndef DIO_INTERFACE_H_
#define DIO_INTERFACE_H_
#include <util\delay.h>
#include "..\LIB\STD_TYPES.h"
#include "../LIB/BIT_MATH.h"
#include "REG.h"
#define A 0
#define B 1
#define C 2
#define D 3

#define PA0 0
#define PA1 1
#define PA2 2
#define PA3 3
#define PA4 4
#define PA5 5
#define PA6 6
#define PA7 7

#define PB0 10
#define PB1 11
#define PB2 12
#define PB3 13
#define PB4 14
#define PB5 15
#define PB6 16
#define PB7 17

#define PC0 20
#define PC1 21
#define PC2 22
#define PC3 23
#define PC4 24
#define PC5 25
#define PC6 26
#define PC7 27

#define PD0 30
#define PD1 31
#define PD2 32
#define PD3 33
#define PD4 34
#define PD5 35
#define PD6 36
#define PD7 37

#define OUTPUT 1
#define INPUT 0
#define HIGH 1
#define LOW 0




void pinMode(uint8 pin_num ,uint8 DIR);
void digitalWrite(uint8 pin_num ,uint8 STATE);
uint8 digitalRead(uint8 pin_num);

#endif /* DIO_INTERFACE_H_ */