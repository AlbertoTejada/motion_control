if(NOT CMAKE_CROSSCOMPILING)
   add_executable(
      spi_if_test
      spi_if_test.cpp
   )
   
   target_include_directories(
      spi_if_test
      PRIVATE ${spi_dir}/test/mocks
      PRIVATE ${gpio_dir}/test/mocks
   )

   target_link_libraries(
      spi_if_test
      spi_if
      gtest_main
      gmock_main
      spi_mock
      gpio_mock
   )

   add_subdirectory(mocks)

   gtest_discover_tests(spi_if_test)
endif(NOT CMAKE_CROSSCOMPILING)

