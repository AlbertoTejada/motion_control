#ifndef PWM_H
#define PWM_H

#include <stdint.h>

// Set the power motor PWM clear on match (direct mode):
#define MOTOR_CLR_ON_MATCH (0x80) 
// Set the steering PWM clear on match (direct mode):
#define STRNG_CLR_ON_MATCH (0x20)
// Define the waveform generation for the power motor and
// the steering motor as fast PWM 8 bit:
/* #define FAST_PWM (0x03) */
#define FAST_PWM_CTRLA (0x01)
#define FAST_PWM_CTRLB (0x08)
// Select the internal timer with prescaler at 8 for the
// PWM clock:
#define PWM_CLOCK (0x02)
// Define the registers value:
#define PWM_CTRL_A_CFG ( MOTOR_CLR_ON_MATCH + \
												 STRNG_CLR_ON_MATCH + \
												 FAST_PWM_CTRLA )
#define PWM_CTRL_B_CFG ( PWM_CLOCK + \
												 FAST_PWM_CTRLB )

void pwm_init(void);

void set_motor_pwm(uint8_t pwm);

void set_steering_pwm(uint8_t pwm);

#endif // PWM_H
