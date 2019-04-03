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
		_port = 'E';
		setMode(dir);
	break;
	case 3: //PE5
		_id = id;
		_bit = 5;
		_port = 'E';
		setMode(dir);
	break;
	case 4: //PG5
		_id = id;
		_bit = 5;
		_port = 'G';
		setMode(dir);
	break;
	case 5: //PE3
		_id = id;
		_bit = 3;
		_port = 'E';
		setMode(dir);
	break;
	case 6: //PH3
		_id = id;
		_bit = 3;
		_port = 'H';
		setMode(dir);
	break;
	case 7: //PH4
		_id = id;
		_bit = 4;
		_port = 'H';
		setMode(dir);
	break;
	case 8: //PH5
		_id = id;
		_bit = 5;
		_port = 'H';
		setMode(dir);
	break;
	case 9: //PH6
		_id = id;
		_bit = 6;
		_port = 'H';
		setMode(dir);
	break;

	}

}

void GPIO::setMode(PortDirection_t dir) {
	if (dir == 1) {


	}


}




