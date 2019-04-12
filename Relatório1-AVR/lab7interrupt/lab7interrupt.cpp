/*
 * lab7interrupt.cpp
 *
 *  Created on: 12/04/2019
 *      Author: aluno
 */




#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>
#include <stdio.h>


//pino digital 9, PH6
//pino digital 2, PE4

int debounce(){

	_delay_ms(300); //metodo para debounce


	if(PINE & (1<<4)) {
		return 1;
	} else {
		return 0;
	}

}

ISR(INT4_vect) //interrupção externa 0, quando o botão é pressionado o LED troca de estado
{
	if(debounce() == 1){
		if(PINH & (1<<6)) {
		PORTH &= ~(1<<PH6);
		} else {
			PORTH |= (1<<PH6);
		}
	}
}

int main() {

	 DDRE = 0x00; //PORTD entrada
	 PORTE = 0xFF; //pull-ups habilitados
	 DDRH = (1<<6); //somente pino do LED como saída
	 PORTH = 0b11011111; //desliga LED e habilita pull-ups
	 UCSR0B = 0x00; /*necessário desabilitar RX e TX para trabalho com os pinos
	 do PORTD no Arduino*/
	 EICRA = 1<<ISC00;//interrupção em qualquer borda
	 EIMSK = (1<<INT4);//habilita interrupção no D2
	 sei(); //habilita interrupções globais, ativando o bit I do SREG

	 while(1){}
}


