/*
 * ADC.h
 *
 *  Created on: oct 17, 2025
 *      Author: mohamedMahrous
 */

#ifndef _ADC_H_
#define _ADC_H_

#include "BIT_MATH.h"
#include "STD_TYPES.h"

enum Vref
{
	AREF	= 0,
	VCC		= 1,
	RESERVED= 2,
	INT_REF	= 3
};

enum LEFT_ADJUST
{
	RIGHT_ADJUST	= 0,
	LEFT_ADJUST		= 1
};

enum PRESCALLER
{
	PRESCALLER_2	= 1,
	PRESCALLER_4	= 2,
	PRESCALLER_8	= 3,
	PRESCALLER_16	= 4,
	PRESCALLER_32	= 5,
	PRESCALLER_64	= 6,
	PRESCALLER_128	= 7
};

void ADC_init(uint8_t Vref, uint8_t Left_adjust, uint8_t Prescaller);
void ADC_select_channel(uint8_t channel);
void ADC_start_conversion(void);
uint16_t ADC_get_analog_value(void);

void ADC_enable_interrupt(void (*ADC_CLBK)(uint16_t));
void ADC_disable_interrupt(void);

#endif /* INC_ADC_H_ */
