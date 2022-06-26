message(STATUS "Including gpio_mock")

add_library(
  gpio_mock	
	fake_gpio.cpp gpio_mock.cpp
)

target_include_directories(
	gpio_mock
	INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}
)
