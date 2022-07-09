#pragma once

#ifndef DELAY_MOCK_H
#define DELAY_MOCK_H

#include <stdint.h>
#include "gmock/gmock.h"

class DelayMock{
public:
	virtual ~DelayMock(){}

	//Mock methods
	MOCK_METHOD(void, _delay_ms, (double));
	
	MOCK_METHOD(void, _delay_us, (double));
};

#endif // DELAY_MOCK_H
