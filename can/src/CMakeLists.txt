##
## Source definitions
##

if(CMAKE_CROSSCOMPILING)
	add_avr_library(can can.c)
	
	avr_target_include_directories(
		can	
		PUBLIC ${can_dir}/inc
		PRIVATE ${can_drv_dir}/inc
	)
else(CMAKE_CROSSCOMPILING)
	add_library(can can.c)

	message(STATUS "${can_drv_dir}/inc")

	target_include_directories(
		can
		PUBLIC ${can_dir}/inc
		PRIVATE ${can_drv_dir}/inc
	)
endif(CMAKE_CROSSCOMPILING)

