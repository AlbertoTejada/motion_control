##
## Source definitions
##
if(CMAKE_CROSSCOMPILING)
	add_avr_library(
		uart
		uart.c
	)

	avr_target_include_directories(
		uart	
		PUBLIC ${uart_dir}/inc
		PUBLIC ${PROJECT_SOURCE_DIR}
	)
endif(CMAKE_CROSSCOMPILING)

