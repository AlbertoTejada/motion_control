set(gpio_dir ${CMAKE_CURRENT_SOURCE_DIR})
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/inc)

##
## Source definitions
##
add_subdirectory(src)


##
## Test definitions
##
add_subdirectory(test)
