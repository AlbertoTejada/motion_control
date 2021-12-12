add_library(
  adc_mock	
	fixture.cpp adc_mock.cpp
)

target_include_directories(
	adc_mock
	INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}
)
