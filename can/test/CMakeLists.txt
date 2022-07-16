if(CMAKE_CROSSCOMPILING)
  add_avr_executable(
    can_poc
    poc.c
  )

  avr_target_include_directories(
    can_poc
    PRIVATE ${can_dir}/inc
    PRIVATE ${uart_dir}/inc
    PRIVATE ${schd_dir}/inc
    PRIVATE ${spi_dir}/inc
  )

  avr_target_link_libraries(
    can_poc
    can
    uart
    schd
    spi
    ${C_LIB}
  )
else(CMAKE_CROSSCOMPILING)
  add_subdirectory(mocks)
  
  add_executable(
    can_test 
    can_test.cpp
  )
  
  target_link_libraries(
    can_test
    can
    gtest_main
    gmock_main
    can_drv 
  )
  
  target_include_directories(
    can_test
    PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/mocks
  	PRIVATE ${can_drv_dir}/test/mocks
  )
  
  gtest_discover_tests(can_test)
endif(CMAKE_CROSSCOMPILING)
