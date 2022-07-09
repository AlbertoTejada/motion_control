#pragma once

#ifndef FAKE_DELAY_H
#define FAKE_DELAY_H

#include <memory.h>
#include "gtest/gtest.h"
#include "delay_mock.h"

class FakeDelay: virtual public ::testing::Test{
public:
	FakeDelay(){
		_delay.reset(new ::testing::NiceMock<DelayMock>());
	}
	~FakeDelay(){
		_delay.reset();
	}

	// Pointer for accessing to the mocked library
	static std::unique_ptr<DelayMock> _delay;
};

#endif // FAKE_DELAY_H
