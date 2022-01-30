#pragma once

#ifndef FIXTURE_H
#define FIXTURE_H

#include <memory.h>
#include "gtest/gtest.h"
#include "schd_mock.h"

class Fixture: public ::testing::Test{
public:
	Fixture(){
		_schd.reset(new ::testing::NiceMock<SchdMock>());
	}
	~Fixture(){
		_schd.reset();
	}
	virtual void SetUp(){}
	virtual void TearDown(){}

	// Pointer for accessing to the mocked library
	static std::unique_ptr<SchdMock> _schd;
};

#endif // FIXTURE_H
