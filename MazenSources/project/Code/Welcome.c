#include <avr.io.h>
#include <util/delay.h>
#include <avr/interrupt.h>
#include "Welcome.h"
#include "Lcd.h"
#include "KeyPad.h"
#include "Std_Types.h"

extern u8 SafeMode;

static u8 OldPassword()
{
    u8 x;
    u8 Choice[4];
    LCD_CursorPosition(1,0);
    LCD_SendString(" Old Password: ")
    LCD_CursorPosition(2,0);
    u8 No_of_Entered = 0;
    while(No_of_Entered < 4)
    {
        x = KeyPad_GetPressedButton();
        if ((x / 4 < 3 && x % 4 < 3) || x == KEYPAD_B13)
        {
            Choice[No_of_Entered] = x;
            LCD_SendData(Choice[No_of_Entered]);
            // if (Choice[No_of_Entered] != Password[No_of_Entered]){
            //     return 1;
            // }
            No_of_Entered++;
        }
    }
    return 0;
}

static void PasswordChange()
{
    if (OldPassword() == 1)
    {
        // We will open the Buzzer in Joe's Code.
        // Dio_SetPinLevel(BUZZERPIN,STD_HIGH);
        // _delay_ms(5000);
        // Dio_SetPinLevel(LIGHT_PIN,STD_LOW);
    }
    else {
        // Set New Password From Ali's Code.
    }
}

static void SafeMode()
{
    // This Function is using Ali's Safe Mode Needing Ali's Help.
}

void Welcome()
{
    KeyPad_Init();
    LCD_Init();
    LCD_CursorPosition(1,5);
    LCD_SendString("Welcome");
    LCD_CursorPosition(2,0);
    LCD_SendString("Have a safe stay");
    _delay_ms(500);
    LCD_SendCommand(0x01);
    LCD_CursorPosition(1,0);
    LCD_SendString("for safe mode 1 ");
    LCD_CursorPosition(2,0);
    LCD_SendString("for passwords 2 ");
    // GettingChoice(); According to ali
}

void GettingChoice()
{
    KeyPad_ButtonState Choice;
    do {
        Choice = KeyPad_GetPressedButton();
    } while(Choice != KEYPAD_B08 && Choice != KEYPAD_B09);
    switch (Choice)
    {
    case KEYPAD_B08:
        SafeMode();
        break;
    
    case KEYPAD_B09:
        PasswordChange();
        break;
    
    default:
        #error "How You Passed the while Loop!!!!!";
        break;
    }
    PasswordChange();
}