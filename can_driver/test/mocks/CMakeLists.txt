add_library(
  mocks	
	Fixture.cpp FakeSpi.cpp FakeTimer.cpp
)

target_include_directories(
	mocks
	INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}
	PUBLIC ${can_driver_SOURCE_DIR}/inc
)
