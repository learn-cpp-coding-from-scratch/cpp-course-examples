# Create tests
add_executable(tests-ex-12-01-stdio
    test_demo_stdio.cpp
)
target_link_libraries(tests-ex-12-01-stdio
    PRIVATE
    lib-ex-12-01-stdio
    GTest::gtest_main
    spdlog::spdlog
)

# Register tests
gtest_discover_tests(tests-ex-12-01-stdio)
