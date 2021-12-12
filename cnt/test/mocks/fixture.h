#pragma once

#ifndef FIXTURE_H
#define FIXTURE_H

#include <memory.h>
#include "gtest/gtest.h"
#include "cnt_mock.h"

class Fixture: public ::testing::Test{
public:
	Fixture(){
		_cnt.reset(new ::testing::NiceMock<CntMock>());
	}
	~Fixture(){
		_cnt.reset();
	}
	virtual void SetUp(){}
	virtual void TearDown(){}

	// Pointer for accessing to the mocked library
	static std::unique_ptr<CntMock> _cnt;
};

#endif // FIXTURE_H
