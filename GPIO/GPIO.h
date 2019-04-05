/*
 * GPIO.h
 *
 *  Created on: 03/04/2019
 *      Author: aluno
 */

#include <avr/io.h>
#include <util/delay.h>
#ifndef GPIO_H_
#define GPIO_H_


class GPIO {

	public:
		enum PortDirection_t {
			INPUT = 0,
			OUTPUT=1
		};

		GPIO(uint8_t id, PortDirection_t dir);
		~GPIO();

		bool read();
		void write(bool val);
		void toggle();
		void setMode(PortDirection_t dir);
	private:
		uint8_t _id;
		uint8_t _bit;
		volatile uint8_t * _port;
		volatile uint8_t * _ddr;
		volatile uint8_t *_pin;

};


#endif /* GPIO_H_ */
