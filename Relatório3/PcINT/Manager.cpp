/*
 * Manager.cpp
 *
 *  Created on: 31/05/2019
 *      Author: aluno
 */

#include <stdio.h>
#include <avr/interrupt.h>
#include "Manager.h"
#include <avr/io.h>
#include <util/delay.h>

PcINT Manager::_PcINT_vect[24];


Manager::Manager(){
	UCSR0B = 0;
	PCICR |= 1<<PCIE0;
	PCICR |= 1<<PCIE1;
	PCICR |= 1<<PCIE2;
	for (int i = 0; i < 24; i++){
		PcINT p;
		_PcINT_vect[i] = p;
		_PcINT_vect[i].setEvent(false);

	}
}

void Manager::addPcINT(PcINT::PcINT_ID_t id, CALLBACK_t callback){
	_PcINT_vect[id].setCallback(callback);
	_PcINT_vect[id].enable(id);
}

void Manager::disable(PcINT::PcINT_ID_t id){
	_PcINT_vect[id].disable(id);
}


void Manager::enable(PcINT::PcINT_ID_t id){
	_PcINT_vect[id].enable(id);
}

void Manager::checkEvents(){
	for (int i = 0; i < 24; i++){
		if (_PcINT_vect[i].event()){
			_PcINT_vect[i].callback();
			_PcINT_vect[i].setEvent(false);
		}
	}
}

ISR(PcINT0_vect)
{
	int i = 0;
	while(i < 8) {
		if(Manager::_PcINT_vect[i].isEnabled()) {
			if(PINB & (1 << i)){
				Manager::_PcINT_vect[i].setEvent(true);
			}
		}
		i++;
	}

	_delay_ms(100);
}

ISR(PcINT1_vect)
{

	if(Manager::_PcINT_vect[8].isEnabled()){
			if (PINE & (1 << 0)){
				Manager::_PcINT_vect[8].setEvent(true);
			}
	}

	int i = 9;
	int j = 0;
	while(i < 16) {
		if (Manager::_PcINT_vect[i].isEnabled()){
				if (PINJ & (1 << j)){
					Manager::_PcINT_vect[i].setEvent(true);
				}
		}

		i++;
		j++;
	}

	_delay_ms(100);
}


ISR(PcINT2_vect)
{
	int i = 16;
	int j = 0;
	while(i < 24) {
		if(Manager::_PcINT_vect[i].isEnabled()){
				if (PINK & (1 << j)){
					Manager::_PcINT_vect[i].setEvent(true);
				}
		}
	}
}


