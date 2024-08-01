/*
 * UART_INTERFACE.h
 *
 * Created: 7/8/2024 8:37:43 PM
 *  Author: Right Click
 */ 
#ifndef UART_H
#define UART_H

#include "../DIO_INTERFACE.h"

#define BAUD 9600
#define MYUBRR F_CPU/16/BAUD-1
#include <avr/io.h>
void UART_Init(unsigned int ubrr);
void UART_Transmit(unsigned char data);
unsigned char UART_Receive(void);
void UART_TransmitString(const char* str);

#endif