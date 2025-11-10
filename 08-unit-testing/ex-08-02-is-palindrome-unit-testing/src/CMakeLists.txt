add_library(lib-ex-08-02-str str_lib.cpp)
add_executable(app-ex-08-02-str main.cpp)
target_link_libraries(app-ex-08-02-str lib-ex-08-02-str)