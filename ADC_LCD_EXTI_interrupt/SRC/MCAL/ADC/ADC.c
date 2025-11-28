/*
 * adc.C
 *
 *  Created on: Nov 14, 2025
 *      Author: Mohamed
 */
#include "ADC.h"
#include "ADC_reg.h"
#include "ADC_private.h"



static void (*ADC_CallBack)(uint16_t) = 0;


void ADC_init(uint8_t Vref, uint8_t Left_adjust, uint8_t Prescaller)
{
	/* Configure the Vref */
	if(Vref != RESERVED)
	{
		ASSIGN_BIT(ADMUX, REFS0, GET_BIT(Vref, 0));
		ASSIGN_BIT(ADMUX, REFS1, GET_BIT(Vref, 1));
	}

	/* Configure the data register adjustment */
	ASSIGN_BIT(ADMUX, ADLAR, Left_adjust);

	/* Configure the pre-scaller */
	ASSIGN_BIT(ADCSRA, ADPS0, GET_BIT(Prescaller, 0));
	ASSIGN_BIT(ADCSRA, ADPS1, GET_BIT(Prescaller, 1));
	ASSIGN_BIT(ADCSRA, ADPS2, GET_BIT(Prescaller, 2));

	/* Enable the ADC */
	SET_BIT(ADCSRA, ADEN);
}

void ADC_select_channel(uint8_t channel)
{
	ADMUX &= 0xE0;
	ADMUX |= channel;
}

void ADC_start_conversion(void)
{
	SET_BIT(ADCSRA, ADSC);
}

uint16_t ADC_get_analog_value(void)
{
	while(GET_BIT(ADCSRA, ADIF) == 0);
	SET_BIT(ADCSRA, ADIF);
	return ADC_VALUE;
}

void ADC_enable_interrupt(void (*ADC_CLBK)(uint16_t))
{
    ADC_CallBack = ADC_CLBK;  // Save callback
    SET_BIT(ADCSRA, ADIE);    // Enable ADC interrupt (ADIE = 1)
}


void ADC_disable_interrupt(void)
{
	RESET_BIT(ADCSRA, ADIE);  // Disable ADC interrupt
}


/********************************************************************/
/*                          ADC ISR                                  */
/********************************************************************/
/*
ISR(ADC_vect)
{
    if (ADC_CallBack != 0)
    {
        ADC_CallBack(ADC_VALUE);   // Pass ADC result to user callback
    }

    SET_BIT(ADCSRA, ADIF);          // Clear interrupt flag
}*/
