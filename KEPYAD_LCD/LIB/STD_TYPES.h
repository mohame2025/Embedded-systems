/* @file STD_TYPES.h
 * @brief Standard data types for AVR microcontrollers
 */



/* @file STD_TYPES.h
 * @brief Standard data types for AVR microcontrollers
 */

#ifndef STD_TYPES_H_
#define STD_TYPES_H_

#include <stdint.h>  // يحتوي على uint8_t, int8_t, uint16_t, int16_t, ...

/*---------------------------------------------
 *      Standard Return Type
 *--------------------------------------------*/
typedef unsigned char STD_ReturnType;

/*---------------------------------------------
 *      Logical Values
 *--------------------------------------------*/
#define STD_TRUE    1
#define STD_FALSE   0

//#define LOGIC_HIGH  1
//#define LOGIC_LOW   0

#define NULL_PTR    ((void*)0)

/*---------------------------------------------
 *      Shortcut Type Names (اختصارات مفيدة)
 *--------------------------------------------*/
typedef uint8_t   u8;
typedef int8_t    s8;
typedef uint16_t  u16;
typedef int16_t   s16;
typedef uint32_t  u32;
typedef int32_t   s32;
typedef uint64_t  u64;
typedef int64_t   s64;
typedef float     f32;
typedef double    f64;

/*---------------------------------------------
 *      Bit Access Structure
 *--------------------------------------------*/
typedef union {
    struct {
        uint8_t BIT0:1;
        uint8_t BIT1:1;
        uint8_t BIT2:1;
        uint8_t BIT3:1;
        uint8_t BIT4:1;
        uint8_t BIT5:1;
        uint8_t BIT6:1;
        uint8_t BIT7:1;
    } BitAccess;
    uint8_t ByteAccess;
} Register_8Bit;

#endif /* STD_TYPES_H_ */




/*
#ifndef STD_TYPES_H_
#define STD_TYPES_H_
#include <stdint.h>

typedef unsigned char        uint8_t;
typedef signed char          int8_t;
//typedef unsigned short       uint16_t;
//typedef signed short         uint16_t;
typedef unsigned long        uint32_t;
typedef signed long          int32_t;
typedef unsigned long long   uint64_t;
typedef signed long long     int64_t;
typedef float                float32_t;
typedef double               float64_t;

typedef unsigned char STD_ReturnType;

#define STD_TRUE   1
#define STD_FALSE  0

typedef union {
    struct {
        uint8_t BIT0:1;
        uint8_t BIT1:1;
        uint8_t BIT2:1;
        uint8_t BIT3:1;
        uint8_t BIT4:1;
        uint8_t BIT5:1;
        uint8_t BIT6:1;
        uint8_t BIT7:1;
    } BitAccess;
    uint8_t ByteAccess;
} Register_8Bit;

#endif  STD_TYPES_H_ */
