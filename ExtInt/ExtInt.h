/*
 * ExtInt.h
 *
 *  Created on: 03/05/2019
 *      Author: aluno
 */

#ifndef EXTINT_H_
#define EXTINT_H_
#include <avr/io.h>
#include <avr/interrupt.h>

class ExtInt {
public:

	enum INT_ID_t {
		INT_0 = 0,
		INT_1 = 1,
		INT_2 = 2,
		INT_3 = 3,
		INT_4 = 4,
		INT_5 = 5,
		INT_6 = 6,
		INT_7 = 7

	};

	enum ISC_t {
		LOW_LEVEL = 0,
		ANY_EDGE = 1,
		FALLING = 2,
		RISING = 3

	};




	//msk = ((id%4) << 1)

	//EICRA = (EICRA&~(3<<msk))) | (cfg << msk);

	//EICRB = (EICRB&~(3<<msk)) | (cfg<<msk);

	ExtInt(ExtInt::INT_ID_t id,  );



private:


};

#endif /* EXTINT_H_ */
