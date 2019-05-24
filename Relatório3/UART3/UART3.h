
#include <avr/io.h>
#include <avr/interrupt.h>
#ifndef UART3_H_
#define UART3_H_


class UART3 {
public:

	enum DATABITS_t {
		DATABITS_5 = 0,
		DATABITS_6 = 2,
		DATABITS_7 = 4,
		DATABITS_8 = 6
	};

	enum PARITY_t {
			NONE = 0,
			EVEN = 32,
			ODD = 48
		};

	enum STOPBITS_t {
			STOPBIT_1 = 0,
			STOPBIT_2 = 8
		};

	UART3(uint32_t baud, UART3::DATABITS_t db, UART3::PARITY_t parity, UART3::STOPBITS_t sb);
	~UART3();
	void put(uint8_t data);
	void puts(const char * data);
	uint8_t get();
	bool has_data();
	static void rxc_isr_handler();
	static void tx_isr_handler();

private:

	static bool _has_data;
	static uint8_t _rx_buffer;
	static uint8_t _tx_buffer;

};


#endif /* UART3_H_ */
