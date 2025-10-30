add_library(number NaturalNumber.cpp)
add_executable(number_app main.cpp)
target_link_libraries(number_app number)