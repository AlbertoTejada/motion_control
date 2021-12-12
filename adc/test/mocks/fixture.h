#pragma once

#ifndef FIXTURE_H
#define FIXTURE_H

#include <memory.h>
#include "gtest/gtest.h"
#include "adc_mock.h"

class Fixture: public ::testing::Test{
public:
	Fixture(){
		_adc.reset(new ::testing::NiceMock<AdcMock>());
	}
	~Fixture(){
		_adc.reset();
	}
	virtual void SetUp(){}
	virtual void TearDown(){}

	// Pointer for accessing to the mocked library
	static std::unique_ptr<AdcMock> _adc;
};

#endif // FIXTURE_H
