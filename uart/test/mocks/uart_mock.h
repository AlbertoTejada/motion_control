#pragma once

#ifndef UART_MOCK_H
#define UART_MOCK_H

#include <stdint.h>
#include "gmock/gmock.h"

class UartMock{
public:
	virtual ~UartMock(){}

	//Mock methods
	MOCK_METHOD(void, uart_init, ());
	
	MOCK_METHOD(void, uart_tx, (uint8_t data));

	MOCK_METHOD(uint8_t, uart_rx, (uint8_t *data));
};

#endif // UART_MOCK_H
