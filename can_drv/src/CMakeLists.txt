##
## Source definitions
##

if(CMAKE_CROSSCOMPILING)
	add_avr_library(can_drv Mcp2515.c Mcp2515_Cfg.c)

	avr_target_include_directories(
		can_drv	
		PUBLIC ${can_drv_dir}/inc
		PRIVATE ${spi_if_dir}/inc
		PRIVATE ${spi_dir}/inc
	)
else(CMAKE_CROSSCOMPILING)
	add_library(can_drv Mcp2515.c Mcp2515_Cfg.c)

	target_include_directories(
		can_drv
		PRIVATE ${spi_if_dir}/inc
		PRIVATE ${spi_dir}/inc
		PRIVATE ${delay_dir}
	)
endif(CMAKE_CROSSCOMPILING)
