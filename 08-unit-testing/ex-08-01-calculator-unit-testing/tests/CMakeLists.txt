# Create tests
add_executable(tests-ex-08-01-calculator
    test_calculator.cpp
)
target_link_libraries(tests-ex-08-01-calculator
    PRIVATE
    lib-ex-08-01-calculator
    GTest::gtest_main
    spdlog::spdlog
)

# Register tests
include(CTest)
include(GoogleTest)
gtest_discover_tests(tests-ex-08-01-calculator)
