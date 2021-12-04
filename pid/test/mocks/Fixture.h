#pragma once

#ifndef FIXTURE_H
#define FIXTURE_H

#include <memory.h>
#include "gtest/gtest.h"
#include "RteMock.h"

class Fixture: public ::testing::Test{
public:
	Fixture(){
		_rte.reset(new ::testing::NiceMock<RteMock>());
	}
	~Fixture(){
		_rte.reset();
	}
	virtual void SetUp(){}
	virtual void TearDown(){}

	// Pointer for accessing to the mocked library
	static std::unique_ptr<RteMock> _rte;
};

#endif // FIXTURE_H
