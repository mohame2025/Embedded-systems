/*
 * DIO.c
 *
 *  Created on: Oct 3, 2025
 *      Author: OmarAbdulqadir
 */

#include "DIO.h"
#include "DIO_REG.h"
#include "DIO_PRIVATE.h"

/* Pin Operations APIs */
void DIO_set_pin_direction(u8 port, u8 pin, u8 dir)
{
    switch(port)
    {
        case PORTA_ID: {ASSIGN_BIT(DDRA, pin, dir);} break;
        case PORTB_ID: {ASSIGN_BIT(DDRB, pin, dir);} break;
        case PORTC_ID: {ASSIGN_BIT(DDRC, pin, dir);} break;
        case PORTD_ID: {ASSIGN_BIT(DDRD, pin, dir);} break;
        default: {/* Error */} break;
    }
}

u8 DIO_read_pin_value(u8 port, u8 pin)
{
	u8 val = 0;
    switch(port)
    {
        case PORTA_ID: {val = GET_BIT(PINA, pin);} break;
        case PORTB_ID: {val = GET_BIT(PINB, pin);} break;
        case PORTC_ID: {val = GET_BIT(PINC, pin);} break;
        case PORTD_ID: {val = GET_BIT(PIND, pin);} break;
        default: {/* Error */} break;
    }
    return val;
}

void DIO_write_pin_value(u8 port, u8 pin, u8 val)
{
    switch(port)
    {
        case PORTA_ID: {ASSIGN_BIT(PORTA, pin, val);} break;
        case PORTB_ID: {ASSIGN_BIT(PORTB, pin, val);} break;
        case PORTC_ID: {ASSIGN_BIT(PORTC, pin, val);} break;
        case PORTD_ID: {ASSIGN_BIT(PORTD, pin, val);} break;
        default: {/* Error */} break;
    }
}

void DIO_toggle_pin_value(u8 port, u8 pin)
{
    switch(port)
    {
        case PORTA_ID: {TOGGLE_BIT(PORTA, pin);} break;
        case PORTB_ID: {TOGGLE_BIT(PORTB, pin);} break;
        case PORTC_ID: {TOGGLE_BIT(PORTC, pin);} break;
        case PORTD_ID: {TOGGLE_BIT(PORTD, pin);} break;
        default: {/* Error */} break;
    }
}

/* PORT Operations APIs */
void DIO_set_port_direction(u8 port, u8 dir)
{
    switch(port)
    {
        case PORTA_ID: {DDRA = dir;} break;
        case PORTB_ID: {DDRB = dir;} break;
        case PORTC_ID: {DDRC = dir;} break;
        case PORTD_ID: {DDRD = dir;} break;
        default: {/* Error */} break;
    }
}

u8 DIO_read_port_value(u8 port)
{
	u8 value = 0;

    switch(port)
    {
        case PORTA_ID: { value = PINA; } break;
        case PORTB_ID: { value = PINB; } break;
        case PORTC_ID: { value = PINC; } break;
        case PORTD_ID: { value = PIND; } break;
        default: {/* Error */} break;
    }

    return value;
}

void DIO_write_port_value(u8 port, u8 val)
{
    switch(port)
    {
        case PORTA_ID: { PORTA = val; } break;
        case PORTB_ID: { PORTB = val; } break;
        case PORTC_ID: { PORTC = val; } break;
        case PORTD_ID: { PORTD = val; } break;
        default: {/* Error */} break;
    }
}
