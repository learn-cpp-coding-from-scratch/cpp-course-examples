include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/refs/heads/main.zip
  DOWNLOAD_EXTRACT_TIMESTAMP TRUE
)
FetchContent_MakeAvailable(googletest)

include(CTest)
include(googletest)

add_executable(str_lib_tests test_str_lib.cpp)
target_link_libraries(str_lib_tests PRIVATE str_lib GTest::gtest_main)

gtest_discover_tests(str_lib_tests) 