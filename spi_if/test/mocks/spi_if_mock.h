#pragma once

#ifndef SPI_IF_MOCK_H
#define SPI_IF_MOCK_H

#include <stdint.h>
#include "gmock/gmock.h"

class SpiIfMock{
public:
	virtual ~SpiIfMock(){}

	//Mock methods
	MOCK_METHOD(void, spi_init, ());
	
	MOCK_METHOD(uint8_t, spi_transfer, (uint8_t data));

	MOCK_METHOD(void, spi_start, ());

	MOCK_METHOD(void, spi_stop, ());
};

#endif // SPI_IF_MOCK_H
