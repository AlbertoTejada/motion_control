##
## Source definitions
##

if(CMAKE_CROSSCOMPILING)
	add_avr_library(pid pid.c)
	
	avr_target_include_directories(
		pid	
		PUBLIC ${pid_dir}/inc
	)
else(CMAKE_CROSSCOMPILING)
	add_library(pid pid.c)
endif(CMAKE_CROSSCOMPILING)
