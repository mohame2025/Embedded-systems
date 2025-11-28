/*
 * DIO_REG.h
 *
 *  Created on: Oct 3, 2025
 *      Author: Mohamed
 */

#ifndef DIO_REG_H_
#define DIO_REG_H_

#define DDRA    (*((volatile uint8_t*)0x3A))
#define PORTA   (*((volatile uint8_t*)0x3B))
#define PINA    (*((volatile uint8_t*)0x39))

#define DDRB    (*((volatile uint8_t*)0x37))
#define PORTB   (*((volatile uint8_t*)0x38))
#define PINB    (*((volatile uint8_t*)0x36))

#define DDRC    (*((volatile uint8_t*)0x34))
#define PORTC   (*((volatile uint8_t*)0x35))
#define PINC    (*((volatile uint8_t*)0x33))

#define DDRD    (*((volatile uint8_t*)0x31))
#define PORTD   (*((volatile uint8_t*)0x32))
#define PIND    (*((volatile uint8_t*)0x30))

#endif /* DIO_REG_H_ */
