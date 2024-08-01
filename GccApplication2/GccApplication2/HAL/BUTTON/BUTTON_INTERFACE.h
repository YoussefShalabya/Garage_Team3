/*
 * BUTTON_INTERFACE.h
 *
 * Created: 2/28/2024 8:11:46 PM
 *  Author: Right Click
 */ 


#ifndef BUTTON_INTERFACE_H_
#define BUTTON_INTERFACE_H_
#include "../../MCAL/DIO_INTERFACE.h"

#define BUTTON_RESET  PC0
#define WATER_EMERGANCY PC1
#define BUTTON_OPEN    PC2
void BUTTON_init();
uint8 BUTTON_pressed(uint8 BUTTON_Choice);



#endif /* BUTTON_INTERFACE_H_ */