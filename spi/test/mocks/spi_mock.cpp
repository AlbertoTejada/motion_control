#include "fake_spi.h"
extern "C" {
#include "spi.h"
}

extern "C" void spi_init(void){
	return FakeSpi::_spi -> spi_init();
}

extern "C" uint8_t spi_transfer(uint8_t data){
	return FakeSpi::_spi -> spi_transfer(data);
}

