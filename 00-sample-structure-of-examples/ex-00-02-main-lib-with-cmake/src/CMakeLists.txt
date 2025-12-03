# --- Create library for the application ---
add_library(lib-ex-00-02-main-lib-with-cmake 
    functions.cpp
)

# --- Create app - main executable target ---
add_executable(app-ex-00-02-main-lib-with-cmake
    main.cpp
)

# --- Link library to the executable target ---
target_link_libraries(app-ex-00-02-main-lib-with-cmake
    PUBLIC 
       lib-ex-00-02-main-lib-with-cmake
)

# --- Add path to the header files (.hpp) if the library has any ---
target_include_directories(lib-ex-00-02-main-lib-with-cmake
    PUBLIC
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/../include>
)
