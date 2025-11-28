/*
 * KEYPAD_program.c
 *
 *  Created on: Oct 31, 2025
 *      Author: mohamed
 */


#include "DIO.h"
#include "DELAY.h"
#include "STD_TYPES.h"

#include "KEYPAD_interface.h"
#include "KEYPAD_config.h"
//#include "KEYPAD_private.h"

  uint8_t Keypad_u8GetPressedKey(void){

    uint8_t ROW, COL, PinValue, Key = NOT_PRESSED ;

	uint8_t COLArr[4]={ KEPYAD_COL0_PIN ,KEPYAD_COL1_PIN , KEPYAD_COL2_PIN, KEPYAD_COL3_PIN};
	uint8_t ROWArr[4]={KEPYAD_ROW0_PIN, KEPYAD_ROW1_PIN, KEPYAD_ROW2_PIN, KEPYAD_ROW3_PIN};

/*Set        COL OUTPUT      and    ROW INPUT*/


	for (COL = 0; COL < 4; COL++)
	    {
	        DIO_set_pin_direction(KEYPAD_PORT, COLArr[COL], PIN_OUTPUT);
	        DIO_write_pin_value(KEYPAD_PORT, COLArr[COL], LOGIC_HIGH);
	    }

	    for (ROW = 0; ROW < 4; ROW++)
	    {
	        DIO_set_pin_direction(KEYPAD_PORT, ROWArr[ROW], PIN_INPUT);
	        DIO_write_pin_value(KEYPAD_PORT, ROWArr[ROW], LOGIC_HIGH);
	    }

	    /* فحص الأعمدة والصفوف */
	    for (COL = 0; COL < 4; COL++)
	    {
	        // نخفض العمود الحالي
	        DIO_write_pin_value(KEYPAD_PORT, COLArr[COL], LOGIC_LOW);

	        for (ROW = 0; ROW < 4; ROW++)
	        {
	            PinValue = DIO_read_pin_value(KEYPAD_PORT, ROWArr[ROW]);

	            if (PinValue == 0)
	            {
	              //  Key = Local_u8Keys[ROW][COL];

	                // انتظار حتى يترك الزر
	                while (PinValue == 0)
	                {
	                    PinValue = DIO_read_pin_value(KEYPAD_PORT, ROWArr[ROW]);
	                }

	                _delay_ms(20);
	                DIO_write_pin_value(KEYPAD_PORT, COLArr[COL], LOGIC_HIGH);
	                return Key;
	            }
	        }

	        // نرجّع العمود إلى الحالة العالية
	        DIO_write_pin_value(KEYPAD_PORT, COLArr[COL], LOGIC_HIGH);
	    }

	    return Key;
	}





























	/*
// إعداد الأعمدة كمخرجات (OUTPUT) وصفوف كمدخلات (INPUT)
     for (COL= 0; COL < 4; COL++){

    DIO_set_pin_direction(KEYPAD_PORT, COLArr[COL], PIN_OUTPUT);
    DIO_write_pin_value(KEYPAD_PORT,   COLArr[COL], LOGIC_HIGH);

     }
    for (ROW = 0; ROW < 4; ROW++){

    DIO_set_pin_direction(KEYPAD_PORT, ROWArr[ROW], PIN_INPUT);
    DIO_write_pin_value(KEYPAD_PORT, ROWArr[ROW], LOGIC_HIGH);

    }

 for (COL = 0; COL < 4; COL++){

    // نخفض العمود الحالي
    DIO_write_pin_value(KEYPAD_PORT, COLArr[COL], LOGIC_LOW);
 }
    for (ROW = 0; ROW < 4; ROW++){

     uint8_t  PinValue = DIO_read_pin_value(KEYPAD_PORT, ROWArr[ROW]);

        if (PinValue == 0){

            Key = Local_u8Keys[ROW][COL];
        }
    }
            // انتظار حتى يترك الزر
            while (PinValue == 0){


            	DIO_read_pin_value(KEYPAD_PORT, ROWArr[ROW],& PinValue);

          _delay_ma(20);
  }
return Key;
}
  */
