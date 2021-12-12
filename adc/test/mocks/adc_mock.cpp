#include "fixture.h"
extern "C" {
#include "adc.h"
}

extern "C" void adc_init(void){
	return Fixture::_adc -> adc_init();
}

extern "C" uint8_t read_angle(void){
	return Fixture::_adc -> read_angle();
}

