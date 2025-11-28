/*
 * LCD.h
 *
 *  Created on: Oct 11, 2025
 *      Author: Mohamed
 */

#ifndef LCD_H_
#define LCD_H_

#include "STD_TYPES.h"
#include "DIO.h"
#include "DELAY.h"

/* ====== أوامر التحكم ====== */
void LCD_init(void);
void LCD_disp_on(void);
void LCD_disp_off(void);
void LCD_clear(void);
void LCD_return_home(void);
void LCD_set_cursor(uint8_t row, uint8_t col);

/* ====== الكتابة على الشاشة ====== */
void LCD_write_char(uint8_t chr);
void LCD_write_str(uint8_t *str);
void LCD_write_number(uint32_t num);
void LCD_write_float(float number);

/* ====== إنشاء رموز مخصصة ====== */
void LCD_create_custom_char(uint8_t id, uint8_t *pattern);

#endif /* LCD_H_ */
