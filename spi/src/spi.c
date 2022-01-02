#include "spi.h"
#include "board.h"

void spi_init(void) {
	// Set the SPI pin direntions:
	SPI_CLK_DIR |= (OUTPUT << SPI_CLK);
	SPI_MOSI_DIR |= (OUTPUT << SPI_MOSI);
	SPI_MISO_DIR &= ~(OUTPUT << SPI_MISO);
	// Set SCK and MOSI in LOW state:
	SPI_CLK_PORT &= ~(1 << SPI_CLK);
	SPI_MOSI_PORT &= ~(1 << SPI_MOSI);
	// Set the SPI configuration:
	SPI_CTRL = (SPI_ENABLE +\
							MSBFIRST +\
							SPI_MASTER +\
							SPI_MODE0);
	SPI_STAT = SPI_SPEED;
	// For IT, set SPR0 bit to 1, so SPI speed is fosc/8
	/* SPI_CTRL |= (1); */
}

uint8_t spi_transfer(uint8_t data) {
	SPI_DATA = data;

	while(!(SPI_STAT & SPI_COMPLETE));

	return SPI_DATA;
}

