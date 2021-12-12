##
## Source definitions
##
if(CMAKE_CROSSCOMPILING)
	add_avr_library(
		cnt
		cnt.c
	)

	avr_target_include_directories(
		cnt	
		PUBLIC ${cnt_dir}/inc
		PUBLIC ${PROJECT_SOURCE_DIR}
	)
endif(CMAKE_CROSSCOMPILING)

