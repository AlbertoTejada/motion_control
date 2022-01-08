message(STATUS "Including uart_mock")

add_library(
  uart_mock	
	fixture.cpp uart_mock.cpp
)

target_include_directories(
	uart_mock
	INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}
)
