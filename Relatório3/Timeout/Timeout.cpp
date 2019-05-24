/*
 * Timeout.cpp
 *
 *  Created on: 10/05/2019
 *      Author: aluno
 */


#include "Timeout.h"
#include <avr/io.h>
#include <avr/interrupt.h>

Timeout::Timeout() {
//vazio
}

void Timeout::checkTimeout(){
	if(_counter == _interval) {
		_counter = 0;
		_event = true;

	} else {
		_counter = _counter + 1;
		_event = false;
	}

}
void Timeout::config(uint32_t interval, CALLBACK_t callback) {
	_interval = interval;
	_pCallback = callback;
	_enable = true;
	_event = false;

}

void Timeout::e_event(){
	_event = true;
}
bool Timeout::is_event() {
	return _event;
}
void Timeout::d_event(){
	_event = false;

}

