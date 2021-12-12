##################################################################################
# "THE ANY BEVERAGE-WARE LICENSE" (Revision 42 - based on beer-ware
# license):
# <dev@layer128.net> wrote this file. As long as you retain this notice
# you can do whatever you want with this stuff. If we meet some day, and
# you think this stuff is worth it, you can buy me a be(ve)er(age) in
# return. (I don't like beer much.)
#
# Matthias Kleemann
##################################################################################

##################################################################################
# Sample CMakeLists.txt for a simple AVR project based on the toolchain
##################################################################################

cmake_minimum_required(VERSION 3.16)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
project(MOTION_CONTROL VERSION 0.0)

# Check if native compilation or crosscompilation:
if(NOT DEFINED CROSSCOMPILE)
   set(CROSSCOMPILE false)
endif(NOT DEFINED CROSSCOMPILE)
message(STATUS "Crosscompiling? ${CROSSCOMPILE}") 

if(CROSSCOMPILE)
   include(cross_compile.cmake)
else(CROSSCOMPILE)
   include(native_test.cmake)
endif(CROSSCOMPILE)

##################################################################################
# set build type, if not already set at cmake command line
##################################################################################
if(NOT CMAKE_BUILD_TYPE)
   set(CMAKE_BUILD_TYPE Release)
endif(NOT CMAKE_BUILD_TYPE)

##################################################################################
# include subdirectories
##################################################################################
# foreach(module ${modules})
#   if(IS_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/${module}
#       AND NOT ${module} STREQUAL "build")
#     add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/${module})
#     message(STATUS "Added module: ${module}")
#   endif()
# endforeach()
add_subdirectory(pwm)
add_subdirectory(gpio)
add_subdirectory(spi)
add_subdirectory(adc)
add_subdirectory(cnt)
add_subdirectory(pid)
add_subdirectory(can_driver)

##################################################################################
# link library to executable
# NOTE: It needs to be the elf target.
##################################################################################
# target_link_libraries(<executable-name>-${AVR_MCU}.elf <library-name>-${AVR_MCU})
# OR easier
# target_link_libraries(<executable-name> <library-name> <some-external-libary>)

