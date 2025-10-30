add_library(str_lib str_lib.cpp)
add_executable(str_lib_app main.cpp)
target_link_libraries(str_lib_app str_lib)