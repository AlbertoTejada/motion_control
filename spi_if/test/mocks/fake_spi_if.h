#pragma once

#ifndef FAKE_SPI_IF_H
#define FAKE_SPI_IF_H

#include <memory.h>
#include "gtest/gtest.h"
#include "spi_if_mock.h"

class FakeSpiIf: public ::testing::Test{
public:
	FakeSpiIf(){
		_spi_if.reset(new ::testing::NiceMock<SpiIfMock>());
	}
	~FakeSpiIf(){
		_spi_if.reset();
	}
	virtual void SetUp(){}
	virtual void TearDown(){}

	// Pointer for accessing to the mocked library
	static std::unique_ptr<SpiIfMock> _spi_if;
};

#endif // FAKE_SPI_IF_H
