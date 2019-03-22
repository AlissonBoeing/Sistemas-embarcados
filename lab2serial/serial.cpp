/*
 * serial.cpp
 *
 *  Created on: 20/03/2019
 *      Author: aluno
 */

#include <avr/io.h>
#include <util/delay.h>

#define FOSC 16000000// Clock Speed
#define BAUD 9600
#define MYUBRR (FOSC/16/BAUD-1)

void USART_Init( unsigned int ubrr){

/* Set baud rate */
UBRR0H = (unsigned char)(103>>8);
UBRR0L = (unsigned char)103;
//UBRR0 = 103;
/* Enable receiver and transmitter */
UCSR0B = (1<<RXEN0)|(1<<TXEN0);
/* Set frame format: 8data, 2stop bit */
UCSR0C = (1<<USBS0)|(3<<UCSZ01);

} // USART_Init


unsigned char USART_Receive( void ) {
	/* Wait for data to be received */
	while ( !(UCSR0A & (1<<RXC0)))

		;
	/* Get and return received data from buffer */
	return UDR0;
	}


void
 USART_Transmit( unsigned char data )
{
/*
Wait for empty transmit buffer
 */
while ( !( UCSR0A & (1<<UDRE0)) )

	;
/*
Put data into buffer, sends the data
 */
UDR0 = data;
}


int main() {


  USART_Init( MYUBRR );


  while (true) {
  USART_Transmit(0x30);
  _delay_ms(500);
  }



}




