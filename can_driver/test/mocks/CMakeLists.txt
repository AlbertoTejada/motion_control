add_library(
  spi_mocks	
	Fixture.cpp FakeSpi.cpp FakeTimer.cpp
)

target_include_directories(
	spi_mocks
	INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}
)
