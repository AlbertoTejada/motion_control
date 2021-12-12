/**
 * \brief Simple test to verify the SPI communication
 *
 * \file spi_test.c
 * \author Alberto Tejada
 */

#include "spi.h"
#include <util/delay.h>

int main(void) {

	uint8_t output = 0;
	spi_init();
	_delay_ms(1000);

	while(1)
	{
		spi_transfer(output);
		output++;
		_delay_ms(200);
	}
	return 0;
}
