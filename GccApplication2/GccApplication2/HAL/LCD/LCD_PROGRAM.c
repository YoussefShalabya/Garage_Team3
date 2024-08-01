/*
 * LCD_PROGRAM.h
 *
 * Created: 2/29/2024 9:56:37 PM
 *  Author: Right Click
 */ 

#include "LCD_INTERFACE.h"
#include <avr/delay.h>


//===========HELPER FUNCTION==============//
static void lcd_8bit_send_enable_signal();
static void lcd_4bit_send_enable_signal();
//=======================================//
void LCD_init_8bit()
{
		_delay_ms(20);
		LCD_DATA_DDR = 0xFF;
		pinMode(register_select,OUTPUT);
		pinMode(enable,OUTPUT);
		LCD_SEND_COMMAND_8BIT(LCD_MODE_8BIT);
		LCD_SEND_COMMAND_8BIT(0x0C);
		_delay_ms(1);
		LCD_SEND_COMMAND_8BIT(0x06);
		_delay_ms(1);
		LCD_SEND_COMMAND_8BIT(0x01);
		_delay_ms(20);
}
void LCD_init_4bit()
{
	_delay_ms(50);
	pinMode(register_select,OUTPUT);
	pinMode(enable,OUTPUT);
	LCD_DATA_DDR = 0xFF;
	LCD_SEND_COMMAND_4BIT(0x02);
	_delay_ms(1);
	LCD_SEND_COMMAND_4BIT(LCD_MODE_4BIT);
	_delay_ms(1);
	LCD_SEND_COMMAND_4BIT(0X0C);
	_delay_ms(1);
	LCD_SEND_COMMAND_4BIT(0x01);
	_delay_ms(1);
	LCD_SEND_COMMAND_4BIT(0x06);
	_delay_ms(1);
}
void LCD_SEND_COMMAND_8BIT(uint8 COMMAND)
{
		digitalWrite(register_select,LOW);
		LCD_DATA_PORT = COMMAND;
		lcd_8bit_send_enable_signal();
	
}
void LCD_SEND_COMMAND_4BIT(uint8 COMMAND)
{
	digitalWrite(register_select,LOW);
	LCD_DATA_PORT = (COMMAND & 0xF0);
	lcd_4bit_send_enable_signal();
	LCD_DATA_PORT = ((COMMAND & 0x0F) << 4);
	lcd_4bit_send_enable_signal();
}
void LCD_SEND_DATA(uint8 Data,uint8 mode)
{
	switch(mode)
	{
		case (MODE_8BIT):
		digitalWrite(register_select,HIGH);
		LCD_DATA_PORT = Data;
		lcd_8bit_send_enable_signal();
		break;
		case (MODE_4BIT):
		digitalWrite(register_select,HIGH);
		LCD_DATA_PORT = (Data & 0xF0);
		lcd_4bit_send_enable_signal();
		LCD_DATA_PORT = ((Data & 0x0F) << 4);
		lcd_4bit_send_enable_signal();
		break;
	}
	
}
void LCD_SEND_DATA_STRING(uint8 *STRING_DATA,uint8 mode)
{
	while(*STRING_DATA)            
	{
		LCD_SEND_DATA(*STRING_DATA++,mode);
	}
}
void LCD_SEND_DATA_INT(uint8 INTEGAR_DATA,uint8 mode) 
{
	LCD_DATA_PORT = INTEGAR_DATA | 0x30;
	LCD_SEND_DATA(LCD_DATA_PORT,mode);
}
void LCD_CLEAR_8BIT()
{
	LCD_SEND_COMMAND_8BIT(LCD_CLEAR_DATA);
}
void LCD_CLEAR_4BIT()
{
	LCD_SEND_COMMAND_4BIT(LCD_CLEAR_DATA);
}

void LCD_set_cursor_8bit(uint8 line, uint8 col)
{
	if(col <= 16)
	{
		col--;
		switch(line)
		{
			case line_1 :
			LCD_SEND_COMMAND_8BIT(0x80 + col);
			break;
			case line_2 :
			LCD_SEND_COMMAND_8BIT(0xc0 + col);
			break;
		}
	}
	else{}
}

void LCD_set_cursor_4bit(uint8 line, uint8 col)
{
	if(col <= 16)
	{
		col--;
		switch(line)
		{
			case line_1 :
			LCD_SEND_COMMAND_4BIT(0x80 + col);
			break;
			case line_2 :
			LCD_SEND_COMMAND_4BIT(0xc0 + col);
			break;
		}
	}
	else{}
}
void lcd_8bit_send_char_data_pos(uint8 row,uint8 col,uint8 data)
{
	LCD_set_cursor_8bit(row ,col);
	LCD_SEND_DATA(data,MODE_8BIT);
}
void lcd_8bit_send_custom_char(uint8 row,uint8 col,
const uint8 _char[],uint8 mem_pos){
	uint8 lcd_counter = 0;
	
	
		LCD_SEND_COMMAND_8BIT((_LCD_CGRAM_START+(mem_pos*8)));
		for(lcd_counter = 0; lcd_counter < 8;lcd_counter++)
		{
			LCD_SEND_DATA(_char[lcd_counter],MODE_8BIT);
		}
		lcd_8bit_send_char_data_pos(row,col,mem_pos);
	
}
//=====================================Helper function=================================================
static void lcd_8bit_send_enable_signal()
{
	digitalWrite(enable,HIGH);
	_delay_ms(10);
	digitalWrite(enable,LOW);
	_delay_ms(10);
}

static void lcd_4bit_send_enable_signal()
{
	digitalWrite(enable,HIGH);
	_delay_ms(10);
	digitalWrite(enable,LOW);
	_delay_ms(10);
}