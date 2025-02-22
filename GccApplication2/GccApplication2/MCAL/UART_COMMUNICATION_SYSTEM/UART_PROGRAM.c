/*
 * UART_PROGRAM.c
 *
 * Created: 7/8/2024 8:38:05 PM
 *  Author: Right Click
 */ 
#include "UART_INTERFACE.h"

void UART_Init(unsigned int ubrr) {
	
	// Set baud rate
	UBRRH = (unsigned char)(ubrr >> 8);
	UBRRL = (unsigned char)ubrr;
	// Enable receiver and transmitter
	UCSRB = (1 << RXEN) | (1 << TXEN);
	// Set frame format: 8 data bits, 1 stop bit
	UCSRC = (1 << URSEL) | (1 << UCSZ1) | (1 << UCSZ0);
}

void UART_Transmit(unsigned char data) {
	// Wait for empty transmit buffer
	while (!(UCSRA & (1 << UDRE)));
	// Put data into buffer, sends the data
	UDR = data;
}

unsigned char UART_Receive(void) {
	// Wait for data to be received
	while (!(UCSRA & (1 << RXC)));
	// Get and return received data from buffer
	return (UDR);
}

void UART_TransmitString(const char* str) {
	while (*str) {
		UART_Transmit(*str++);
	}
}