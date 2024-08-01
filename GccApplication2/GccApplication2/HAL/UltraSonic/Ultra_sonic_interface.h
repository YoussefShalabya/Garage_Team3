/*
 * Ultra_sonic_interface.h
 *
 * Created: 7/11/2024 9:11:57 PM
 *  Author: Right Click
 */ 


#ifndef ULTRA_SONIC_INTERFACE_H_
#define ULTRA_SONIC_INTERFACE_H_
#include "../../MCAL/DIO_INTERFACE.h"
#define ECHO_PIN PC0
#define TRIG_PIN PC1

void Ultra_Sonic_Init(void);
uint8 Ultra_sonic_read_distance(void);


#endif /* ULTRA_SONIC_INTERFACE_H_ */