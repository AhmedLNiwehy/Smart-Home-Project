/**************************************************************
*
* File Name: SPI.h
*
* Date Created: 03/10/2020
*
* Author: Ahmed LNiwehy
*
****************************************************************/


#ifndef SPI_H_
#define SPI_H_

#include <avr/io.h>

#define SPI_PORT  PORTB
#define SPI_DDR   DDRB

#define SS    4
#define MOSI  5
#define MISO  6
#define SCK   7

#define SLAVE_EN()        (SPI_PORT &=~ (1<<SS))
#define SLAVE_DISEN()     (SPI_PORT |= (1<<SS))

void SPI_Init(unsigned char status);
unsigned char SPI_TxRx(unsigned char data);	
void SPI_Write(char data);


#endif /* SPI_H_ */