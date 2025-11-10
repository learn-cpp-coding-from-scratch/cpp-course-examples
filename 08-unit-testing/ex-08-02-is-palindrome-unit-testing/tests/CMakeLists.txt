# Create tests
add_executable(tests-ex-08-02-str
    test_str_lib.cpp)

target_link_libraries(tests-ex-08-02-str
    PRIVATE
    lib-ex-08-02-str 
    GTest::gtest_main
    spdlog::spdlog
)

# Register tests
include(CTest)
include(GoogleTest)
gtest_discover_tests(tests-ex-08-02-str)