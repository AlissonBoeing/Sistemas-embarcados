/*
 * serial.cpp
 *
 *  Created on: 20/03/2019
 *      Author: aluno
 */

#include <avr/io.h>

#define FOSC 16000000// Clock Speed
#define BAUD 9600


int main() {

	unsigned int MYUBRR;
	MYUBRR = FOSC/(16*(BAUD-1));

	USART_Init( MYUBRR );

}

unsigned char USART_Receive( void ) {
	/* Wait for data to be received */
	while ( !(UCSRnA & (1<<RXCn)));
	/* Get and return received data from buffer */
	return UDRn;
	}

void USART_Init( unsigned int ubrr){

/* Set baud rate */
//UBRRH = (unsigned char)(ubrr>>8);
//UBRRL = (unsigned char)ubrr;
	UBRR0 = ubrr;
/* Enable receiver and transmitter */
UCSRB = (1<<RXEN)|(1<<TXEN);
/* Set frame format: 8data, 2stop bit */
UCSRC = (1<<USBS)|(3<<UCSZ0);

} // USART_Init
