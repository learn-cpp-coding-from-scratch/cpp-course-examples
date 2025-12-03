# --- Create test-app - executable target ---
add_executable(tests-ex-00-04-main-lib-files-gtest-spdlog-with-cmake
    tests_functions.cpp
)

# --- Link library and gtest to the tests executable target ---
target_link_libraries(tests-ex-00-04-main-lib-files-gtest-spdlog-with-cmake
    PRIVATE
    lib-ex-00-04-main-lib-files-gtest-spdlog-with-cmake 
    GTest::gtest_main
    spdlog::spdlog
)

# --- Register tests of the target ---
gtest_discover_tests(tests-ex-00-04-main-lib-files-gtest-spdlog-with-cmake)