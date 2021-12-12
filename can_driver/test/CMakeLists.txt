
add_subdirectory(mocks)
list(APPEND MOCKS_LIB spi_mocks)

add_executable(
  can_driver_test 
  can_driver_test.cpp
)

add_custom_target(
  run_can_drv_test COMMAND CTEST_OUTPUT_ON_FAILURE=1 ${CMAKE_CTEST_COMMAND} DEPENDS can_driver_test
)

target_link_libraries(
  can_driver_test
  can_driver
  gtest_main
  gmock_main
  ${MOCKS_LIB}
)

target_include_directories(
  can_driver_test
  PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/mocks
)

gtest_discover_tests(can_driver_test)
