
add_subdirectory(mocks)
list(APPEND MOCKS_LIB mocks)

add_executable(
  pid_test 
  pid_test.cpp
)

add_custom_target(
  run_pid_test COMMAND CTEST_OUTPUT_ON_FAILURE=1 ${CMAKE_CTEST_COMMAND} DEPENDS pid_test
)

target_link_libraries(
  pid_test
  pid
  gtest_main
  gmock_main
  ${MOCKS_LIB}
)

target_include_directories(
  pid_test
  PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/mocks
)

gtest_discover_tests(pid_test)
