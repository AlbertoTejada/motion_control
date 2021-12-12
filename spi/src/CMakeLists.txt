##
## Source definitions
##
if(CMAKE_CROSSCOMPILING)
	add_avr_library(
		spi
		spi.c
		# ${spi_SOURCE_DIR}/inc/spi.h
		# ${PROJECT_SOURCE_DIR}/board.h
	)

	avr_target_include_directories(
		spi	
		PUBLIC ${spi_dir}/inc
		PUBLIC ${PROJECT_SOURCE_DIR}
	)
# else(CMAKE_CROSSCOMPILING)
# 	add_library(spi spi.c)
endif(CMAKE_CROSSCOMPILING)
