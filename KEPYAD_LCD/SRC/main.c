/*
 * main.c
 *
 *  Created on: Oct 17, 2025
 *      Author: Mohamed Ahmed
 */

#include "DIO.h"
#include "DELAY.h"
#include "LCD.h"
#include "KEYPAD.h"
#include "STD_TYPES.h"

int main(void)
{
    uint8_t key;
    uint8_t counter = 0;

    // ===== التهيئة =====
    LCD_init();             // تهيئة شاشة LCD
    KPD_Init();        // تهيئة الكيباد

    LCD_clear();

    while(1)
    {
        key =  KPD_u8GetPressed();  // قراءة المفتاح

        if(key != NOTPRESSED)
        {
            // زيادة العداد
            counter++;
            if(counter > 99)
                counter = 0;

            // ===== عرض على LCD =====
            LCD_clear();
            LCD_set_cursor(0, 0);
            LCD_write_str((uint8_t*)"Pressed:");
            LCD_set_cursor(0, 9);
            LCD_write_char(key);

            LCD_set_cursor(1, 0);
            LCD_write_str((uint8_t*)"Count:");
            LCD_write_number(counter);

            _delay_ms(100); // تأخير بسيط لتجنب التكرار السريع
        }
    }
}
