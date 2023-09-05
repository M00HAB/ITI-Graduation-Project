#include <avr/io.h>
#include <util/delay.h>
#include "Keypad.h"
#include "Dio.h"
#include "Bit_Math.h"
#include "Std_Types.h"

static void KeyPad_SetColumnLevel(u8 column, Dio_PinType Level)
{
    switch (column)
    {
    case 0:
        Dio_SetPinLevel(KEYPAD_PIN_C1, Level);
        break;
    case 1:
        Dio_SetPinLevel(KEYPAD_PIN_C2, Level);
        break;
    case 2:
        Dio_SetPinLevel(KEYPAD_PIN_C3, Level);
        break;
    case 3:
        Dio_SetPinLevel(KEYPAD_PIN_C4, Level);
        break;
    }
    return;
}

static Dio_PinLevelType KeyPad_GetRowLevel(u8 row)
{
	Dio_PinLevelType level = STD_LOW;
    switch (row)
    {
    case 0:
        level = Dio_ReadPinLevel(KEYPAD_PIN_R1);
        break;
    case 1:
        level = Dio_ReadPinLevel(KEYPAD_PIN_R2);
        break;
    case 2:
        level = Dio_ReadPinLevel(KEYPAD_PIN_R3);
        break;
    case 3:
        level = Dio_ReadPinLevel(KEYPAD_PIN_R4);
        break;
    }
    return level;
}

void KeyPad_Init()
{
    Dio_SetPinMode(KEYPAD_PIN_R1, DIO_PIN_INPUT_PULLUP);
    Dio_SetPinMode(KEYPAD_PIN_R2, DIO_PIN_INPUT_PULLUP);
    Dio_SetPinMode(KEYPAD_PIN_R3, DIO_PIN_INPUT_PULLUP);
    Dio_SetPinMode(KEYPAD_PIN_R4, DIO_PIN_INPUT_PULLUP);

    Dio_SetPinMode(KEYPAD_PIN_C1, DIO_PIN_OUTPUT);
    Dio_SetPinMode(KEYPAD_PIN_C2, DIO_PIN_OUTPUT);
    Dio_SetPinMode(KEYPAD_PIN_C3, DIO_PIN_OUTPUT);
    Dio_SetPinMode(KEYPAD_PIN_C4, DIO_PIN_OUTPUT);

    Dio_SetPinLevel(KEYPAD_PIN_C1, STD_HIGH);
    Dio_SetPinLevel(KEYPAD_PIN_C2, STD_HIGH);
    Dio_SetPinLevel(KEYPAD_PIN_C3, STD_HIGH);
    Dio_SetPinLevel(KEYPAD_PIN_C4, STD_HIGH);
}

KeyPad_ButtonState KeyPad_GetButtonState(KeyPad_ButtonType Button)
{
    u8 column = Button % 4;
    u8 row = Button / 4;
    KeyPad_ButtonState state = KEYPAD_NOT_PRESSED;
    KeyPad_SetColumnLevel(column, STD_LOW);
    if (KeyPad_GetRowLevel(row) == STD_LOW)
    {
        _delay_ms(30);
        if (KeyPad_GetRowLevel(row) == STD_LOW)
        {
            state = KEYPAD_PRESSED;
        }
    }
    KeyPad_SetColumnLevel(column, STD_HIGH);
    return state;
}

KeyPad_ButtonType KeyPad_GetPressedButton(void)
{
    u8 i;
    KeyPad_ButtonType button = KEYPAD_INVALID;
    for (i = 0; i < 16; i++)
    {
        if (KeyPad_GetButtonState(i) == KEYPAD_PRESSED)
        {
            button = i;
            break;
        }
    }
    return button;
}

