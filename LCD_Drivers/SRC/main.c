

#include "DIO.h"
#include "DELAY.h"
#include "STD_TYPES.h"
#include "LCD.h"

uint8_t count;
int main(void)
{
    LCD_init();
    LCD_clear();

    LCD_set_cursor(0, 0);
    LCD_write_str((uint8_t*)" MohamedMahrous: ");




    while(1)
    {

        LCD_set_cursor(1, 0);
        LCD_write_str((uint8_t*)"Count: ");
        LCD_write_number(count);

        _delay_ms(500);  // كل نصف ثانية يزيد العداد
        count++;

        if(count > 99)
            count = 0;
    }

    return 0;
}
