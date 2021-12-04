##
## Source definitions
##

if(CMAKE_CROSSCOMPILING)
	add_avr_library(
		gpio
		gpio.c
		${gpio_dir}/inc/gpio.h
		${PROJECT_SOURCE_DIR}/board.h
	)
endif(CMAKE_CROSSCOMPILING)

