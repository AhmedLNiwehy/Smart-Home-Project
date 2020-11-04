/**************************************************************
*
* File Name: SPI.c
*
* Date Created: 03/10/2020
*
* Author: Ahmed LNiwehy
*
****************************************************************/


#include "SPI.h"

void SPI_Init(unsigned char status)
{
	switch(status)
	{
		case 'M':
		SPI_DDR |= (1<<MOSI) | (1<<SCK) | (1<<SS);	
		SPI_DDR &=~ (1<<MISO);
		SPCR |= (1<<MSTR) | (1<<SPE);
		SLAVE_DISEN();
		break;
		
		case 'S':
		SPI_DDR &=~ (1<<MOSI) | (1<<SCK) | (1<<SS);
		SPI_DDR |= (1<<MISO);
		SPCR |= (1<<SPE);
		break;
	}
	
}
unsigned char SPI_TxRx(unsigned char data)
{
	SPDR = data;
	while(!(SPSR & (1<<SPIF)));   //waiting for reading data
	return SPDR;	
}

void SPI_Write(char data)		/* SPI write data function */
{
	char flush_buffer;
	SPDR = data;			    /* Write data to SPI data register */
	while(!(SPSR & (1<<SPIF)));	/* Wait till transmission complete */
	flush_buffer = SPDR;		/* Flush received data */
	/* Note: SPIF flag is cleared by first reading SPSR (with SPIF set) and then accessing SPDR hence flush buffer used here to access SPDR after SPSR read */
}