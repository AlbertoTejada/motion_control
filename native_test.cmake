##
## Feth the google test repository and populated it
##
include(FetchContent)
FetchContent_Declare(
  googletest
  GIT_REPOSITORY https://github.com/google/googletest.git
  GIT_TAG        release-1.11.0
)
FetchContent_MakeAvailable(googletest)
include(GoogleTest)
enable_testing()

##
## Add the gmock and gtest headers available for all the targets
##
include_directories(
   ${googletest_SOURCE_DIR}/googletest/include
   ${googletest_SOURCE_DIR}/googlemock/include
)

message(STATUS "Using google test framework")
message(STATUS "Include gtest directory: ${googletest_SOURCE_DIR}/googletest/include")
message(STATUS "Include gmock directory: ${googletest_SOURCE_DIR}/googlemock/include")
