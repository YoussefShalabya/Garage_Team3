/*
 * LCD_INTERFACE.h
 *
 * Created: 2/29/2024 9:56:23 PM
 *  Author: Right Click
 */ 


#ifndef LCD_INTERFACE_H_
#define LCD_INTERFACE_H_

#include "../../MCAL/DIO_INTERFACE.h"

#define _LCD_CLEAR                  0x01
#define _LCD_RETURN_HOME            0x02
#define _LCD_ENTRY_MODE             0x06
#define _LCD_CURSOR_OFF_DISPLAY_ON  0x0C
#define _LCD_CURSOR_OFF_DISPLAY_OFF 0x08
#define _LCD_CURSOR_ON_BLINK_ON     0x0F
#define _LCD_CURSOR_ON_BLINK_OFF    0x0E
#define _LCD_DISPLAY_SHIFT_RIGHT    0x1C
#define _LCD_DISPLAY_SHIFT_LEFT     0x1C
#define _LCD_8BIT_MODE_2_LINE       0x38
#define _LCD_4BIT_MODE_2_LINE       0x28
#define _LCD_CGRAM_START            0x40
#define _LCD_DDRAM_START            0x80
#define LCD_DATA_DDR DDRA
#define LCD_DATA_PORT PORTA
#define register_select PB2
#define enable          PB3
#define LCD_MODE_4BIT 0x28
#define LCD_MODE_8BIT 0x38
#define LCD_CLEAR_DATA 0X01
#define MODE_4BIT 1
#define MODE_8BIT 0
#define line_1 1
#define line_2 2
void LCD_init_8bit();
void LCD_init_4bit();
void LCD_SEND_COMMAND_8BIT(uint8 COMMAND);
void LCD_SEND_COMMAND_4BIT(uint8 COMMAND);
void LCD_SEND_DATA(uint8 Data,uint8 mode);
void LCD_SEND_DATA_STRING(uint8 *STRING_DATA,uint8 mode);
void LCD_SEND_DATA_INT(uint8 INTEGAR_DATA,uint8 mode);
void LCD_set_cursor_8bit(uint8 line, uint8 col);
void LCD_set_cursor_4bit(uint8 line, uint8 col);
void lcd_8bit_send_char_data_pos(uint8 row,uint8 col,uint8 data);
void lcd_8bit_send_custom_char(uint8 row,uint8 col,
const uint8 _char[],uint8 mem_pos);
void LCD_CLEAR_8BIT();
void LCD_CLEAR_4BIT();

#endif /* LCD_INTERFACE_H_ */