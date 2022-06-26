add_library(
  spi_if_mock	
	fake_spi_if.cpp spi_if_mock.cpp
)

target_include_directories(
	spi_if_mock
  PUBLIC ${spi_dir}/inc
	INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}
)
