#include "pwm.h"

/**
 * \brief PWM on target test: 
 * This is a simple test to verify the behaviour of the PWM
 * pins. The expected behaviour is:
 * Power motor pin (D5) is set at 66% of duty cycle.
 * Steering motor (D6) is set at 25% of duty cycle.
 * \file pwm_test.c
 * \author Alberto Tejada
 */
int main(void) {
	pwm_init();
	set_motor_pwm(170u);
	set_steering_pwm(64u);

	while(1) {}
	return 0;
}
	
