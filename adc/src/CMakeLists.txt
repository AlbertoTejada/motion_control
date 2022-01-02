##
## Source definitions
##
if(CMAKE_CROSSCOMPILING)
	add_avr_library(
		adc
		adc.c
	)

	avr_target_include_directories(
		adc	
		PUBLIC ${adc_dir}/inc
		PUBLIC ${PROJECT_SOURCE_DIR}
	)
endif(CMAKE_CROSSCOMPILING)

