/**************************************************************
*
* File Name: UART.h
*
* Date Created: 02/10/2020
*
* Author: Ahmed LNiwehy
*
****************************************************************/


#ifndef UART_H_
#define UART_H_

#include <avr/io.h>
#define F_CPU 16000000UL

#define BAUDRATE 9600

#define MYUBRR ((F_CPU / (16UL * BAUDRATE)) -1)


void Uart_Init();
void Uart_Send(unsigned char data);
unsigned char Uart_Receive();
void Uart_SendString(char * string);

#endif /* UART_H_ */