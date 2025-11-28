/*
 * KEYPAD_program.c
 *
 *  Created on: Nov 7, 2025
 *      Author: Mohamed
 */

#include "DIO.h"
#include "DELAY.h"
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "KEYPAD_interface.h"
#include "KEYPAD_config.h"
#include "KEYPAD_private.h"

#define ROWS 4
#define COLS 4

/* خريطة المفاتيح */
static const uint8_t Local_u8Keys[4][4]={
		{'7','8','9','/'},
        {'4','5','6','*'},
        {'1','2','3','-'},
        {'c','0','=','+'}};

uint8_t Keypad_u8GetPressedKey(void)
{
    uint8_t row, col, pinValue, key = NOT_PRESSED;

    /* تعريف الأعمدة والصفوف */
    uint8_t rowPins[ROWS] = {KEYPAD_ROW0_PIN , KEYPAD_ROW1_PIN, KEYPAD_ROW2_PIN, KEYPAD_ROW3_PIN};
    uint8_t colPins[COLS] = {KEYPAD_COL0_PIN, KEYPAD_COL1_PIN, KEYPAD_COL2_PIN, KEYPAD_COL3_PIN};



    /* إعداد الأعمدة كمخرجات (OUTPUT) */
    for (col = 0; col < COLS; col++)
    {
        DIO_set_pin_direction(KEYPAD_PORT_COL , colPins[col], PIN_OUTPUT);
        DIO_write_pin_value(KEYPAD_PORT_COL, colPins[col], LOGIC_HIGH);
    }

    /* إعداد الصفوف كمدخلات (INPUT) */
    for (row = 0; row < ROWS; row++)
    {
        DIO_set_pin_direction(KEYPAD_PORT_ROW, rowPins[row], PIN_INPUT);
        DIO_write_pin_value(KEYPAD_PORT_ROW, rowPins[row], LOGIC_HIGH); // pull-up
    }

    /* فحص الأعمدة والصفوف */
    for (col = 0; col < COLS; col++)
    {
        // نسحب العمود الحالي إلى LOW
        DIO_write_pin_value(KEYPAD_PORT_COL, colPins[col], LOGIC_LOW);

        for (row = 0; row < ROWS; row++)
        {
            pinValue = DIO_read_pin_value(KEYPAD_PORT_ROW, rowPins[row]);

            if (pinValue == 0)
            {
                key = Local_u8Keys[row][col];

                // انتظار حتى يترك الزر
                while (DIO_read_pin_value(KEYPAD_PORT_ROW, rowPins[row]) == 0);

                _delay_ms(20); // Debouncing
                DIO_write_pin_value(KEYPAD_PORT_COL, colPins[col], LOGIC_HIGH);
                return key;
            }
        }

        // نرجّع العمود إلى HIGH
        DIO_write_pin_value(KEYPAD_PORT_COL, colPins[col], LOGIC_HIGH);
    }

    return key;
}
