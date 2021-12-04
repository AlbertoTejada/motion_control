##
## Source definitions
##
message(STATUS "Crosscimpiling?: ${CMAKE_CROSSCOMPILING}")
if(CMAKE_CROSSCOMPILING)
	add_avr_library(
		pwm
		pwm.c
		${pwm_dir}/inc/pwm.h
		${PROJECT_SOURCE_DIR}/board.h
	)
endif(CMAKE_CROSSCOMPILING)

