#include "Fixture.h"
extern "C" {
#include "SpiHandler.h"
}

extern "C" void spi_init(uint8_t cc){
	return Fixture::_spi -> spi_init(cc);
}

extern "C" void spi_start(){
	return Fixture::_spi -> spi_start();
}

extern "C" void spi_end(){
	return Fixture::_spi -> spi_end();
}

extern "C" uint8_t spi_transfer(uint8_t inb){
	return Fixture::_spi -> spi_transfer(inb);
}
