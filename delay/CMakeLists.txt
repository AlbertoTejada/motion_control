set(delay_dir ${CMAKE_CURRENT_SOURCE_DIR} CACHE INTERNAL "")

add_library(
  delay_mock
  fake_delay.cpp delay_mock.cpp
)

