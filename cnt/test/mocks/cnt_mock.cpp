#include "fixture.h"
extern "C" {
#include "cnt.h"
}

extern "C" void cnt_init(void){
	return Fixture::_cnt -> cnt_init();
}

extern "C" uint8_t read_cnt(void){
	return Fixture::_cnt -> read_cnt();
}

