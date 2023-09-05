/*
 * Lcd.h
 *
 *  Created on: Aug 25, 2023
 *      Author: Acer
 */

#ifndef LCD_H_
#define LCD_H_

typedef unsigned char u8;

/* LCD Control Pins Defining */
#define LCD_PINS_RS DIO_PORTC,DIO_PIN5
#define LCD_PINS_RW DIO_PORTC,DIO_PIN6
#define LCD_PINS_EN DIO_PORTC,DIO_PIN7

/* LCD Data Pins Defining */
#define LCD_PINS_D0 DIO_PORTD,DIO_PIN0
#define LCD_PINS_D1 DIO_PORTD,DIO_PIN1
#define LCD_PINS_D2 DIO_PORTD,DIO_PIN2
#define LCD_PINS_D3 DIO_PORTD,DIO_PIN3
#define LCD_PINS_D4 DIO_PORTD,DIO_PIN4
#define LCD_PINS_D5 DIO_PORTD,DIO_PIN5
#define LCD_PINS_D6 DIO_PORTD,DIO_PIN6
#define LCD_PINS_D7 DIO_PORTD,DIO_PIN7


// LCD Initiate Pins Used
void LCD_InitPins();


/* LCD Commands Functions */

void LCD_Init(void);


// Clear the LCD
void LCD_SendCommand(u8 command);

// Send a character to be displayed on the LCD
void LCD_SendData(u8 data);

// Send a string to be displayed on the LCD
void LCD_SendString(const u8 *str);

// Set the starting point of the cursor
void LCD_CursorPosition(u8 row,u8 col);

#endif /* LCD_H_ */
