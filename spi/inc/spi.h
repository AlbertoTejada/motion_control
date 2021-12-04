#pragma once

#ifndef _SPI_H_
#define _SPI_H_

#include <stdint.h>

#define SPI_ENABLE (1 << 6)
#define MSBFIRST (0 << 5)
#define SPI_MASTER (1 << 4)
#define SPI_MODE0 (0 << 2)
// Define the SPI speed as fosc/2 = 8000000 Hz
#define SPI_SPEED (1) 
// Define the SPI Interrupt flag mask:
#define SPI_COMPLETE (1 << 7)

void spi_init(void);

uint8_t spi_transfer(uint8_t data);

#endif // _SPI_H_
