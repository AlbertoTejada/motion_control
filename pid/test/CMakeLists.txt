if(NOT CMAKE_CROSSCOMPILING)
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
    pid_test 
    pid_test.cpp
  )
  
  add_custom_target(
    run_pid_test COMMAND CTEST_OUTPUT_ON_FAILURE=1 ${CMAKE_CTEST_COMMAND} DEPENDS pid_test
  )
  
  target_link_libraries(
    pid_test
    gtest_main
    gmock_main
    ${MOCKS_LIB}
  )
  
  target_include_directories(
    pid_test
  	PUBLIC ${pid_dir}/inc
    PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/mocks
  )
  
  target_sources(
    pid_test
    PUBLIC ${pid_dir}/src/pid.c
  )
  
  include(GoogleTest)
  gtest_discover_tests(pid_test)
endif(NOT CMAKE_CROSSCOMPILING)
