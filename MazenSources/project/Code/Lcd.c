/*
 * Lcd.c
 *
 *  Created on: Aug 25, 2023
 *      Author: Acer
 */
#include "avr/io.h"
#include <avr/delay.h>
#include "Bit_Math.h"
//#include "Std_Types.h"
#include "Lcd.h"
#include "Dio.h"

// Sending Commands to the LCD.
void LCD_SendCommand(u8 command)
{
    // Setting the register to write on LCD.
    Dio_SetPinLevel(LCD_PINS_RS, STD_LOW);
    Dio_SetPinLevel(LCD_PINS_RW, STD_LOW);

    // Sending the command to the LCD.
    Dio_SetPinLevel(LCD_PINS_D0, GET_BIT(command, 0));
    Dio_SetPinLevel(LCD_PINS_D1, GET_BIT(command, 1));
    Dio_SetPinLevel(LCD_PINS_D2, GET_BIT(command, 2));
    Dio_SetPinLevel(LCD_PINS_D3, GET_BIT(command, 3));
    Dio_SetPinLevel(LCD_PINS_D4, GET_BIT(command, 4));
    Dio_SetPinLevel(LCD_PINS_D5, GET_BIT(command, 5));
    Dio_SetPinLevel(LCD_PINS_D6, GET_BIT(command, 6));
    Dio_SetPinLevel(LCD_PINS_D7, GET_BIT(command, 7));

    // Enable the LCD to receive the command.
    Dio_SetPinLevel(LCD_PINS_EN, STD_HIGH);
    // Wait for changes.
    _delay_ms(2);
    // Disable the LCD from further changes.
    Dio_SetPinLevel(LCD_PINS_EN, STD_LOW);
}

// Sending data to the LCD.
void LCD_SendData(u8 data)
{
    // Setting the register to write on LCD.
    Dio_SetPinLevel(LCD_PINS_RW, STD_LOW);
    Dio_SetPinLevel(LCD_PINS_RS, STD_HIGH);

    // Sending the command to the LCD.
    Dio_SetPinLevel(LCD_PINS_D0, GET_BIT(data, 0));
    Dio_SetPinLevel(LCD_PINS_D1, GET_BIT(data, 1));
    Dio_SetPinLevel(LCD_PINS_D2, GET_BIT(data, 2));
    Dio_SetPinLevel(LCD_PINS_D3, GET_BIT(data, 3));
    Dio_SetPinLevel(LCD_PINS_D4, GET_BIT(data, 4));
    Dio_SetPinLevel(LCD_PINS_D5, GET_BIT(data, 5));
    Dio_SetPinLevel(LCD_PINS_D6, GET_BIT(data, 6));
    Dio_SetPinLevel(LCD_PINS_D7, GET_BIT(data, 7));

    // Enable the LCD to receive the command.
    Dio_SetPinLevel(LCD_PINS_EN, STD_HIGH);
    // Wait for changes.
    _delay_ms(2);
    // Disable the LCD from further changes.
    Dio_SetPinLevel(LCD_PINS_EN, STD_LOW);
}

void LCD_Init(void)
{
    _delay_ms(40);
    // Function Set
    // 8-bit mode for interfacing - 2 line - 5x8 font.
    LCD_SendCommand(0b00111000);
    // Display ON/OFF Control, Cursor Blink OFF
    // and locating the cursor at the beginning of the first line.
    LCD_SendCommand(0b00001100);
    // Clear Display
    LCD_SendCommand(0x01);
}

void LCD_InitPins(void)
{
	Dio_SetPinMode(LCD_PINS_EN, DIO_PIN_OUTPUT);
	Dio_SetPinMode(LCD_PINS_RS, DIO_PIN_OUTPUT);
	Dio_SetPinMode(LCD_PINS_RW, DIO_PIN_OUTPUT);

	Dio_SetPinMode(LCD_PINS_D0, DIO_PIN_OUTPUT);
	Dio_SetPinMode(LCD_PINS_D1, DIO_PIN_OUTPUT);
	Dio_SetPinMode(LCD_PINS_D2, DIO_PIN_OUTPUT);
	Dio_SetPinMode(LCD_PINS_D3, DIO_PIN_OUTPUT);
	Dio_SetPinMode(LCD_PINS_D4, DIO_PIN_OUTPUT);
	Dio_SetPinMode(LCD_PINS_D5, DIO_PIN_OUTPUT);
	Dio_SetPinMode(LCD_PINS_D6, DIO_PIN_OUTPUT);
	Dio_SetPinMode(LCD_PINS_D7, DIO_PIN_OUTPUT);

}


void LCD_SendString(const u8 *str)
{
    u8 i = 0;
    while (str[i] != '\0')
    {
        LCD_SendData(str[i]);
        i++;
    }
}

void LCD_CursorPosition(u8 row, u8 col)
{
    u8 localAddress = 0;
    if (row == 1)
    {
        localAddress = col;
    }
    else if (row == 2)
    {
        localAddress = 0x40 + col;
    }
    else
    {
        // Do nothing.
    }
    LCD_SendCommand(localAddress);
}
