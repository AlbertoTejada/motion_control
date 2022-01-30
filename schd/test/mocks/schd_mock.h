#pragma once

#ifndef SCHD_MOCK_H
#define SCHD_MOCK_H

#include <stdint.h>
#include "gmock/gmock.h"

class SchdMock{
public:
	virtual ~SchdMock(){}

	//Mock methods
	MOCK_METHOD(void, schd_init, ());
	
	MOCK_METHOD(void, task_10_ms, ());

	MOCK_METHOD(void, task_100_ms, ());
};

#endif // SCHD_MOCK_H
