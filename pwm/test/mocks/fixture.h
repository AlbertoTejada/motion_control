#pragma once

#ifndef FIXTURE_H
#define FIXTURE_H

#include <memory.h>
#include "gtest/gtest.h"
#include "pwm_mock.h"

class Fixture: public ::testing::Test{
public:
	Fixture(){
		_pwm.reset(new ::testing::NiceMock<PwmMock>());
	}
	~Fixture(){
		_pwm.reset();
	}
	virtual void SetUp(){}
	virtual void TearDown(){}

	// Pointer for accessing to the mocked library
	static std::unique_ptr<PwmMock> _pwm;
};

#endif // FIXTURE_H
