add_library(
  can_drv_mock	
	fake_can_drv.cpp can_drv_mock.cpp
)

target_include_directories(
	can_drv_mock
	INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}
	PRIVATE ${can_drv_dir}/inc
)
