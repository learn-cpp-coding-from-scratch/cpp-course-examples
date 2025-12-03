# --- Create library for the application ---
add_library(lib-ex-00-03-main-lib-gtest-spdlog-with-cmake 
    functions.cpp
)

# --- Add path to the header files (.hpp) if the library has any ---
target_include_directories(lib-ex-00-03-main-lib-gtest-spdlog-with-cmake
    PUBLIC
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/../include>
)

# --- Link spdlog to the library ---
target_link_libraries(lib-ex-00-03-main-lib-gtest-spdlog-with-cmake
    PUBLIC
        spdlog::spdlog
)

# --- Create app - main executable target ---
add_executable(app-ex-00-03-main-lib-gtest-spdlog-with-cmake
    main.cpp
)

# --- Link library to the executable target ---
target_link_libraries(app-ex-00-03-main-lib-gtest-spdlog-with-cmake
    PUBLIC 
       lib-ex-00-03-main-lib-gtest-spdlog-with-cmake
       spdlog::spdlog
)

