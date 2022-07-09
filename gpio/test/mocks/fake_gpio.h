#pragma once

#ifndef FAKE_GPIO_H
#define FAKE_GPIO_H

#include <memory.h>
#include "gtest/gtest.h"
#include "gpio_mock.h"

class FakeGpio: virtual public ::testing::Test{
public:
	FakeGpio(){
		_gpio.reset(new ::testing::NiceMock<GpioMock>());
	}
	~FakeGpio(){
		_gpio.reset();
	}

	// Pointer for accessing to the mocked library
	static std::unique_ptr<GpioMock> _gpio;
};

#endif // FAKE_GPIO_H
