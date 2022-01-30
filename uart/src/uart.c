#include "uart.h"
#include "board.h"
#include <avr/interrupt.h>

#define BR_VALUE (OSC_FREQUENCY/16/BAUD_RATE - 1)

volatile uint8_t uart_output;


void uart_init(void){
	// Set baud rate
	UART_BRH = (unsigned char)(BR_VALUE >> 8);
	UART_BRL = (unsigned char)BR_VALUE;
	/* UART_CTRLB = (UART_RX_COMPINT_ENB << RXCIE0) */
	           /* | (UART_TX_COMPINT_ENB << TXCIE0) */
					   /* | (UART_TX_EMPTINT_ENB << UDRIE0) */
	UART_CTRLB = (UART_RECEIVER << RXEN0)
					   | (UART_TRANSMITTER << TXEN0)
					   | (UART_9BIT << UCSZ02);
	UART_CTRLC = (UART_COMM_MODE << UMSEL00)
		         | (UART_PARITY_MODE << UPM00)
						 | (UART_STOP_BIT << USBS0)
						 | (UART_FRAME_SIZE << UCSZ00)
						 | (UART_CLOCK_POL << UCPOL0);
	sei();
}

void uart_tx(uint8_t data){
	uart_output = data;
	// Enable the TX empty buffer interruption
	UART_CTRLB |= (1 << UDRIE0);
	
	// Wait for empty transmit buffer
	
	// Put data into buffer, sends the data
	/* UART_DATA = data; */
}

ISR(USART_UDRE_vect) {
	// Put data into buffer, sends the data
	UART_DATA = uart_output;
	// Wait until the buffer is empty again
	while (!(UART_CTRLA & (1 << UART_EMTY)));
	// Disable the interrruption
	UART_CTRLB &= ~(1 << UDRIE0);
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
