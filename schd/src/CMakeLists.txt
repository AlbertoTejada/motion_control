##
## Source definitions
##
if(CMAKE_CROSSCOMPILING)
	add_avr_library(
		schd
		schd.c
		schd_cfg.c
	)

	avr_target_include_directories(
		schd	
		PUBLIC ${schd_dir}/inc
		PUBLIC ${PROJECT_SOURCE_DIR}
	)
endif(CMAKE_CROSSCOMPILING)

