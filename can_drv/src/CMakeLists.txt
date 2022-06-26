##
## Source definitions
##
if(CMAKE_CROSSCOMPILING)
	add_avr_library(can_drv Mcp2515.c Mcp2515_Cfg.c)

	avr_target_include_directories(
		can_drv	
		PUBLIC ${can_drv_dir}/inc
	)
else(CMAKE_CROSSCOMPILING)
	add_library(can_drv Mcp2515.c Mcp2515_Cfg.c)
endif(CMAKE_CROSSCOMPILING)
