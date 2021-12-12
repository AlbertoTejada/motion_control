#pragma once

#ifndef PWM_MOCK_H
#define PWM_MOCK_H

#include <stdint.h>
#include "gmock/gmock.h"

class PwmMock{
public:
	virtual ~PwmMock(){}

	//Mock methods
	MOCK_METHOD(void, pwm_init, ());
	
	MOCK_METHOD(void, set_motor_pwm, (uint8_t pwm));

	MOCK_METHOD(void, set_steering_pwm, (uint8_t pwm));
};

#endif // PWM_MOCK_H
