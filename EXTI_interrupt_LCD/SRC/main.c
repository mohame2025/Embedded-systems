
/*  main.c
 *
 *  Created on: Oct 17, 2025
 *      Author: moham
 */

#include "DIO.h"
#include "DELAY.h"
#include "EXTI.h"
#include "GI.h"
#include "LCD.h"

void LCD_ON(void);
void LCD_OFF(void);


int main(void)
{
    // تهيئة شاشة LCD
    LCD_init();
    LCD_clear();
    LCD_set_cursor(0, 0);
    LCD_write_str((uint8_t*) "System Ready");

    // تفعيل المقاطعات العامة
    GI_enable();

    // تفعيل INT0 و INT1
    // عند الضغط على زر INT0 → تظهر كلمة ON
    // عند الضغط على زر INT1 → تظهر كلمة OFF
    EXTI_enable(INT0, 0, LCD_ON);
    EXTI_enable(INT1, 0, LCD_OFF);
    EXTI_enable(INT2, 0, LCD_ON);


    while(1)
    {
        // لا شيء داخل اللوب، لأن المقاطعات تقوم بالعمل
    }
}


void LCD_ON(void)
{
    LCD_clear();
    LCD_set_cursor(1, 1);
    LCD_write_str((uint8_t*) "LCD is ON");

}

void LCD_OFF(void)
{
    LCD_clear();
    LCD_set_cursor(1, 1);
    LCD_write_str((uint8_t*) "LCD is OFF");
}



