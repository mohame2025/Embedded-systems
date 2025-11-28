/*
 * LCD.c
 *
 *  Created on: Oct 11, 2025
 *      Author: moham
 */


/* LCD.c
 *
 *  Created on: Oct 11, 2025
 *      Author: moham
 */

#include "LCD.h"
#include "LCD_config.h"
#include "LCD_private.h"
#include "DELAY.h"
#include <stdlib.h>

void LCD_init(void)
{
    // ضبط اتجاه الأرجل على أنها مخرجات
    DIO_set_port_direction(LCD_PORT,
        (1 << RS_PIN) |
        (1 << E_PIN)  |
        (1 << D4_PIN) |
        (1 << D5_PIN) |
        (1 << D6_PIN) |
        (1 << D7_PIN));

    _delay_ms(50);

    // تهيئة الشاشة في وضع 4 بت
    send_cmd(0x33); // تهيئة أولية
    send_cmd(0x32); // وضع 4 بت
    send_cmd(0x28); // 2 خط + 5x8 dots
    send_cmd(0x0C); // تشغيل العرض بدون المؤشر
    send_cmd(0x01); // مسح الشاشة
    _delay_ms(2);
    send_cmd(0x06); // التحرك لليمين بعد كل حرف
}

void LCD_disp_on(void)
{
    send_cmd(0x0C); // تشغيل العرض
}

void LCD_disp_off(void)
{
    send_cmd(0x08); // إيقاف العرض
}

void LCD_clear(void)
{
    send_cmd(0x01); // مسح الشاشة
    _delay_ms(2);
}

void LCD_return_home(void)
{
    send_cmd(0x02); // العودة للموقع 0,0
    _delay_ms(2);
}

void LCD_set_cursor(uint8_t row, uint8_t col)
{
    uint8_t address;
    switch (row)
    {
        case 0: address = 0x80 + col; break;
        case 1: address = 0xC0 + col; break;
        case 2: address = 0x94 + col; break;
        case 3: address = 0xD4 + col; break;
        default: address = 0x80; break;
    }
    send_cmd(address);
    _delay_us(50);
}

void LCD_write_char(uint8_t chr)
{
    send_data(chr);
    _delay_us(50);
}

void LCD_write_str(uint8_t *str)
{
    while (*str != '\0')   // ← كانت غلط '/o'
    {
        send_data(*str++);
        _delay_us(50);
    }
}

void LCD_write_number(uint32_t num)
{
    char buffer[11]; // يكفي 10 أرقام + '\0'
    itoa(num, buffer, 10); // تحويل الرقم لنص
    LCD_write_str((uint8_t*)buffer);
}

void LCD_write_float(float number)
{
    char buffer[16];
    dtostrf(number, 6, 2, buffer); // عرض 6 خانات، 2 عشري
    LCD_write_str((uint8_t*)buffer);
}

void LCD_create_custom_char(uint8_t id, uint8_t *pattern)
{
    id &= 0x07; // فقط 8 رموز ممكنة
    send_cmd(0x40 + (id * 8)); // عنوان CGRAM
    for (uint8_t i = 0; i < 8; i++)
    {
        send_data(pattern[i]);
    }
}
