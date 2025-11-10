add_library(lib-ex-09-01-variant Variant.cpp)
add_executable(app-ex-09-01-variant main.cpp)
target_link_libraries(app-ex-09-01-variant lib-ex-09-01-variant)