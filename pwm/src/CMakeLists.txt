##
## Source definitions
##
if(CMAKE_CROSSCOMPILING)
	add_avr_library(
		pwm
		pwm.c
	)

	avr_target_include_directories(
		pwm	
		PUBLIC ${pwm_dir}/inc
		PUBLIC ${PROJECT_SOURCE_DIR}
	)
endif(CMAKE_CROSSCOMPILING)

