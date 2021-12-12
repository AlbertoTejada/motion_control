add_library(
  pwm_mock	
	fixture.cpp pwm_mock.cpp
)

target_include_directories(
	pwm_mock
	INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}
)
