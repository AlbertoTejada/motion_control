include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/609281088cfefc76f9d0ce82e1ff6c30cc3591e5.zip
)

# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

enable_testing()

add_subdirectory(mocks)
list(APPEND MOCKS_LIB mocks)

add_executable(
  can_driver_test 
  can_driver_test.cpp
)

target_link_libraries(
  can_driver_test
  gtest_main
  gmock_main
  ${MOCKS_LIB}
)

target_include_directories(
  can_driver_test
	PUBLIC ${can_driver_SOURCE_DIR}/inc
  PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/mocks
)

target_sources(
  can_driver_test
  PUBLIC ${can_driver_SOURCE_DIR}/src/Mcp2515.c
  PUBLIC ${can_driver_SOURCE_DIR}/src/Mcp2515_Cfg.c
)

include(GoogleTest)
gtest_discover_tests(can_driver_test)
