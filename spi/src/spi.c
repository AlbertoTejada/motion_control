#include "spi.h"
#include "board.h"

void spi_init(void) {
	// Set the SPI pin direntions:
	SPI_CLK_DIR |= (OUTPUT << SPI_CLK);
	SPI_MOSI_DIR |= (OUTPUT << SPI_MOSI);
	SPI_MISO_DIR &= ~(OUTPUT << SPI_MISO);
	// Set the SPI configuration:
	SPI_CTRL = (SPI_ENABLE +\
							MSBFIRST +\
							SPI_MASTER +\
							SPI_MODE0);
	SPI_STAT = SPI_SPEED;
}

uint8_t spi_transfer(uint8_t data) {
	SPI_DATA = data;

	while(!(SPI_STAT & SPI_COMPLETE));

	return SPI_DATA;
}

