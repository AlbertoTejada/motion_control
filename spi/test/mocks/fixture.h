#pragma once

#ifndef FIXTURE_H
#define FIXTURE_H

#include <memory.h>
#include "gtest/gtest.h"
#include "spi_mock.h"

class Fixture: public ::testing::Test{
public:
	Fixture(){
		_spi.reset(new ::testing::NiceMock<SpiMock>());
	}
	~Fixture(){
		_spi.reset();
	}
	virtual void SetUp(){}
	virtual void TearDown(){}

	// Pointer for accessing to the mocked library
	static std::unique_ptr<SpiMock> _spi;
};

#endif // FIXTURE_H
