message(STATUS "Including spi_mock")

add_library(
  spi_mock	
	fake_spi.cpp spi_mock.cpp
)

target_include_directories(
	spi_mock
	INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}
)
