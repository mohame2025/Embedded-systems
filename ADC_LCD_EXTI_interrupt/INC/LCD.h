/*
 * LCD.h
 *
 *  Created on: Oct 11, 2025
 *      Author: Mohamed
 */

#ifndef _LCD_H_
#define _LCD_H_

#include "STD_TYPES.h"
#include "DELAY.h"
#include "DIO.h"

/* Initialization function */
void LCD_init(void);

/* Control */
void LCD_disp_on(void);
void LCD_disp_off(void);
void LCD_clear(void);
void LCD_return_home(void);
void LCD_set_cursor(uint8_t row, uint8_t col);

/* Data */
void LCD_write_char(const uint8_t chr);
void LCD_write_str(const uint8_t* str);
void LCD_write_number(const uint32_t number);
void LCD_write_float(const float64_t nubmer);

/* Custom characters */
void LCD_create_custom_char(uint8_t id, uint8_t* chr);

#endif /* _LCD_H_ */
