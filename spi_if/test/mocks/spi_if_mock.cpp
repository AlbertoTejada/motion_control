#include "fake_spi_if.h"
extern "C" {
#include "spi_if.h"
}

extern "C" void spi_init(void){
	return FakeSpiIf::_spi_if -> spi_init();
}

extern "C" uint8_t spi_trasfer(uint8_t data){
	return FakeSpiIf::_spi_if -> spi_transfer(data);
}

extern "C" void spi_start(void){
	return FakeSpiIf::_spi_if -> spi_start();
}

extern "C" void spi_stop(void){
	return FakeSpiIf::_spi_if -> spi_stop();
}
