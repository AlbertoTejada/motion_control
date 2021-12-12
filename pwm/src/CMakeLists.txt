##
## Source definitions
##
if(CMAKE_CROSSCOMPILING)
	add_avr_library(
		pwm
		pwm.c
		# ${pwm_dir}/inc/pwm.h
		# ${PROJECT_SOURCE_DIR}/board.h
	)

	avr_target_include_directories(
		pwm	
		PUBLIC ${pwm_dir}/inc
		PUBLIC ${PROJECT_SOURCE_DIR}
	)
else(CMAKE_CROSSCOMPILING)
	add_library(pwm pwm.c)
endif(CMAKE_CROSSCOMPILING)

