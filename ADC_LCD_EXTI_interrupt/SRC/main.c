/*
 * main.c
 *
 *  Created on: Oct 17, 2025
 *      Author: MohamedMahrous
 */
#include "DIO.h"
#include "DELAY.h"
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "ADC.h"
#include "LCD.h"
#include "EXTI.h"
#include "GI.h"


void LCD_ON(void);
uint16_t adc_val = 0;
int main(void)
{

	ADC_init(VCC, RIGHT_ADJUST, PRESCALLER_128);
	    LCD_init();
	    LCD_clear();
	    LCD_set_cursor(0, 0);
	    LCD_write_str((uint8_t*) "System Ready");

	    GI_enable();

	    EXTI_enable(INT0, 0, LCD_ON);


	    while(1)
	    {
			  ADC_start_conversion();

			  adc_val= ADC_get_analog_value();


	    }
	}


	void LCD_ON(void)
	{

		  if(adc_val < 512){//<1024
			  LCD_clear();
			  LCD_set_cursor(0, 0);
			  LCD_write_number(adc_val);

		}
	}
