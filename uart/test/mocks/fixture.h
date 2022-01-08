#pragma once

#ifndef FIXTURE_H
#define FIXTURE_H

#include <memory.h>
#include "gtest/gtest.h"
#include "uart_mock.h"

class Fixture: public ::testing::Test{
public:
	Fixture(){
		_uart.reset(new ::testing::NiceMock<UartMock>());
	}
	~Fixture(){
		_uart.reset();
	}
	virtual void SetUp(){}
	virtual void TearDown(){}

	// Pointer for accessing to the mocked library
	static std::unique_ptr<UartMock> _uart;
};

#endif // FIXTURE_H
