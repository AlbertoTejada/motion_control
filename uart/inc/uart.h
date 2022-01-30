#pragma once

#ifndef UART_H
#define UART_H

#include <stdint.h>

#define BAUD_RATE (9600U)
/* UART Ctrl B resgister settings: */
// Enable/disable the receive complete interruption
/* #define UART_RX_COMPINT_ENB (1) */
#define UART_RX_COMPINT_ENB (0)
// Enable/diable the trasmit complete interruption
#define UART_TX_COMPINT_ENB (0)
// Enable/disable the trasmit buffer empty interruption
#define UART_TX_EMPTINT_ENB (0)
/* #define UART_TX_EMPTINT_ENB (1) */
// Enable/disable the UART as receiver
#define UART_RECEIVER (1)
// Enable/disable the UART as transmitter
#define UART_TRANSMITTER (1)
// Enable/disable the 9th bit in the frame 
#define UART_9BIT (0)

/* UART Ctrl C register settings: */
// Select the communication mode
#define UART_COMM_MODE (0)
// Select the parity mode
#define UART_PARITY_MODE (3)
// Select the number of stop bits
#define UART_STOP_BIT (1)
// Select the frame size
#define UART_FRAME_SIZE (3)
// Select the UART clock polatiry 
#define UART_CLOCK_POL (0)

// Helper definitions:
#define RECEIVED_TRUE (1U)
#define RECEIVED_FALSE (0U)
#define NULL_DATA (0U)

void uart_init(void);

void uart_tx(uint8_t data);

uint8_t uart_rx(uint8_t *data);

#endif // UART_H
