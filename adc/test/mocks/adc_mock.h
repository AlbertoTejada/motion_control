#pragma once

#ifndef ADC_MOCK_H
#define ADC_MOCK_H

#include <stdint.h>
#include "gmock/gmock.h"

class AdcMock{
public:
	virtual ~AdcMock(){}

	//Mock methods
	MOCK_METHOD(void, adc_init, ());
	
	MOCK_METHOD(uint16_t, read_angle, ());
};

#endif // ADC_MOCK_H
