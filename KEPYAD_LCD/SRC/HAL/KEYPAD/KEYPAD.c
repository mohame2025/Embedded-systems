/*
 *<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<    KPD_program.c    >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
 *
 *  Author : Modified by Mohamed Ahmed
 *  Layer  : HAL
 *  SWC    : KPD
 *
 */


#include "DELAY.h"
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "DIO.h"
#include "KEYPAD.h"
#include "KEPYAD_private.h"
#include "KEYPAD_config.h"

//----------------------------------------------------------------------------------------------------------------------------------------------------
/*
 * Brief : Initialize keypad pins (rows = input + pull-up, cols = output)
 */
void KPD_Init(void)
{
    // إعداد الصفوف كـ INPUT + تفعيل مقاومة السحب لأعلى Pull-up
    DIO_set_pin_direction(KPD_PORT, KPD_R0, PIN_INPUT);
    DIO_set_pin_direction(KPD_PORT, KPD_R1, PIN_INPUT);
    DIO_set_pin_direction(KPD_PORT, KPD_R2, PIN_INPUT);
    DIO_set_pin_direction(KPD_PORT, KPD_R3, PIN_INPUT);

    DIO_write_pin_value(KPD_PORT, KPD_R0, LOGIC_HIGH);
    DIO_write_pin_value(KPD_PORT, KPD_R1, LOGIC_HIGH);
    DIO_write_pin_value(KPD_PORT, KPD_R2, LOGIC_HIGH);
    DIO_write_pin_value(KPD_PORT, KPD_R3, LOGIC_HIGH);


    /*        This code equivalent to connect pull up for the pins of the rows                  */

    	/*DIO_enumSetPinDirection( KPD_PORT , KPD_R0 , DIO_INPUT );
    	DIO_enumSetPinDirection( KPD_PORT , KPD_R1 , DIO_INPUT );
    	DIO_enumSetPinDirection( KPD_PORT , KPD_R2 , DIO_INPUT );
    	DIO_enumSetPinDirection( KPD_PORT , KPD_R3 , DIO_INPUT );

    	DIO_enumSetPinValue    ( KPD_PORT , KPD_R0 , DIO_HIGH );
    	DIO_enumSetPinValue    ( KPD_PORT , KPD_R1 , DIO_HIGH );
    	DIO_enumSetPinValue    ( KPD_PORT , KPD_R2 , DIO_HIGH );
    	DIO_enumSetPinValue    ( KPD_PORT , KPD_R3 , DIO_HIGH );*/


    	/*                 connect the pins of the columns as output pins (HIGH)                    */


    // إعداد الأعمدة كـ OUTPUT ورفعها HIGH
    DIO_set_pin_direction(KPD_PORT, KPD_C0, PIN_OUTPUT);
    DIO_set_pin_direction(KPD_PORT, KPD_C1, PIN_OUTPUT);
    DIO_set_pin_direction(KPD_PORT, KPD_C2, PIN_OUTPUT);
    DIO_set_pin_direction(KPD_PORT, KPD_C3, PIN_OUTPUT);

    DIO_write_pin_value(KPD_PORT, KPD_C0, LOGIC_HIGH);
    DIO_write_pin_value(KPD_PORT, KPD_C1, LOGIC_HIGH);
    DIO_write_pin_value(KPD_PORT, KPD_C2, LOGIC_HIGH);
    DIO_write_pin_value(KPD_PORT, KPD_C3, LOGIC_HIGH);
}

//----------------------------------------------------------------------------------------------------------------------------------------------------
/*
 * Brief : Scan the keypad and return the pressed key
 */
uint8_t KPD_u8GetPressed(void)
{
    uint8_t LOC_u8ReturnData = NOTPRESSED;
    uint8_t LOC_u8GetPressed;
    uint8_t LOC_u8Row;
    uint8_t LOC_u8Col;

    for (LOC_u8Col = KPD_COL_INIT; LOC_u8Col <= KPD_COL_END; LOC_u8Col++)
    {
        // ضع العمود الحالي على LOW
        DIO_write_pin_value(KPD_PORT, LOC_u8Col, LOGIC_LOW);

        // فحص الصفوف
        for (LOC_u8Row = KPD_ROW_INIT; LOC_u8Row <= KPD_ROW_END; LOC_u8Row++)
        {
            LOC_u8GetPressed = DIO_read_pin_value(KPD_PORT, LOC_u8Row);

            if (LOC_u8GetPressed == 0) // الزر مضغوط
            {
                _delay_ms(50); // لتفادي الاهتزاز (debounce)
                LOC_u8GetPressed = DIO_read_pin_value(KPD_PORT, LOC_u8Row);

                if (LOC_u8GetPressed == 0)
                {
                    LOC_u8ReturnData = KPD_u8Buttons[LOC_u8Row - KPD_ROW_INIT][LOC_u8Col - KPD_COL_INIT];
                }

                // انتظر حتى يترك المستخدم الزر
                while (DIO_read_pin_value(KPD_PORT, LOC_u8Row) == 0)
                    ;

                break;
            }
        }

        // أعد العمود إلى HIGH
        DIO_write_pin_value(KPD_PORT, LOC_u8Col, LOGIC_HIGH);
    }

    return LOC_u8ReturnData;
}





















/*
#include "KEYPAD.h"
#include "DIO.h"
#include "KEYPAD_config.h"
#include "DELAY.h"


uint8_t KEYPAD_Press(void)
{
    uint8_t arr[4][4] = {
    		        {'7','8','9','/'},
    		        {'4','5','6','*'},
    		        {'1','2','3','-'},
    		        {'c','0','=','+'}};

    uint8_t row, column, state;
    uint8_t return_val = NOTPRESSED;

    for (row = 0; row < 4; row++)
    {
        DIO_write_pin_value(KEYPAD_PORT_ROW, 4, LOGIC_HIGH);
        DIO_write_pin_value(KEYPAD_PORT_ROW, 5, LOGIC_HIGH);
        DIO_write_pin_value(KEYPAD_PORT_ROW, 6, LOGIC_HIGH);
        DIO_write_pin_value(KEYPAD_PORT_ROW, 7, LOGIC_HIGH);

        DIO_write_pin_value(KEYPAD_PORT_ROW, (row + 4), LOGIC_LOW);

        for (column = 0; column < 4; column++)
        {
            state = DIO_read_pin_value(KEYPAD_PORT_COL, (column));
            if (state == 0)
            {
                return_val = arr[row][column];
                while (DIO_read_pin_value(KEYPAD_PORT_COL, column) == 0);
                _delay_ms(50);
                return return_val;
            }
        }
    }
   return return_val;
}

void KEYPAD_Init(void)
{
    // إعداد صفوف كمخارج
    DIO_set_pin_direction(KEYPAD_PORT_ROW, 4, PIN_OUTPUT);
    DIO_set_pin_direction(KEYPAD_PORT_ROW, 5, PIN_OUTPUT);
    DIO_set_pin_direction(KEYPAD_PORT_ROW, 6, PIN_OUTPUT);
    DIO_set_pin_direction(KEYPAD_PORT_ROW, 7, PIN_OUTPUT);

    // إعداد الأعمدة كمداخل مع مقاومة سحب لأعلى
    DIO_set_pin_direction(KEYPAD_PORT_COL, 0, PIN_INPUT);
    DIO_set_pin_direction(KEYPAD_PORT_COL, 1, PIN_INPUT);
    DIO_set_pin_direction(KEYPAD_PORT_COL, 2, PIN_INPUT);
    DIO_set_pin_direction(KEYPAD_PORT_COL, 3, PIN_INPUT);

    // تفعيل Pull-up
    DIO_write_pin_value(KEYPAD_PORT_COL, 0, LOGIC_HIGH);
    DIO_write_pin_value(KEYPAD_PORT_COL, 1, LOGIC_HIGH);
    DIO_write_pin_value(KEYPAD_PORT_COL, 2, LOGIC_HIGH);
    DIO_write_pin_value(KEYPAD_PORT_COL, 3, LOGIC_HIGH);

}
*/
