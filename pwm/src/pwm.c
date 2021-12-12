#include "pwm.h" 
#include "board.h"

void pwm_init(void) {
	// Set the PWM pins as output:
	MOTOR_PWM_DIR |= (OUTPUT << MOTOR_PWM);
	STEERING_PWM_DIR |= (OUTPUT << STEERING_PWM);
	// Set the PWM fast mode, waveform, timer and prescaler:
	PWM_CTRL_A = PWM_CTRL_A_CFG;
	PWM_CTRL_B = PWM_CTRL_B_CFG;
	// Set the PWM to their default value:
	MOTOR_PWM_OC = 0;
	STEERING_PWM_OC = 0;
}

void set_motor_pwm(uint8_t pwm) {
	MOTOR_PWM_OC = pwm;
}

void set_steering_pwm(uint8_t pwm) {
	STEERING_PWM_OC = pwm;
}

