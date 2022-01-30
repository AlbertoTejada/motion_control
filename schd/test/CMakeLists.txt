##########################################################################
# "THE ANY BEVERAGE-WARE LICENSE" (Revision 42 - based on beer-ware
# license):
# <dev@layer128.net> wrote this file. As long as you retain this notice
# you can do whatever you want with this stuff. If we meet some day, and
# you think this stuff is worth it, you can buy me a be(ve)er(age) in
# return. (I don't like beer much.)
#
# Matthias Kleemann
##########################################################################

if(CMAKE_CROSSCOMPILING)
   add_avr_executable(
      schd_test
      schd_test.c
   )

   avr_target_include_directories(
      schd_test
      PUBLIC ${uart_dir}/inc
      PUBLIC ${gpio_dir}/inc
   )
   
   find_library(C_LIB c)
   message(STATUS "avr-libc: ${C_LIB}")
   
   avr_target_link_libraries(schd_test schd uart gpio ${C_LIB})
else(CMAKE_CROSSCOMPILING)
   add_subdirectory(mocks)
endif(CMAKE_CROSSCOMPILING)

