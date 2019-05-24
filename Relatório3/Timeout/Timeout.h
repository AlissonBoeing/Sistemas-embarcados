/*
 * Timeout.h
 *
 *  Created on: 10/05/2019
 *      Author: aluno
 */

#ifndef TIMEOUT_H_
#define TIMEOUT_H_
#include <avr/io.h>
#include <avr/interrupt.h>


typedef void (*CALLBACK_t)(void);

class Timeout {
	public:
		Timeout();
		void callback(){(*_pCallback)();}
		uint32_t _interval;
		void checkTimeout();
		void config(uint32_t interval, CALLBACK_t callback);
		void e_event();
		bool is_event();
		void d_event();
	private:
		bool _event;
		bool _enable;
		uint32_t _counter;
		CALLBACK_t _pCallback;
};


#endif /* TIMEOUT_H_ */
