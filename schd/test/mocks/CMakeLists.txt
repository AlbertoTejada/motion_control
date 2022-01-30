add_library(
  schd_mock	
	fixture.cpp schd_mock.cpp
)

target_include_directories(
	schd_mock
	INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}
)
