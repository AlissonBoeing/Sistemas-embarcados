/*
 * GPIO.cpp
 *
 *  Created on: 03/04/2019
 *      Author: aluno
 */

#include "GPIO.h"


GPIO::GPIO(uint8_t id,  PortDirection_t dir ){

	switch (id) {
	case 2: //PE4
		_id = id;
		_bit = 4;
		_port = &PORTE;
		_pin = &PINE;
		_ddr = &DDRE;
		this->setMode(dir);

	break;
	case 3: //PE5
		_id = id;
		_bit = 5;
		_port = &PORTE;
		_pin = &PINE;
		_ddr = &DDRE;
	break;
	case 4: //PG5
		_id = id;
		_bit = 5;
		_port = &PORTG;
		_pin = &PING;
		_ddr = &DDRG;
	break;
	case 5: //PE3
		_id = id;
		_bit = 3;
		_port = &PORTE;
		_pin = &PINE;
		_ddr = &DDRE;
	break;
	case 6: //PH3
		_id = id;
		_bit = 3;
		_port = &PORTH;
		_pin = &PINH;
		_ddr = &DDRH;
	break;
	case 7: //PH4
		_id = id;
		_bit = 4;
		_port = &PORTH;
		_pin = &PINH;
		_ddr = &DDRH;
	break;
	case 8: //PH5
		_id = id;
		_bit = 5;
		_port = &PORTH;
		_pin = &PINH;
		_ddr = &DDRH;

	break;
	case 9: //PH6
		_id = id;
		_bit = 6;
		_port = &PORTH;
		_pin = &PINH;
		_ddr = &DDRH;

	break;

	}

}

void GPIO::setMode(PortDirection_t dir) {

	if(dir) _ddr |= (1<<_bit);
	else _ddr &= ~(1<<_bit);

}


bool GPIO::read(){



}
void GPIO::write(bool val) {

}






