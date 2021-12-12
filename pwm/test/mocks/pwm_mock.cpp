#include "fixture.h"
extern "C" {
#include "pwm.h"
}

extern "C" void pwm_init(void){
	return Fixture::_pwm -> pwm_init();
}

extern "C" void set_motor_pwm(uint8_t pwm){
	return Fixture::_pwm -> set_motor_pwm(pwm);
}

extern "C" void set_steering_pwm(uint8_t pwm){
	return Fixture::_pwm -> set_steering_pwm(pwm);
}

