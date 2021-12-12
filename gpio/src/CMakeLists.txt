##
## Source definitions
##

if(CMAKE_CROSSCOMPILING)
	add_avr_library(
		gpio
		gpio.c
		# ${gpio_dir}/inc/gpio.h
		# ${PROJECT_SOURCE_DIR}/board.h
	)

	avr_target_include_directories(
		gpio	
		PUBLIC ${gpio_dir}/inc
		PUBLIC ${PROJECT_SOURCE_DIR}
	)
endif(CMAKE_CROSSCOMPILING)

