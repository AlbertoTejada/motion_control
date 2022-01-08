#ifndef UART_H
#define UART_H

#include <stdint.h>
#include "board.h"

#define BAUD_RATE (9600U)
#define BR_VALUE (OSC_FREQUENCY/16/BAUD_RATE - 1)
// UART Ctrl B resgister settings:
#define UART_TX_RX_ENABLE (1 << RXEN0) | (1 << TXEN0)
#define UART_RXCM_ENABLE (1 << RXCIE0)
#define UART_EMTY_ENABLE (1 << UDRIE0)
// UART Ctrl C register settings:
#define UART_ODD_PARITY (3 << UPM00)
#define UART_STOP_BIT (1 << USBS0)
#define UART_8BIT (3 << UCSZ00)
// Helper definitions:
#define RECEIVED_TRUE (1U)
#define RECEIVED_FALSE (0U)
#define NULL_DATA (0U)

void uart_init(void);

void uart_tx(uint8_t data);

uint8_t uart_rx(uint8_t *data);

#endif // UART_H
