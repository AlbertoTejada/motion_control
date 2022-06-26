#include "spi_if.h"
#include "gpio.h"

void spi_start(void)
{
	can_drv_select();
}

void spi_end(void)
{
	can_drv_deselect();
}

