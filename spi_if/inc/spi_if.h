#ifndef _SPI_IF_H_
#define _SPI_IF_H_

#include <stdint.h>
#include "spi.h"

/**
 * Starts the SPI communication by pulling down the
 * corresponding CS pin.
 */
void spi_start(void);

/**
 * Stops the SPI communication by pulling up the
 * corresponding CS pin.
 */
void spi_end(void);

#endif // _SPI_IF_H_
