#include <avr/io.h>
#include <avr/interrupt.h>
#include "GPIO.h"
#include "Timer.h"

GPIO pino_9(9, GPIO::OUTPUT);

void timeout_handler(void){
	pino_9.toggle();
}

Timer tempo = Timer(1000);

int main(){

	sei();
	tempo.addTimeout(1000, &timeout_handler);
	while(true){
		tempo.delay(1000);
		pino_9.toggle();

		//t.timeoutManager();
}
}



