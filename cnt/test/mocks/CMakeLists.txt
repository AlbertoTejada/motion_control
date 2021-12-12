add_library(
  cnt_mock	
	fixture.cpp cnt_mock.cpp
)

target_include_directories(
	cnt_mock
	INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}
)
