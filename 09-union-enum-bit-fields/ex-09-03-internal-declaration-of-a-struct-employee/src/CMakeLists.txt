add_library(lib-ex-09-03-statistics statistics.cpp)
add_executable(app-ex-09-03-internal-declaration main.cpp)
target_link_libraries(app-ex-09-03-internal-declaration lib-ex-09-03-statistics)