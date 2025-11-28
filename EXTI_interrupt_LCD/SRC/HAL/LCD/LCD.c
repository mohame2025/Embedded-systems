/*
 * LCD.c
 *
 *  Created on: Oct 11, 2025
 *      Author: OmarAbdulqadir
 */
#include "LCD.h"
#include "LCD_config.h"
#include "LCD_private.h"
//#include "KEYPAD_interface.h"
#include <stdlib.h>
//#include <avr/dtostrf.h>


/* Initialization function */
void LCD_init(void)
{
	/* Set pins direction */
	DIO_set_port_direction(PORTA_ID,
						(PIN_OUTPUT << RS_PIN) |
						(PIN_OUTPUT << E_PIN)  |
						(PIN_OUTPUT << D4_PIN) |
						(PIN_OUTPUT << D5_PIN) |
						(PIN_OUTPUT << D6_PIN) |
						(PIN_OUTPUT << D7_PIN) );

_delay_ms(50);

	/* Function set */
	send_cmd(FS(DL, N, F));
	_delay_us(50);

	/* Display on */
	send_cmd(DISP_ON_OFF(D, C, B));
	_delay_us(50);

	/* Display Clear */
	send_cmd(0x01);
	_delay_ms(2);

	/* Entry mode */
	send_cmd(ENTRY_MODE(I_D, SH));
	_delay_us(50);


//	LCD_set_cursor(0, 0);
	//		LCD_write_str((uint8_t*) "key :");




  }

/* Control */
void LCD_disp_on(void)
{
	send_cmd(DISP_ON_OFF(1, C, B));
	_delay_us(50);
}

void LCD_disp_off(void)
{
	send_cmd(DISP_ON_OFF(0, C, B));
	_delay_us(50);
}

void LCD_clear(void)
{
	send_cmd(0x01);
	_delay_ms(2);
}

void LCD_return_home(void)
{
	send_cmd(0x02);
	_delay_ms(2);
}

void LCD_set_cursor(uint8_t row, uint8_t col)
{
	uint8_t address = 0x80 + (row*0x40) + col;
	send_cmd(address);
	_delay_us(50);
}

/* Data */
void LCD_write_char(const uint8_t chr)
{
	send_data(chr);
	_delay_us(50);
}

void LCD_write_str(const uint8_t* str)
{
	while(*str != '\0')
	{
		send_data(*str++);
		_delay_us(50);
	}
}

void LCD_write_number(const uint32_t number)
{
	char buffer[11]; // يكفي 10 أرقام + '\0'
	itoa(number, buffer, 10); // تحويل الرقم لنص
	    LCD_write_str((uint8_t*)buffer);

}

void LCD_write_float(const float64_t number)
{
	  char buffer[16];
	    //dtostrf

	  dtostrf(number, 6, 2, buffer); // عرض 6 خانات، 2 عشري
	    LCD_write_str((uint8_t*)buffer);
}

/* Custom characters */
void LCD_create_custom_char(uint8_t id, uint8_t* chr)
{
	   id &= 0x07; // فقط 8 رموز ممكنة
	    send_cmd(0x40 + (id * 8)); // عنوان CGRAM
	    for (uint8_t i = 0; i < 8; i++)
	    {
	        send_data(chr[i]);
	    }
}
