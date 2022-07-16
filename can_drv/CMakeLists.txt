##
## Define library directory and include path
##
set(can_drv_dir ${CMAKE_CURRENT_SOURCE_DIR} CACHE INTERNAL "")
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/inc)


##
## Source definitions
##
add_subdirectory(src)


##
## Test definitions
##
if(NOT CMAKE_CROSSCOMPILING)
   add_subdirectory(test)
endif(NOT CMAKE_CROSSCOMPILING)
