
#include <avr/interrupt.h>
#include <util/delay.h>
#include "GPIO.h"

GPIO led1(7, GPIO::OUTPUT);


int main(void){

	while (1){
		led1.toggle();
		_delay_ms(1000);
	}

}





//TESTE EXT_INT
//#include "uart.h"
//#include <avr/interrupt.h>

//#include "extint.h"
//using namespace EXT_INT;

//UART uart(19200, UART::DATABITS_8, UART::PARITY_NONE, UART::STOPBITS_1);
//
//void int0_handler(void){
//	uart.put('0');
//	return;
//}
//
//void int1_handler(void){
//	uart.put('1');
//	return;
//}
//
//int main( void ){
//	ExtInt int0_obj(ExtInt::INT_0, ExtInt::FALLING, &int0_handler);
//	ExtInt int1_obj(ExtInt::INT_1, ExtInt::FALLING, &int1_handler);
//
//	int0_obj.enable();
//	int1_obj.enable();
//
//	sei();
//	while(1){                                   /* forever */
//		if (uart.has_data())
//		uart.put(uart.get());                 /* echo the received character */
//	}
//
//	return 0;
//}
