# --- Локализованное копирование папки data ---
file(COPY "${CMAKE_CURRENT_SOURCE_DIR}/data"
     DESTINATION "${CMAKE_BINARY_DIR}/bin")
# ---------------------------------------------

add_subdirectory(src)
add_subdirectory(tests)