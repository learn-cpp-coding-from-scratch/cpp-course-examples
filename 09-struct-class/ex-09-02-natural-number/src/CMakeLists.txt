add_library(lib-ex-09-02-number NaturalNumber.cpp)
add_executable(app-ex-09-02-number main.cpp)
target_link_libraries(app-ex-09-02-number lib-ex-09-02-number)