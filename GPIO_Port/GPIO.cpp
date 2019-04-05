/*
 * GPIO.cpp
 *
 *  Created on: 22 de mar de 2017
 *      Author: aluno
 */

#include "GPIO.h"

GPIO::GPIO(int pin, PortDirection_t dir)
: _pin(pin)
{
	if(_pin < 8) {
			_port = GPIO_PORT::PD;
		}
		else if(pin > 13) {
			_port = GPIO_PORT::PC;
			_pin -= 14;
		}
		else {
			_port = GPIO_PORT::PB;
			_pin -= 8;
		}

	_port->dir(_pin, dir);
}

GPIO::~GPIO() {}

bool GPIO::get() {
	return _port->get(_pin);
}

void GPIO::set(bool val) {
	_port->set(_pin, val);
}

void GPIO::clear() {
	this->set(0);
}

void GPIO::toggle() {
	_port->toggle(_pin);
}

