add_library(
  can_mock	
	fake_can.cpp can_mock.cpp
)

target_include_directories(
	can_mock
	INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}
	PRIVATE ${can_dir}/inc
)

