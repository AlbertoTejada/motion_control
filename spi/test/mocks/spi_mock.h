#pragma once

#ifndef SPI_MOCK_H
#define SPI_MOCK_H

#include <stdint.h>
#include "gmock/gmock.h"

class SpiMock{
public:
	virtual ~SpiMock(){}

	//Mock methods
	MOCK_METHOD(void, spi_init, ());
	
	MOCK_METHOD(uint8_t, spi_transfer, (uint8_t data));
};

#endif // SPI_MOCK_H
