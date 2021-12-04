#include "Fixture.h"
extern "C" {
#include "Os_TimeServices.h"
}

extern "C" uint32_t os_timer_ms(){
	return Fixture::_timer -> os_timer_ms();
}

extern "C" uint32_t os_timer_us(){
	return Fixture::_timer -> os_timer_us();
}

extern "C" void os_wait_ms(uint16_t time){
	return Fixture::_timer -> os_wait_ms(time);
}

