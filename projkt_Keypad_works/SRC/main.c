/*
 * main.c
 *
 *  Created on: Oct 17, 2025
 *      Author: moham
 */

#include "DIO.h"
#include "STD_TYPES.h"
#include "DELAY.h"

#define NOT_PRESSED 0xFF

/* تعريف الأعمدة والصفوف */
const uint8_t KPD_ROWS[4] = {PIN0_ID, PIN1_ID, PIN2_ID, PIN3_ID};
const uint8_t KPD_COLS[4] = {PIN4_ID, PIN5_ID, PIN6_ID, PIN7_ID};

/* تخطيط الأزرار */
const uint8_t KPD_KEYS[4][4] = {
    {'1','2','3','A'},
    {'4','5','6','B'},
    {'7','8','9','C'},
    {'*','0','#','D'}
};

void KPD_init(void)
{
    // الصفوف مخرجات
    for (uint8_t r = 0; r < 4; r++)
        DIO_set_pin_direction(PORTD_ID, KPD_ROWS[r], PIN_OUTPUT);

    // لأعمدة مدخلات مع مقاومة سحب داخلية
    for (uint8_t c = 0; c < 4; c++)
    {
        DIO_set_pin_direction(PORTD_ID, KPD_COLS[c], PIN_INPUT);
        DIO_write_pin_value(PORTD_ID, KPD_COLS[c], LOGIC_HIGH);
    }
}

uint8_t KPD_getPressedKey(void)
{
    for (uint8_t r = 0; r < 4; r++)
    {
        DIO_write_pin_value(PORTD_ID, KPD_ROWS[r], LOGIC_LOW);

        for (uint8_t c = 0; c < 4; c++)
        {
            if (DIO_read_pin_value(PORTD_ID, KPD_COLS[c]) == LOGIC_LOW)
            {
                _delay_ms(20);  // للتثبيت
                while (DIO_read_pin_value(PORTD_ID, KPD_COLS[c]) == LOGIC_LOW);
                DIO_write_pin_value(PORTD_ID, KPD_ROWS[r], LOGIC_HIGH);
                return KPD_KEYS[r][c];
            }
        }

        DIO_write_pin_value(PORTD_ID, KPD_ROWS[r], LOGIC_HIGH);
    }

    return NOT_PRESSED;
}
