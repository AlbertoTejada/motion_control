/**
 * \brief Simple test to verify the Counter feature 
 *
 * \file cnt_test.c
 * \author Alberto Tejada
 */

#include "cnt.h"
#include "uart.h"
#include <util/delay.h>

/**
 * \brief Counter pin test:
 * This is the simplest way to verify that the counter
 * pin is actually working.
 * In order to execute this test on target, a pulse generator
 * must be connected to the counter pin and the UART 
 * communication must be enabled with the test machine.
 * The expted result is tha the test machine receives through
 * UART the number up pulses detected on the counter pin plus
 * a message number as a separate one byte counter
 */

void to_str(uint8_t data, char* result);

int main(void){
	char result[] = "000 0\n";
	uint8_t len = 6;
	uint8_t pulses = 0;
	cnt_init();
	uart_init();

	while(1){
		pulses = read_cnt();	
		to_str(pulses, result);
		// Update the counter:
		result[4]++;
		if(result[4] > '9')
		{
			result[4] = '0';
		}
		for(uint8_t idx = 0; idx < len; idx++)
		{
			uart_tx(result[idx]);
		}
		_delay_ms(200);
	}
	return 0;
}

void to_str(uint8_t data, char *result){
	uint8_t cents = (data / 100);
	uint8_t decns = (data / 10) - 10 * cents; 
	uint8_t units = data - 10 * (data / 10);
	result[0] = cents + '0';
	result[1] = decns + '0';
	result[2] = units + '0';
}
