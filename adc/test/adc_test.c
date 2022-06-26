/**
 * \brief Simple test to verify the ADC feature
 *
 * \file adc_test.c
 * \author Alberto Tejada
 */

#include "adc.h"
#include "uart.h"
#include <util/delay.h>

/**
 * \brief ADC on target test:
 * This is the simplest way to verify that the ADC is
 * correctly configured on target.
 * In order to execute this test, a potentiometer must be
 * connected to the ADC pin of the board and the UART
 * connection with the test machine must be enabled.
 * The expected result is the test machine receives through
 * the UART the ADC value as a 10 bit integer
 */

void to_str(uint16_t data, char* result);

int main(void){
	uint16_t data;
	char result[] = "0000 0\n";
	uint8_t len = 7;

	adc_init();
	uart_init();

	while(1){
		data = read_angle();
		to_str(data, result);
		// Update the counter:
		result[5]++;
		if(result[5] > '9')
		{
			result[5] = '0';
		}
		for(uint8_t idx = 0; idx < len; idx++)
		{
			uart_tx(result[idx]);
		}
		_delay_ms(200);
	}
	return 0;
}

void to_str(uint16_t data, char *result){
	uint8_t mills = data / 1000;
	uint8_t cents = (data / 100) - 10 * mills;
	uint8_t decns = (data / 10) - 10 * (cents + 10 * mills); 
	uint8_t units = data - 10 * (data / 10);
	result[0] = mills + '0';
	result[1] = cents + '0';
	result[2] = decns + '0';
	result[3] = units + '0';
}
	
