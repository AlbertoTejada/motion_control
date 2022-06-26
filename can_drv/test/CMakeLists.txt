
add_subdirectory(mocks)
list(APPEND MOCKS_LIB spi_mocks)

add_executable(
  can_drv_test 
  can_drv_test.cpp
)

add_custom_target(
  run_can_drv_test COMMAND CTEST_OUTPUT_ON_FAILURE=1 ${CMAKE_CTEST_COMMAND} DEPENDS can_drv_test
)

target_link_libraries(
  can_drv_test
  can_drv
  gtest_main
  gmock_main
  ${MOCKS_LIB}
)

target_include_directories(
  can_drv_test
  PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/mocks
)

gtest_discover_tests(can_drv_test)
