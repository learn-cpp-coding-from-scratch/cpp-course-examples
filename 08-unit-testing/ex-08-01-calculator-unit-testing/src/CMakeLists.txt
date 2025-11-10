# Create library for calculator
add_library(lib-ex-08-01-calculator calculator.cpp)

# Create main executable
add_executable(app-ex-08-01-calculator main.cpp)
target_link_libraries(app-ex-08-01-calculator lib-ex-08-01-calculator)
