/*****************************************************************
*
* File Name: Smart_Home_Slave.c
*
* Date Created: 22/10/2020
* 
* Author : Ahmed LNiwehy
*
*******************************************************************/

#include <avr/io.h>
#include "SPI.h"
#include "LCD.h"
#include "DIO.h"
#include "ADC.h"
#include "SSegments.h"

int main(void)
{
	LCD_Init();
	SPI_Init('S');
	ADC_Init();
	SSEG_Init();
	
	DDRC |= (1<<5) | (1<<6) | (1<<7);    
	DDRB |= (1<<0) | (1<<1);
	
	TCCR0 |=(1<<WGM00)|(1<<CS00)|(1<<CS01)|(1<<COM01);    //phase correct mode, non-inverting, N=64
	
	unsigned char motorFlag=0, slaveRequest, count=0;
	unsigned short tempValue;
	
	while (1)
	{
		slaveRequest = SPI_Receive();
		
		switch(slaveRequest)
		{
			case '1':
			PORTC |= (1<<5);
			break;
			case '2':
			PORTC &=~ (1<<5);
			break;
			case '3':
			PORTC |= (1<<6);
			break;
			case '4':
			PORTC &=~ (1<<6);
			break;
			case '5':
			PORTC |= (1<<7);
			break;
			case '6':
			PORTC &=~ (1<<7);
			break;
			case '7':
			while(slaveRequest == '7')
			{
	             tempValue = ADC_Read(3);
	             tempValue /= 4;
	             SSEG_display(tempValue);
			}
			break;
			case 's':
			OCR0 = 0;
			PORTB |= (1<<1);
			PORTB &=~ (1<<0);
			LCD_Clear();
			LCD_Gotoxy(1,1);
			LCD_DisplayString(" Speed = 0");
			motorFlag = 1;
			count = 0;
			break;
			case 'e':
			OCR0 = 0;
			PORTB &=~ (1<<0);
			PORTB &=~ (1<<1);
			motorFlag = 0;
			count = 0;
			break;
			case '+':
			if(motorFlag == 0)
			{
				LCD_Clear();
				LCD_Gotoxy(1,1);
				LCD_DisplayString(" Turn ON motor!!");
			}
			else
			{
				count++;
				switch(count)
				{
					case 1:
					OCR0 = 63;
					LCD_Clear();
					LCD_Gotoxy(1,1);
					LCD_DisplayString(" Speed x25");
					break;
					case 2:
					OCR0 = 127;
					LCD_Clear();
					LCD_Gotoxy(1,1);
					LCD_DisplayString(" Speed x50");
					break;
					case 3:
					OCR0 = 191;
					LCD_Clear();
					LCD_Gotoxy(1,1);
					LCD_DisplayString(" Speed x75");
					break;
					case 4:
					OCR0 = 255;
					LCD_Clear();
					LCD_Gotoxy(1,1);
					LCD_DisplayString(" Speed x100");
					break;
				}
				if (count>4)
				{
					count=4;
				}
				break;
				case '-':
				if(motorFlag == 0)
				{
					LCD_Clear();
					LCD_Gotoxy(1,1);
					LCD_DisplayString(" Turn ON motor!!");
				}
				else
				{
					count--;
					switch(count)
					{
						case 0:
						OCR0 = 0;
						LCD_Clear();
						LCD_Gotoxy(1,1);
						LCD_DisplayString(" Speed = 0");
						break;
						case 1:
						OCR0 = 63;
						LCD_Clear();
						LCD_Gotoxy(1,1);
						LCD_DisplayString(" Speed x25");
						break;
						case 2:
						OCR0 = 127;
						LCD_Clear();
						LCD_Gotoxy(1,1);
						LCD_DisplayString(" Speed x50");
						break;
						case 3:
						OCR0 = 191;
						LCD_Clear();
						LCD_Gotoxy(1,1);
						LCD_DisplayString(" Speed x75");
						break;
						case 4:
						OCR0 = 255;
						LCD_Clear();
						LCD_Gotoxy(1,1);
						LCD_DisplayString(" Speed x100");
						break;
					}
					if (count<0)
					{
						count=0;
					}
					break;
			}
		}
	}
}
}
