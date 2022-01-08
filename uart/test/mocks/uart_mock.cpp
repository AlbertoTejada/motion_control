#include "fixture.h"
extern "C" {
#include "uart.h"
}

extern "C" void uart_init(void){
	return Fixture::_uart -> uart_init();
}

extern "C" void uart_tx(uint8_t data){
	return Fixture::_uart -> uart_tx(data);
}

extern "C" uint8_t uart_rx(uint8_t *data){
	return Fixture::_uart -> uart_rx(data);
}

