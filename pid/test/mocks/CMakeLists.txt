add_library(
  mocks	
	Fixture.cpp FakeRte.cpp SystemModel.cpp
)

target_include_directories(
	mocks
	INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}
	PUBLIC ${pid_SOURCE_DIR}/inc
)
