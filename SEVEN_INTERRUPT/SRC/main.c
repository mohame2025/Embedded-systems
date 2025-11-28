/*
 * main.c
 *
 *  Created on: Oct 17, 2025
 *      Author: moham
 */

#include "DIO.h"
#include "DELAY.h"
#include "EXTI.h"
#include "GI.h"
#include "SEVENSEG_interface.h"

void SEG_ON(void);
void SEG_OFF(void);

uint8_t count = 0;
uint8_t paused = 0;

int main(void)
{
    DIO_set_port_direction(PORTA_ID, 0xFF);
    DIO_set_pin_direction(PORTC_ID, PIN6_ID, PIN_OUTPUT);
    DIO_set_pin_direction(PORTC_ID, PIN7_ID, PIN_OUTPUT);

    GI_enable();

    EXTI_enable(INT0, 0, SEG_ON);
    EXTI_enable(INT1, 0, SEG_OFF);

    while(1)
    {
        if(!paused)
        {
            SEVENSEG_DisplayNumber(PORTA_ID, PORTC_ID, PIN6_ID, PIN7_ID, count);
            _delay_ms(300);

            count++;
            if(count == 100) count = 0;
        }
    }
}

void SEG_ON(void)
{
    paused = 0;
}

void SEG_OFF(void)
{
    paused = 1;
}





/*
#include "DIO.h"
#include "DELAY.h"
#include "EXTI.h"
#include "GI.h"
#include <SEVENSEG_interface.h>

void SEG_ON(void);
void SEG_OFF(void);

int main(void)
{

	    DIO_set_port_direction(PORTA_ID, 0xFF); // كل أطراف الـ data OUT
	    DIO_set_pin_direction(PORTC_ID, PIN6_ID, PIN_OUTPUT); // رجل الشاشة الأولى
	    DIO_set_pin_direction(PORTC_ID, PIN7_ID, PIN_OUTPUT); // رجل الشاشة الثانية

	    GI_enable();

     	EXTI_enable(INT0, 0, SEG_ON);
	    EXTI_enable(INT1, 0, SEG_OFF);


	while(1)
	{
        for (uint8_t count = 0; count <= 99; count++){
        	SEVENSEG_DisplayNumber(PORTA_ID, PORTC_ID, PIN6_ID, PIN7_ID, count);
	  }
}

void SEG_ON(void)
{
	DIO_write_pin_value(PORTC_ID, PIN0_ID, LOGIC_HIGH);

}


void SEG_OFF(void)
{
	DIO_write_pin_value(PORTC_ID, PIN1_ID, LOGIC_LOW);

     }
   }

*/
