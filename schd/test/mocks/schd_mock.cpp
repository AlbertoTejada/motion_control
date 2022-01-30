#include "fixture.h"
extern "C" {
#include "schd.h"
}

extern "C" void schd_init(void){
	return Fixture::_schd -> schd_init();
}

extern "C" void task_10_ms(void){
	return Fixture::_schd ->  task_10_ms();
}

extern "C" void task_100_ms(void){
	return Fixture::_schd ->  task_100_ms();
}
