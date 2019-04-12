#include <avr/io.h>
#include <util/delay.h>
#include <stdlib.h>


#define FOSC 16000000// Clock Speed
#define BAUD 9600
#define MYUBRR (FOSC/16/BAUD-1)

uint16_t read_adc(uint8_t channel){

ADMUX = 0x45;   
ADCSRB = channel&(1<<3); 
ADCSRA |= (1<<ADSC);      //Starts a new conversion
while(ADCSRA & (1<<ADSC));  //Wait until the conversion is done
return ADCW;}           //Returns the ADC value of the chosen channel

void adc_init(void){



ADCSRA |= ((1<<ADPS2)|(1<<ADPS1)|(1<<ADPS0));

ADMUX |= (1<<REFS0);       //Set Voltage reference to Avcc (5v)

ADCSRA |= (1<<ADEN);       //Turn on ADC

ADCSRA |= (1<<ADSC);
}     


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


float RMS(int repeat) {

	uint8_t channel = 5;
	int i;
  i = 0;
  float valores[repeat];
  while(i < repeat) {

  uint16_t a = read_adc(channel);

  valores[i] = a;

  i = i + 1;
  }
  i = 0;
 float acumulado = 0;
  while(i<repeat){
    acumulado = acumulado + (valores[i]*valores[i]);
    i = i + 1;
  }
  acumulado = acumulado/repeat;

  return sqrt(acumulado);

}

int main() {

	adc_init();

	USART_Init( MYUBRR );
	char b[5];
	char analogico[15] = "\nAnalogico:\n" ;
	char digital[15] = "\nDigital:\n";
	uint16_t c;
	char d[5];

	while(true) {
		int i = 0;


	  uint16_t a = RMS(30);
	  itoa(a, b, 10);

	  while(analogico[i] != 0){
	  		  USART_Transmit(analogico[i]);
	  		  i++;
	  	  }
	  i = 0;
	  while(b[i] != 0){
		  USART_Transmit(b[i]);
		  i++;
	  }

	  while(digital[i] != 0){
		 USART_Transmit(digital[i]);
		 i++;
	  }
		  i = 0;

		  c = ((5.0*a)/1023.0);

		  itoa(c, d, 10);

		  while(d[i] != 0){
		  		 USART_Transmit(d[i]);
		  		 i++;
		  	  }
 }

}




