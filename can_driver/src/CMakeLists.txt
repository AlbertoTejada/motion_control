##
## Source definitions
##

add_library(can_driver Mcp2515.c Mcp2515_Cfg.c)

target_include_directories(
	can_driver	
	PUBLIC ${can_driver_SOURCE_DIR}/inc
)
