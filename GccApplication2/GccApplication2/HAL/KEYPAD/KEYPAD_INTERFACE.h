/*
 * KEYPAD_INTERFACE.h
 *
 * Created: 3/18/2024 9:14:21 PM
 *  Author: Right Click
 */ 


#ifndef KEYPAD_INTERFACE_H_
#define KEYPAD_INTERFACE_H_
#include "../../MCAL/DIO_INTERFACE.h"

#define NOT_PRESSED 0xff
#define KPD_ROW_INIT PD0
#define KPD_ROW_END PD3
#define KPD_COL_INIT PD4
#define KPD_COL_END PD7

#define ROWS 4
#define COLS 4
#define KPD_R0 PD0
#define KPD_R1 PD1
#define KPD_R2 PD2
#define KPD_R3 PD3

#define KPD_C0 PD4
#define KPD_C1 PD5
#define KPD_C2 PD6
#define KPD_C3 PD7

void KEYPAD_init();
uint8 KEYPAD_scan();


#endif /* KEYPAD_INTERFACE_H_ */