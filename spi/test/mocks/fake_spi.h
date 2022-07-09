#pragma once

#ifndef FAKE_SPI_H
#define FAKE_SPI_H

#include <memory.h>
#include "gtest/gtest.h"
#include "spi_mock.h"

class FakeSpi: virtual public ::testing::Test{
public:
	FakeSpi(){
		_spi.reset(new ::testing::NiceMock<SpiMock>());
	}
	~FakeSpi(){
		_spi.reset();
	}

	// Pointer for accessing to the mocked library
	static std::unique_ptr<SpiMock> _spi;
};

#endif // FAKE_SPI_H
