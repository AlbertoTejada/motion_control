#pragma once

#ifndef FIXTURE_H
#define FIXTURE_H

#include <memory.h>
#include "gtest/gtest.h"
#include "gpio_mock.h"

class Fixture: public ::testing::Test{
public:
	Fixture(){
		_gpio.reset(new ::testing::NiceMock<GpioMock>());
	}
	~Fixture(){
		_gpio.reset();
	}
	virtual void SetUp(){}
	virtual void TearDown(){}

	// Pointer for accessing to the mocked library
	static std::unique_ptr<GpioMock> _gpio;
};

#endif // FIXTURE_H
