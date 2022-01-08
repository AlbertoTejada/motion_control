#ifndef BOARD_H
#define BOARD_H

#include <avr/io.h>

/* Arduino Nano crystal oscillator frequency [Hz] */
#define OSC_FREQUENCY 16000000U

/**
 * Definitions for the pin and register values
 */
#define INPUT 0U
#define OUTPUT 1U

#define PULL_DOWN 0U
#define PULL_UP 1U

#define LOW 0U
#define HIGH 1U

/**
* Definitions for the pin numbers and port and 
* direction registers:
*/
// UART Rx:
#define UART_RX PIN0
#define UART_RX_PORT PORTD
#define UART_RX_DIR DDRD
// UART Tx:
#define UART_TX PIN1
#define UART_TX_PORT PORTD
#define UART_TX_DIR DDRD
// CAN controller SPI chip selected:
#define CAN_DVR_CS PIN2
#define CAN_DVR_CS_PORT PORTB
#define CAN_DVR_CS_DIR DDRB
// SPI clock:
#define SPI_CLK PIN5
#define SPI_CLK_PORT PORTB
#define SPI_CLK_DIR DDRB
// SPI MOSI:
#define SPI_MOSI PIN3
#define SPI_MOSI_PORT PORTB
#define SPI_MOSI_DIR DDRB
// SPI MISO:
#define SPI_MISO PIN4
#define SPI_MISO_PORT PORTB
#define SPI_MISO_DIR DDRB
// Power motor activation:
#define MOTOR_ACTIVATION PIN7
#define MOTOR_ACTIVATION_PORT PORTD
#define MOTOR_ACTIVATION_DIR DDRD
// Power motor PWM:
#define MOTOR_PWM PIN5
#define MOTOR_PWM_PORT PORTD
#define MOTOR_PWM_DIR DDRD
// Power motor spin direction:
#define MOTOR_SPIN PIN4
#define MOTOR_SPIN_PORT PORTD
#define MOTOR_SPIN_DIR DDRD
// Stering wheel motor PWM:
#define STEERING_PWM PIN6
#define STEERING_PWM_PORT PORTD
#define STEERING_PWM_DIR DDRD
// Stering wheel motor sensor:
#define STEERING_SENS PIN0
#define STEERING_SENS_PORT PORTC
#define STEERING_SENS_DIR DDRC

/**
* Definition of the PWM and counter registers:
*/
// Power motor and steering motor PWM configuration:
#define PWM_CTRL_A TCCR0A
#define PWM_CTRL_B TCCR0B 
// Output compare value for the power motor PWM:
#define MOTOR_PWM_OC OCR0A
// Output compare value for the steering motor PWM:
#define STEERING_PWM_OC OCR0B

/**
 * Definition of the SPI registers:
 */
#define SPI_CTRL SPCR
#define SPI_STAT SPSR
#define SPI_DATA SPDR

/**
 * Definition of the UART registers:
 */
// Baud rate (high and low):
#define UART_BRH UBRR0H
#define UART_BRL UBRR0L
// UART control:
#define UART_CTRLA UCSR0A
#define UART_CTRLB UCSR0B
#define UART_CTRLC UCSR0C
// UART data:
#define UART_DATA UDR0
// UART data register empty flag:
#define UART_EMTY UDRE0
// UART reveive complete flag:
#define UART_RXCM RXC0

#endif // BOARD_H
