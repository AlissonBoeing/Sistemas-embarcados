#include <avr/io.h>
#include <util/delay.h>
#include <stdlib.h>


#define FOSC 16000000// Clock Speed
#define BAUD 9600
#define MYUBRR (FOSC/16/BAUD-1)

//char * 	dtostrf (double __val, signed char __width, unsigned char __prec, char *__s)


uint16_t read_adc(uint8_t channel){
     //Clear bits MUX0-4
ADMUX = 0x45;   //Defines the new ADC channel to be read by setting bits MUX0-2
ADCSRB = channel&(1<<3); //Set MUX5
ADCSRA |= (1<<ADSC);      //Starts a new conversion
while(ADCSRA & (1<<ADSC));  //Wait until the conversion is done
return ADCW;}           //Returns the ADC value of the chosen channel

void adc_init(void){

//16MHz/128 = 125kHz the ADC reference clock

ADCSRA |= ((1<<ADPS2)|(1<<ADPS1)|(1<<ADPS0));

ADMUX |= (1<<REFS0);       //Set Voltage reference to Avcc (5v)

ADCSRA |= (1<<ADEN);       //Turn on ADC

ADCSRA |= (1<<ADSC);
}     //Do an initial conversion


void USART_Init( unsigned int ubrr){
/* Set baud rate */
UBRR0H = (unsigned char)(ubrr>>8);
UBRR0L = (unsigned char)ubrr;
/* Enable receiver and transmitter */
UCSR0B = (1<<RXEN0)|(1<<TXEN0);
/* Set frame format: 8data, 2stop bit */
UCSR0C = (1<<USBS0)|(3<<UCSZ00);
}



unsigned char USART_Receive( void ) {
	/* Wait for data to be received */
	while ( !(UCSR0A & (1<<RXC0)))

		;
	/* Get and return received data from buffer */
	return UDR0;
	}


void USART_Transmit( unsigned char data )
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
	uint8_t channel = 5;
adc_init();
	//unsigned char a;
	USART_Init( MYUBRR );
	char b[5];
int i;
	while(true) {


	  _delay_ms(500);

	  uint16_t a = read_adc(channel);

	  itoa(a, b, 10);

	 // dtostrf(a,3,1,b);
	  i = 0;

	  while(b[i] != 0){
		  USART_Transmit(b[i]);
		  i++;
	  }




 }



}




