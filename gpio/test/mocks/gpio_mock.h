#pragma once

#ifndef GPIO_MOCK_H
#define GPIO_MOCK_H

#include <stdint.h>
#include "gmock/gmock.h"

class GpioMock{
public:
	virtual ~GpioMock(){}

	//Mock methods
	MOCK_METHOD(void, gpio_init, ());
	
	MOCK_METHOD(void, can_drv_select, ());
	
	MOCK_METHOD(void, can_drv_deselect, ());
	
	MOCK_METHOD(void, power_motor_activate, ());
	
	MOCK_METHOD(void, power_motor_deactivate, ());
	
	MOCK_METHOD(void, power_motor_forward, ());
	
	MOCK_METHOD(void, power_motor_backward, ());
};

#endif // GPIO_MOCK_H
