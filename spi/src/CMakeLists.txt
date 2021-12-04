##
## Source definitions
##

add_avr_library(
	spi
	spi.c
	${spi_SOURCE_DIR}/inc/spi.h
	${spi_SOURCE_DIR}/../board.h
)
