##
## Source definitions
##

if(CMAKE_CROSSCOMPILING)
	add_avr_library(
		gpio
		gpio.c
	)

	avr_target_include_directories(
		gpio	
		PUBLIC ${gpio_dir}/inc
		PUBLIC ${PROJECT_SOURCE_DIR}
	)
endif(CMAKE_CROSSCOMPILING)

