##
## Source definitions
##
if(CMAKE_CROSSCOMPILING)
	add_avr_library(
		spi
		spi.c
	)

	avr_target_include_directories(
		spi	
		PUBLIC ${spi_dir}/inc
		PUBLIC ${PROJECT_SOURCE_DIR}
	)
endif(CMAKE_CROSSCOMPILING)
