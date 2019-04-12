#include <avr/io.h>
#include <util/delay.h>

int main(){
	DDRB |= (1<<7);

	while(true) {
		if(PINB & (1<<6)) {
			PORTB |= (1<<7);
		} else {
			PORTB &= ~(1<<7);
		}
	}
	return 1;
}


