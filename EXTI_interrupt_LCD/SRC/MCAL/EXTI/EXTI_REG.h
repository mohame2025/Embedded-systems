/*
 * EXTI_REG.h
 *
 *  Created on: Oct 24, 2025
 *      Author: OmarAbdulqadir
 */

#ifndef _EXTI_REG_H_
#define _EXTI_REG_H_

#define MCUCR		*((volatile uint8_t*)0x55)
#define MCUCSR		*((volatile uint8_t*)0x54)
#define GICR		*((volatile uint8_t*)0x5B)
#define GIFR 		*((volatile uint8_t*)0x5A)

#endif /* _EXTI_REG_H_ */
