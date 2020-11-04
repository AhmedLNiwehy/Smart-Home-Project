/**************************************************************
*
* File Name: UART.c
*
* Date Created: 02/10/2020
*
* Author: Ahmed LNiwehy
*
****************************************************************/


#include "UART.h"

void Uart_Init()
{
	UCSRB |= (1<<RXEN) | (1<<TXEN);    //Enable TX & RX
	UCSRC |= (1<<URSEL) | (1<<UCSZ0) | (1<<UCSZ1);
	UBRRL = MYUBRR;
	UBRRH = (MYUBRR>>8);
}

void Uart_Send(unsigned char data)
{
	while(!(UCSRA & (1<<UDRE)));
	UDR = data;	
}

unsigned char Uart_Receive()
{
	while(!(UCSRA & (1<<RXC)));
	return UDR;
}

void Uart_SendString(char * string)
{
	unsigned char i = 0;
	while(string[i] != '\0')
	{
		Uart_Send(string[i]);
		i++;
	}
}