#include "fixture.h"
extern "C" {
#include "gpio.h"
}

extern "C" void gpio_init(void){
	return Fixture::_gpio -> gpio_init();
}

extern "C" void can_drv_select(void){
	return Fixture::_gpio -> can_drv_select();
}

extern "C" void can_drv_deselect(void){
	return Fixture::_gpio -> can_drv_deselect();
}

extern "C" void power_motor_activate(void){
	return Fixture::_gpio -> power_motor_activate();
}

extern "C" void power_motor_deactivate(void){
	return Fixture::_gpio -> power_motor_deactivate();
}

extern "C" void power_motor_forward(void){
	return Fixture::_gpio -> power_motor_forward();
}

extern "C" void power_motor_backward(void){
	return Fixture::_gpio -> power_motor_backward();
}
