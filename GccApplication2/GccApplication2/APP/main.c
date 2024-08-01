/*
 * Author: Team 3
 * subject: smart system Garage
 * Created: 2/13/2024 12:32:41 PM
 * Author : hamdy ayman
 */ 
#include "main.h"
#define ENTRY_DOOR_QR 0
#define FLAME_EMERGANCY 0x32
#define Threshold_distance 20
void application_initialize(void);

int main(void)
{
	application_initialize();
	uint8 customChar[] = {
		0x0E,
		0x0E,
		0x0E,
		0x0E,
		0x0E,
		0x00,
		0x0E,
		0x00
	};
	uint8 customChar_1[] = {
		0x04,
		0x0E,
		0x1F,
		0x0E,
		0x0E,
		0x0E,
		0x0E,
		0x0E
	};
	
	uint8 customChar_2[] = {
		0x0E,
		0x0E,
		0x0E,
		0x0E,
		0x0E,
		0x1F,
		0x0E,
		0x04
	};
	uint8 full_cap_key = 0;
	uint8 index_buzzer = 0;
	uint8 lcd_cars_present = 0;
	uint8 lcd_cars_capacity = 9;
	volatile uint8 v_digital_ir = 0;
	volatile uint8 v_digital_ir_1 = 0;
	volatile uint8 v_digital_flame = 0;	
	LCD_set_cursor_8bit(1,1);
	LCD_SEND_DATA_STRING((uint8*)"capacity = ",MODE_8BIT);
	LCD_set_cursor_8bit(2,1);
	LCD_SEND_DATA_STRING((uint8*)"car inside = ",MODE_8BIT);
    while (1) 
    {	
		//check_value_btn_res = BUTTON_pressed(BUTTON_RESET);
		_delay_ms(10);
		v_digital_flame = get_flame_value();
		v_digital_ir    = get_ir_value(IR_OUTPUT);
		v_digital_ir_1  = get_ir_value(IR_OUTPUT_1);
		_delay_ms(10);
		
		
		//========================== LCD ====================================
		LCD_set_cursor_8bit(1,11);
		LCD_SEND_DATA_INT(lcd_cars_capacity,MODE_8BIT);
		LCD_set_cursor_8bit(2,13);
		LCD_SEND_DATA_INT(lcd_cars_present,MODE_8BIT);
		_delay_ms(100);
		//===================================================================
		//========================== IR SENSOR ==============================
		if ( v_digital_ir == LOW )
		{
			if(0 != lcd_cars_present)
			{
				lcd_cars_present--;
				lcd_8bit_send_custom_char(2,16,customChar_2,0);
				_delay_ms(3000);
				
			}
			else
			{
				LCD_CLEAR_8BIT();
				LCD_SEND_DATA_STRING((uint8*)"NO CAR INSIDE ",MODE_8BIT);
				LCD_set_cursor_8bit(2,1);
				LCD_SEND_DATA_STRING((uint8*)"THE GARGAE",MODE_8BIT);
				_delay_ms(1500);
				LCD_CLEAR_8BIT();
				LCD_set_cursor_8bit(1,1);
				LCD_SEND_DATA_STRING((uint8*)"capacity = ",MODE_8BIT);
				LCD_set_cursor_8bit(2,1);
				LCD_SEND_DATA_STRING((uint8*)"car inside = ",MODE_8BIT);
				
			}
			
			
		}
		else
		{
			
		}
		//=================================================================
		
		//========================== Flame sensor==============================
		if(v_digital_flame == LOW)
		{
			LCD_CLEAR_8BIT();
			LCD_SEND_DATA_STRING((uint8*)" Alert",MODE_8BIT);
			lcd_8bit_send_custom_char(2,16,customChar,0);
			_delay_ms(1500);
			for(index_buzzer = 0;index_buzzer<10;index_buzzer++)
			{
				BUZZER_on();
				_delay_ms(50);
				BUZZER_off();
			}
			_delay_ms(100);
			LCD_CLEAR_8BIT();
			LCD_set_cursor_8bit(1,1);
			LCD_SEND_DATA_STRING((uint8*)"capacity = ",MODE_8BIT);
			LCD_set_cursor_8bit(2,1);
			LCD_SEND_DATA_STRING((uint8*)"car inside = ",MODE_8BIT);
		}
		else
		{
			
		}
		//============================================================================
		//========================== UART  COMMUNICATION==============================
		
		if((ENTRY_DOOR_QR == v_digital_ir_1))
		{
			servo_motor_degree(motor_1,ON_SERVO_MOTOR);
			_delay_ms(5000);
			servo_motor_degree(motor_1,OFF_SERVO_MOTOR);
			_delay_ms(5000);
			if(lcd_cars_present != lcd_cars_capacity)
			{
				lcd_cars_present++;
				lcd_8bit_send_custom_char(2,16,customChar_1,1);

			}
			else
			{
				LCD_CLEAR_8BIT();
				while(lcd_cars_present== 9 && v_digital_ir !=0)
				{
					v_digital_ir = get_ir_value(IR_OUTPUT);
					if(full_cap_key != 1)
					{
						full_cap_key = 1;
						LCD_SEND_DATA_STRING((uint8*)"GARAGE IS FULL",MODE_8BIT);
					}
					
				}
				full_cap_key = 0;
				LCD_CLEAR_8BIT();
				LCD_set_cursor_8bit(1,1);
				LCD_SEND_DATA_STRING((uint8*)"capacity = ",MODE_8BIT);
				LCD_set_cursor_8bit(2,1);
				LCD_SEND_DATA_STRING((uint8*)"car inside = ",MODE_8BIT);
			}
		}
		
		//=================================================================
		
		
		
	}
		
}

void application_initialize(void)
{
	LCD_init_8bit();
	servo_motor_init();
	flame_sensor_intialize();
	ir_sensor_intialize();
	BUZZER_init();
	Ultra_Sonic_Init();
}
