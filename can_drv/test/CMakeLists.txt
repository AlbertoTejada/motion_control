
add_subdirectory(mocks)

add_executable(
  can_drv_test 
  can_drv_test.cpp
)

target_link_libraries(
  can_drv_test
  can_drv
  gtest_main
  gmock_main
  spi_if_mock
  delay_mock
)

target_include_directories(
  can_drv_test
  PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/mocks
	PRIVATE ${spi_if_dir}/test/mocks
	PRIVATE ${delay_dir}
)

gtest_discover_tests(can_drv_test)
