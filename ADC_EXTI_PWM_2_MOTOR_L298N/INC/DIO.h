/* DIO.h
 *  Created on: Oct 3, 2025
 *  Author: mohamedMahrous
 */

#ifndef DIO_H_
#define DIO_H_

#include "STD_TYPES.h"
#include "BIT_MATH.h"




/* Define the ports */
enum {
    PORTA_ID,
    PORTB_ID,
    PORTC_ID,
    PORTD_ID
};

/* Define the pins */
enum {
    PIN0_ID,
    PIN1_ID,
    PIN2_ID,
    PIN3_ID,
    PIN4_ID,
    PIN5_ID,
    PIN6_ID,
    PIN7_ID
};

/* Define the direction */
enum {
    PIN_INPUT,
    PIN_OUTPUT
};

/* Define the logic value */
enum {
    LOGIC_LOW,
    LOGIC_HIGH
};

/* API - Application Programming Interface */

/* Pin Operations APIs */
void DIO_set_pin_direction(uint8_t port, uint8_t pin, uint8_t dir);
uint8_t DIO_read_pin_value(uint8_t port, uint8_t pin);
void DIO_write_pin_value(uint8_t port, uint8_t pin, uint8_t val);   // ✅ نفس الاسم المستخدم في main.c
void DIO_toggle_pin_value(uint8_t port, uint8_t pin);

/* PORT Operations APIs */
void DIO_set_port_direction(uint8_t port, uint8_t dir);
uint8_t DIO_read_port_value(uint8_t port);
void DIO_write_port_value(uint8_t port, uint8_t val);

#endif /* DIO_H_ */
