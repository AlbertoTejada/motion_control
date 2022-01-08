#include "uart.h"

void uart_init(void){
	// Set baud rate
	UART_BRH = (unsigned char)(BR_VALUE >> 8);
	UART_BRL = (unsigned char)BR_VALUE;
	// Enable receiver and transmitter
	// Enable empty transmit buffer and received complete
	UART_CTRLB = UART_TX_RX_ENABLE 
		|	UART_EMTY_ENABLE
	  | UART_RXCM_ENABLE;
	// Set odd parity check, two stops bits and 8 data bits:
	// Set frame format: 8 data bit
	UART_CTRLC = UART_ODD_PARITY
		| UART_STOP_BIT
		| UART_8BIT;
}

void uart_tx(uint8_t data){
	// Wait for empty transmit buffer
	while (!(UART_CTRLA & (1 << UART_EMTY)));
	// Put data into buffer, sends the data
	UART_DATA = data;
}

uint8_t uart_rx(uint8_t *data){
	// TODO: Handle error flags
	uint8_t result;
	if(UART_CTRLA & (1 << UART_RXCM))
	{
		*data = UART_DATA;
		result = RECEIVED_TRUE;
	}
	else
	{
		*data = NULL_DATA;
		result = RECEIVED_FALSE;
	}
	return result;
}
