/*
 * main.c
 *
 *  Created on: Nov 10, 2025
 *      Author: Mohamed Ahmed
 */

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "GI.h"
#include "EXTI.h"
#include "DIO.h"
#include "DELAY.h"

// دالة اختبار — بس عشان نعرف إنها اشتغلت
void myInterruptFunction(void)
{
    // هنا تقدر تحط أي كود بسيط بعدين (مثلاً عداد أو رسالة)
}

int main(void)
{
    // تفعيل المقاطعات الخارجية INT0 (مثلاً) — من غير ما نعمل أي وظيفة حقيقية
    EXTI_enable(INT0, SENSE_FALLING_EDGE, myInterruptFunction);

    // تفعيل المقاطعات العامة
    GI_enable();

    while (1)
    {
        // الكود الأساسي — حالياً فاضي
    }

    return 0;
}
