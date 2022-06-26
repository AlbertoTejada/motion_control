##
## Source definitions
##

if(CMAKE_CROSSCOMPILING)
	add_avr_library(spi_if spi_if.c)
	
	avr_target_include_directories(
		spi_if	
		PUBLIC ${spi_if_dir}/inc
		PUBLIC ${spi_dir}/inc
		PRIVATE ${gpio_dir}/inc
	)
else(CMAKE_CROSSCOMPILING)
	add_library(spi_if spi_if.c)

	target_include_directories(
		spi_if
		PUBLIC ${spi_dir}/inc
		PRIVATE ${gpio_dir}/inc
	)
endif(CMAKE_CROSSCOMPILING)
