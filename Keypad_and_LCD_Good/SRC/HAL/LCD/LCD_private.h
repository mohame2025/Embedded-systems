/*
 * LCD_private.h
 *
 *  Created on: Oct 11, 2025
 *      Author: MohamedMahrous
 */

#ifndef _LCD_PRIVATE_H_
#define _LCD_PRIVATE_H_

#include "DELAY.h"

//inline
void send_cmd(const uint8_t instruction)
{
	/* step 1 */
	DIO_write_pin_value(LCD_PORT, RS_PIN, LOGIC_LOW);
	_delay_us(1);
	DIO_toggle_pin_value(LCD_PORT, E_PIN);
	_delay_us(1);
	DIO_write_pin_value(LCD_PORT, D7_PIN, (instruction >> 7) & 1);
	DIO_write_pin_value(LCD_PORT, D6_PIN, (instruction >> 6) & 1);
	DIO_write_pin_value(LCD_PORT, D5_PIN, (instruction >> 5) & 1);
	DIO_write_pin_value(LCD_PORT, D4_PIN, (instruction >> 4) & 1);
	_delay_us(1);
	DIO_toggle_pin_value(LCD_PORT, E_PIN);

	/* step 2 */
	_delay_us(10);
	DIO_toggle_pin_value(LCD_PORT, E_PIN);
	_delay_us(1);
	DIO_write_pin_value(LCD_PORT, D7_PIN, (instruction >> 3) & 1);
	DIO_write_pin_value(LCD_PORT, D6_PIN, (instruction >> 2) & 1);
	DIO_write_pin_value(LCD_PORT, D5_PIN, (instruction >> 1) & 1);
	DIO_write_pin_value(LCD_PORT, D4_PIN, (instruction >> 0) & 1);
	_delay_us(1);
	DIO_toggle_pin_value(LCD_PORT, E_PIN);
}

//inline
void send_data(const uint8_t data)
{
	/* step 1 */
	DIO_write_pin_value(LCD_PORT, RS_PIN, LOGIC_HIGH);
	_delay_us(1);
	DIO_toggle_pin_value(LCD_PORT, E_PIN);
	_delay_us(1);
	DIO_write_pin_value(LCD_PORT, D7_PIN, (data >> 7) & 1);
	DIO_write_pin_value(LCD_PORT, D6_PIN, (data >> 6) & 1);
	DIO_write_pin_value(LCD_PORT, D5_PIN, (data >> 5) & 1);
	DIO_write_pin_value(LCD_PORT, D4_PIN, (data >> 4) & 1);
	_delay_us(1);
	DIO_toggle_pin_value(LCD_PORT, E_PIN);

	/* step 2 */
	_delay_us(10);
	DIO_toggle_pin_value(LCD_PORT, E_PIN);
	_delay_us(1);
	DIO_write_pin_value(LCD_PORT, D7_PIN, (data >> 3) & 1);
	DIO_write_pin_value(LCD_PORT, D6_PIN, (data >> 2) & 1);
	DIO_write_pin_value(LCD_PORT, D5_PIN, (data >> 1) & 1);
	DIO_write_pin_value(LCD_PORT, D4_PIN, (data >> 0) & 1);
	_delay_us(1);
	DIO_toggle_pin_value(LCD_PORT, E_PIN);
}

#define FS(DL, N, F)			(0x20 | (DL << 4) | (N << 3) | (F << 2))
#define DISP_ON_OFF(D, C, B)	(0x08 | (D << 2) | (C << 1) | (B << 0))
#define ENTRY_MODE(I_D, SH)		(0x04 | (I_D << 1) | (SH << 0))

#endif /* _LCD_PRIVATE_H_ */
