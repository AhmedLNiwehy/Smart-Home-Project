/**************************************************************
*
* File Name: Smart_Home_Master.c
*
* Date Created: 21/10/2020
*
* Author: Ahmed LNiwehy
*
****************************************************************/


#include <avr/io.h>
#include "UART.h"
#include "SPI.h"
#include "LCD.h"


int main(void)
{
	LCD_Init();
	SPI_Init('M');
	SLAVE_EN();
	Uart_Init();
	
	LCD_Gotoxy(1,1);
	LCD_DisplayString("Ahmed Mahmoud ");
	LCD_Gotoxy(1,2);
	LCD_DisplayString("Smart Home Project");
	
	while (1)
	{
		switch(Uart_Receive())
		{
			case '1':
			SPI_Write('1');
			LCD_Command(CLEAR);
			LCD_Gotoxy(2,1);
			LCD_DisplayString(" ROOM1 IS ON");
			break;
			case '2':
			SPI_Write('2');
			LCD_Gotoxy(2,1);
			LCD_Command(CLEAR);
			LCD_DisplayString(" ROOM1 IS OFF");
			break;
			case '3':
			SPI_Write('3');
			LCD_Gotoxy(2,1);
			LCD_Command(CLEAR);
			LCD_DisplayString(" ROOM2 IS ON");
			break;
			case '4':
			SPI_Write('4');
			LCD_Gotoxy(2,1);
			LCD_Command(CLEAR);
			LCD_DisplayString(" ROOM2 IS OFF");
			break;
			case '5':
			SPI_TxRx('5');
			LCD_Gotoxy(2,1);
			LCD_Command(CLEAR);
			LCD_DisplayString(" ROOM3 IS ON");
			break;
			case '6':
			SPI_Write('6');
			LCD_Gotoxy(2,1);
			LCD_Command(CLEAR);
			LCD_DisplayString(" ROOM3 IS OFF");
			break;
			case '7':
			SPI_Write('7');
			LCD_Gotoxy(2,1);
			LCD_Command(CLEAR);
			LCD_DisplayString(" Receiving Temperature: ");
			break;
			
			case 's':
			SPI_Write('s');
			LCD_Gotoxy(2,1);
			LCD_Command(CLEAR);
			LCD_DisplayString(" Motor is ON ");
			break;
			case 'e':
			SPI_Write('e');
			LCD_Gotoxy(2,1);
			LCD_Command(CLEAR);
			LCD_DisplayString(" Motor is OFF ");
			break;
			case '+':
			SPI_Write('+');
			break;
			case '-':
			SPI_Write('-');
			break;
		}
	}
}

