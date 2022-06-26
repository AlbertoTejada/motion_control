#include "fake_gpio.h"
extern "C" {
#include "gpio.h"
}

extern "C" void gpio_init(void){
	return FakeGpio::_gpio -> gpio_init();
}

extern "C" void can_drv_select(void){
	return FakeGpio::_gpio -> can_drv_select();
}

extern "C" void can_drv_deselect(void){
	return FakeGpio::_gpio -> can_drv_deselect();
}

extern "C" void power_motor_activate(void){
	return FakeGpio::_gpio -> power_motor_activate();
}

extern "C" void power_motor_deactivate(void){
	return FakeGpio::_gpio -> power_motor_deactivate();
}

extern "C" void power_motor_forward(void){
	return FakeGpio::_gpio -> power_motor_forward();
}

extern "C" void power_motor_backward(void){
	return FakeGpio::_gpio -> power_motor_backward();
}
