#pragma once

#include <gmock/gmock-nice-strict.h>
#ifndef FIXTURE_H
#define FIXTURE_H

#include <memory.h>
#include "gtest/gtest.h"
#include "SpiMock.h"
#include "TimerMock.h"

class Fixture: public ::testing::Test{
public:
	Fixture(){
		_spi.reset(new ::testing::StrictMock<SpiMock>());
		_timer.reset(new ::testing::StrictMock<TimerMock>());
	}
	~Fixture(){
		_spi.reset();
		_timer.reset();
	}
	virtual void SetUp(){}
	virtual void TearDown(){}

	// Pointer for accessing to the mocked library
	static std::unique_ptr<SpiMock> _spi;
	static std::unique_ptr<TimerMock> _timer;
};

#endif // FIXTURE_H
