##
## Source definitions
##
if(CMAKE_CROSSCOMPILING)
	add_avr_library(
		adc
		adc.c
		# ${adc_dir}/inc/adc.h
		# ${PROJECT_SOURCE_DIR}/board.h
	)

	avr_target_include_directories(
		adc	
		PUBLIC ${adc_dir}/inc
		PUBLIC ${PROJECT_SOURCE_DIR}
	)
# else(CMAKE_CROSSCOMPILING)
# 	add_library(adc adc.c)
endif(CMAKE_CROSSCOMPILING)

