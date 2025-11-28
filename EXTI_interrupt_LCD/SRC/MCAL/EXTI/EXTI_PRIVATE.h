/*
 * EXTI_PRIVATE.h
 *
 *  Created on: Oct 24, 2025
 *      Author: OmarAbdulqadir
 */

#ifndef _EXTI_PRIVATE_H_
#define _EXTI_PRIVATE_H_

#define VIE_INT0		6
#define VIE_INT1		7
#define VIE_INT2		5

#define VIF_INT0		6
#define VIF_INT1		7
#define VIF_INT2		5



#define NULL			(void*)0

void __vector_1(void)__attribute__((signal));
void __vector_2(void)__attribute__((signal));
void __vector_3(void)__attribute__((signal));

#endif /* _EXTI_PRIVATE_H_ */
