#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>
#include "GPT.h"
#include "Std_Types.h"
#include "Dio.h"
#include "Bit_Math.h"

u16 counter = 0;
u8 counter_of_seconds = 0;
ISR0
{
    counter++;
    if (counter == 3907)
    {
        counter = 0;
        counter_of_seconds++;
        if (counter_of_seconds == 10)
        {
            // The Detection of the Burglar
            // Buzzer from Joe's code 
            GPT_DisableNotification(GPT_TNT_SOURCE_TIM0_OV);
        }
    }
}

void Timer_Init()
{
    GPT_Init();
    TCNT0 = 192;
    GPT_EnableNotification(GPT_TNT_SOURCE_TIM0_OV);
    // The Printing functions should be added to counter 
    // on the lcd screen in the second line if it is possible
}