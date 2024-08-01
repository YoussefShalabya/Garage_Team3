#ifndef REG_H_
#define REG_H_
/****************REG_A*********************/
#define PORTA (*((volatile char*) 0x3B))
#define DDRA  (*((volatile char*) 0x3A))
#define PINA  (*((volatile char*) 0x39))
/****************REG_B*********************/
#define PORTB (*((volatile char*) 0x38))
#define DDRB  (*((volatile char*) 0x37))
#define PINB  (*((volatile char*) 0x36))
/****************REG_C*********************/
#define PORTC (*((volatile char*) 0x35))
#define DDRC  (*((volatile char*) 0x34))
#define PINC  (*((volatile char*) 0x33))
/****************REG_D*********************/
#define PORTD (*((volatile char*) 0x32))
#define DDRD  (*((volatile char*) 0x31))
#define PIND  (*((volatile char*) 0x30))
/*************************************/
#endif /* REG_H_ */