/**
 * \brief Simple test to verify the SPI communication
 *
 * \file spi_test.c
 * \author Alberto Tejada
 */

#include "spi.h"
#include "gpio.h"
#include <util/delay.h>

/**
 * \brief SPI Master on target test:
 * This is a simple test to verify the behaviour of the SPI
 * communication.
 * In order to execute this test, an aditional uC is
 * required as SPI slave with the following set up:
 * 1) Connect master-slave MISO (PB4), MOSI(PB3), SPI Clock
 *    (PB5) and CAN_DRV_CS (PB2).
 * 2) Assuming an Arduino board in the slave side, flash the
 *    code for the SPI slve of this post:
 *    https://forum.arduino.cc/t/arduino-as-spi-slave/52206/2
 * 3) As the test is expecting slave-master communication,
 *    modify the slave code to load a character in the
 *    SPDR register.
 * 4) Verify that both uC share a common GND and Vss to
 *    avoid damage them.
 * 5) Connect the UART to the slave and verify that the
 *    message `Hello World! X` is printed, where `X` is the
 *    character that sent by the slave.
 * 
 * \note
 * If the slave board is an ATmega328p, the SPI Clock speed
 * shall be set to fosc/8 instead of fosc/2
 */

#ifdef AVR_SIM
	#include "../../avr_mcu_section.h"
	AVR_MCU(F_CPU, "atmega328p");
#endif

int main(void) {

	char test[] = "Hello World! 0\n";
	uint8_t idx = 0;
	uint8_t len = 15;
	uint8_t input = 0; 
	gpio_init();
	can_drv_deselect();
	spi_init();
	_delay_ms(1000);

	while(1)
	{
		can_drv_select();
		input = spi_transfer(test[idx]);
		can_drv_deselect();
		idx++;
		if(idx == len)
		{
			idx = 0;
			test[13] = input;
		}
		_delay_ms(200);
	}
	return 0;
}
