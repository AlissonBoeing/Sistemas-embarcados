/*
 * main.cpp
 *
 *  Created on: 17/04/2019
 *      Author: aluno
 */
#include <util/delay.h>
#include "UART3.h"

int main() {

	UART3 uart(9600, UART3::DATABITS_8, UART3::NONE, UART3::STOPBIT_2);

	sei();

	int i = 0;

	while(true) {
		if(uart.has_data()) {
			uart.put(uart.get());
		}
		_delay_ms(500);
		i++;

	}



}
