/**
 * @file DELAY.h
 * @author mohamedMahrous (mohamedahmedmahrous69@gmail.com)
 * @brief Delay functions for AVR microcontrollers
 * @version 1.0
 * @date 2025-10-03
 * 
 * @copyright Copyright (c) 2025
 * 
 */

#ifndef _UTIL_DELAY_H_
#define _UTIL_DELAY_H_

#include "STD_TYPES.h"

// !! CRITICAL: Define the CPU frequency (e.g., 8 MHz) !!
#undef F_CPU
#define F_CPU 16000000UL

/**
 * @brief Performs a blocking delay for a specified number of microseconds (us).
 *
 * NOTE: This implementation is highly sensitive to CPU frequency and compiler optimization.
 * It is less accurate than using hardware timers or the optimized _delay_us().
 *
 * @param us The number of microseconds to delay.
 */
inline void _delay_us(uint32_t us) {
	uint32_t delay_counter;
    // Cycles per microsecond = (F_CPU / 1,000,000)
    uint32_t cycles_per_us = F_CPU / 1000000UL;

    // Estimate cycles per loop iteration (e.g., ~4 cycles for load, compare, subtract, branch).
    const uint8_t cycles_per_loop = 10;

    // Calculate total loop iterations required
    uint32_t iterations = (cycles_per_us / cycles_per_loop) * us;

    for (delay_counter = 0; delay_counter < iterations; ++delay_counter) {
        // Optional: Insert NOP for consistent timing within the loop
        __asm__ __volatile__ ("nop");
    }
}

/**
 * @brief Performs a blocking delay for a specified number of milliseconds (ms).
 *
 * @param ms The number of milliseconds to delay.
 */
inline void _delay_ms(uint32_t ms) {
    // We can implement ms delay by calling us delay 'ms' times if us is reliable,
    // or by recalculating iterations for better precision over longer periods.

	uint32_t delay_counter;
    uint32_t cycles_per_ms = F_CPU / 1000UL;
    const uint8_t cycles_per_loop = 10; // Must be consistent with us function
    uint32_t iterations = (cycles_per_ms / cycles_per_loop) * ms;

    for (delay_counter = 0; delay_counter < iterations; ++delay_counter) {
         __asm__ __volatile__ ("nop");
    }
}

#endif /* _DELAY_H_ */
