/*
 * main.c
 *
 *  Created on: Oct 17, 2025
 *      Author: mohamedMahrous
 */

#include "DIO.h"
#include "DELAY.h"
#include "PWM_interface.h"
#include "EXTI.h"
#include "ADC.h"
#include "GI.h"

// ====================
// Global variables
// ====================
volatile uint8_t motor_state = 0; // 0 = OFF, 1 = ON
volatile uint8_t direction   = 0; // 0 = CW, 1 = CCW

// Preload for PWM (TCNT, OCR)
uint8_t PRELOAD[2] = {0, 128};

// PWM configuration
PWM_config COFIG = {
    .WGM = PWM_fast,
    .COM = PWM_fast_clr_top,
    .CS = PWM_64PRE,
    .Timer = PWM_TIMER0,
    .preload = PRELOAD
};

// ====================
// Function prototypes
// ====================
void ISR_Motor_ON(void);
void ISR_Motor_OFF(void);
void ISR_Change_Dir(void);
void Update_Direction(void);
void PWM_Update_Duty(uint16_t adc_val);


// ====================
// Main program
// ====================
int main(void)
{
    // ---------- ADC ----------
    ADC_init(VCC, RIGHT_ADJUST, PRESCALLER_128);

    // ---------- PWM ----------
    gen_PWM(&COFIG);          // Init PWM
    PWM_stop(PWM_TIMER0);     // Start stopped

    // ---------- Direction pins ----------
    DIO_set_pin_direction(PORTC_ID, PIN3_ID, PIN_OUTPUT);
    DIO_set_pin_direction(PORTC_ID, PIN4_ID, PIN_OUTPUT);

    // ---------- Global interrupt ----------
    GI_enable();

    // ---------- EXTI buttons ----------
    EXTI_enable(INT0, SENSE_LOW, ISR_Motor_ON);    // زر تشغيل
    EXTI_enable(INT1, SENSE_LOW, ISR_Motor_OFF);   // زر إيقاف
    EXTI_enable(INT2, SENSE_FALLING_EDGE, ISR_Change_Dir); // زر تغيير اتجاه

    // ---------- Main loop ----------
    while(1)
    {
        if(motor_state == 1)
        {
            // Read potentiometer
            ADC_start_conversion();
            uint16_t adc_val = ADC_get_analog_value();

            // Update motor speed (convert 0-1023 → 0-255)
            PWM_Update_Duty(adc_val);
        }
    }

    return 0;
}


// ====================
// ISR functions
// ====================
void ISR_Motor_ON(void)
{
    motor_state = 1;
    gen_PWM(&COFIG);         // تشغيل المحرك مع القيم الحالية
    Update_Direction();
}

void ISR_Motor_OFF(void)
{
    motor_state = 0;
    PWM_stop(PWM_TIMER0);    // إيقاف المحرك
}

void ISR_Change_Dir(void)
{
    direction ^= 1;  // toggle
    Update_Direction();
}

// ====================
// Helper functions
// ====================
void Update_Direction(void)
{
    if(direction == 0)
    {
        DIO_write_pin_value(PORTC_ID, PIN3_ID, LOGIC_HIGH);
        DIO_write_pin_value(PORTC_ID, PIN4_ID, LOGIC_LOW);
    }
    else
    {
        DIO_write_pin_value(PORTC_ID, PIN3_ID, LOGIC_LOW);
        DIO_write_pin_value(PORTC_ID, PIN4_ID, LOGIC_HIGH);
    }
}

void PWM_Update_Duty(uint16_t adc_val)
{
    // Convert ADC 0-1023 → 0-255
    PRELOAD[1] = (adc_val * 255UL) / 1023;

    // Re-generate PWM with new OCR value
    gen_PWM(&COFIG);
}
