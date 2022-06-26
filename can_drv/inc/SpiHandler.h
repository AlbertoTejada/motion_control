#pragma once

#ifndef _MCP2515_SPI_H_
#define _MCP2515_SPI_H_

#include <stdint.h>

#define MCP2515_SPI_CLOCK 10000000U

void spi_init(uint8_t cc); // SPI initialization and CC pin selection
void spi_start(void);
void spi_end(void);
uint8_t spi_transfer(uint8_t inb);  // SPI xfer 1 byte

#endif // _MCP2515_SPI_H_
