/*
 * SEVENSEG_program.c
 *
 *  Created on: Oct 24, 2025
 *      Author: moham
 */
#include <SEVENSEG_interface.h>
#include "DIO.h"
#include "DELAY.h"





// شكل الأرقام من 0 إلى 9 (لـ common cathode)
uint8_t Seg_7[] = {
    0b01111110,  // 0
    0b00001100,  // 1
    0b10110110,  // 2
    0b10011110,  // 3
    0b11000110,  // 4
    0b11011010,  // 5
    0b11111010,  // 6
    0b00001110,  // 7
    0b11111110,  // 8
    0b11011110   // 9
};

void SEVENSEG_Init(uint8_t port, uint8_t enablePort, uint8_t enablePin1, uint8_t enablePin2)
{
    DIO_set_port_direction(port, 0xFF); // كل أطراف الـ data OUT
    DIO_set_pin_direction(enablePort, enablePin1, PIN_OUTPUT); // رجل الشاشة الأولى
    DIO_set_pin_direction(enablePort, enablePin2, PIN_OUTPUT); // رجل الشاشة الثانية
}

void SEVENSEG_DisplayNumber(uint8_t port, uint8_t enablePort, uint8_t enablePin1, uint8_t enablePin2, uint8_t number)
{
    uint8_t tens = number / 10;  // رقم العشرات
    uint8_t ones = number % 10;  // رقم الآحاد

    for(uint8_t i = 0; i < 50; i++) // تكرار سريع علشان التبديل ما يبينش
    {
        // عرض رقم الآحاد
        DIO_write_pin_value(enablePort, enablePin1, LOGIC_HIGH);
        DIO_write_pin_value(enablePort, enablePin2, LOGIC_LOW);
        DIO_write_port_value(port, Seg_7[ones]);
        _delay_ms(5);

        // عرض رقم العشرات
        DIO_write_pin_value(enablePort, enablePin1, LOGIC_LOW);
        DIO_write_pin_value(enablePort, enablePin2, LOGIC_HIGH);
        DIO_write_port_value(port, Seg_7[tens]);
        _delay_ms(5);
    }

}
