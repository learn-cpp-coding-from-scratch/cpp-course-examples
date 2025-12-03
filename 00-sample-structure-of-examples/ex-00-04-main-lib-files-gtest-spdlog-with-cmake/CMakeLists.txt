# --- Copy data files to binary directory ---
file(COPY "${CMAKE_CURRENT_SOURCE_DIR}/data"
     DESTINATION "${CMAKE_BINARY_DIR}/bin")
# -------------------------------------------

# --- Apps (main and tests) with gtest and spdlog ---
# ---  Source files of the main executable target ---
add_subdirectory(src)
# ---  Source files of the tests executable target ---
add_subdirectory(tests)