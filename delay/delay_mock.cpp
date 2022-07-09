#include "fake_delay.h"
extern "C" {
#include "util/delay.h"
}

extern "C" void _delay_ms(double __ms){
	return FakeDelay::_delay -> _delay_ms(__ms);
}

extern "C" void _delay_us(double __us){
	return FakeDelay::_delay -> _delay_us(__us);
}
