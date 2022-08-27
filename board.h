#ifndef BOARD_H
#define BOARD_H

#include <avr/io.h>

/* Arduino Nano crystal oscillator frequency [Hz] */
#ifndef F_CPU
	#define F_CPU 16000000UL
#endif

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
* Definitions for the pin numbers, port and 
* direction registers:
*/
// Power motor pulse counter:
/* #define MOTOR_CNT PIN0 */
/* #define MOTOR_CNT_PORT PORTB */
/* #define MOTOR_CNT_DIR DDRB */
#define MOTOR_CNT PIN4
#define MOTOR_CNT_PORT PORTD
#define MOTOR_CNT_DIR DDRD
// CAN controller SPI chip selected:
/* #define CAN_DVR_CS PIN2 */
/* #define CAN_DVR_CS_PORT PORTB */
/* #define CAN_DVR_CS_DIR DDRB */
#define CAN_DVR_CS PIN5
#define CAN_DVR_CS_PORT PORTD
#define CAN_DVR_CS_DIR DDRD
// SPI MOSI:
#define SPI_MOSI PIN3
#define SPI_MOSI_PORT PORTB
#define SPI_MOSI_DIR DDRB
// SPI MISO:
#define SPI_MISO PIN4
#define SPI_MISO_PORT PORTB
#define SPI_MISO_DIR DDRB
// SPI clock:
#define SPI_CLK PIN5
#define SPI_CLK_PORT PORTB
#define SPI_CLK_DIR DDRB
// Stering wheel motor sensor:
#define STEERING_SENS PIN0
#define STEERING_SENS_PORT PORTC
#define STEERING_SENS_DIR DDRC
// Power motor spin direction:
/* #define MOTOR_SPIN PIN4 */
/* #define MOTOR_SPIN_PORT PORTD */
/* #define MOTOR_SPIN_DIR DDRD */
#define MOTOR_SPIN PIN6
#define MOTOR_SPIN_PORT PORTD
#define MOTOR_SPIN_DIR DDRD
// Power motor PWM:
/* #define MOTOR_PWM PIN5 */
/* #define MOTOR_PWM_PORT PORTD */
/* #define MOTOR_PWM_DIR DDRD */
#define MOTOR_PWM PIN2
#define MOTOR_PWM_PORT PORTB
#define MOTOR_PWM_DIR DDRB
// Stering wheel motor PWM:
/* #define STEERING_PWM PIN1 */
/* #define STEERING_PWM_PORT PORTB */
/* #define STEERING_PWM_DIR DDRB */
#define STEERING_PWM PIN1
#define STEERING_PWM_PORT PORTB
#define STEERING_PWM_DIR DDRB
// Power motor activation:
#define MOTOR_ACTIVATION PIN7
#define MOTOR_ACTIVATION_PORT PORTD
#define MOTOR_ACTIVATION_DIR DDRD

/**
* Definition of the PWM and counter registers:
*/
// Power motor and steering motor PWM configuration:
/* #define PWM_CTRL_A TCCR0A */
/* #define PWM_CTRL_B TCCR0B */ 
#define PWM_CTRL_A TCCR1A
#define PWM_CTRL_B TCCR1B 
// Output compare value for the power motor PWM:
/* #define MOTOR_PWM_OC OCR0A */
#define MOTOR_PWM_OC OCR1A
// Output compare value for the steering motor PWM:
/* #define STEERING_PWM_OC OCR0B */
#define STEERING_PWM_OC OCR1B

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

/*
 * Definitions of the ADC registers:
 */
// ADC output data:
#define ADC_DATAL ADCL
#define ADC_DATAH ADCH
// Configuration and control:
#define ADC_MUX ADMUX
#define ADC_CTRLA ADCSRA
#define ADC_CTRLB ADCSRB
#define ADC_DISB DIDR0

/*
 * Definitions of the scheduler registers:
 */
#define SCHD_CTRLA TCCR2A
#define SCHD_CTRLB TCCR2B
#define SCHD_TIMEA OCR2A
#define SCHD_TIMEB OCR2B
#define SCHD_IMASK TIMSK2
#define SCHD_IFLAG TIFR2
#define SCHD_ASYC ASSR

/*
 * Definitions of the counter registers:
 */
// Counter output data:
#define CNT_DATA TCNT0
// Configuration and control:
#define CNT_CTRLA TCCR0A
#define CNT_CTRLB TCCR0B
#define CNT_IMASK TIMSK0
#define CNT_IFLAG TIFR0

/* #define CNT_ASYC */ 

#endif // BOARD_H
