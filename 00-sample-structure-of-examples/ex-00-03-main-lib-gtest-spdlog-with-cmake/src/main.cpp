#include <iostream>
#include "functions.hpp"

// Compile time log levels - для того чтобы макросы SPDLOG_TRACE, SPDLOG_DEBUG и другие работали,
// необходимо определить уровень логирования на этапе компиляции до подключения
// заголовочного файла spdlog.h.
// По умолчанию SPDLOG_ACTIVE_LEVEL установлен в INFO,
// поэтому макросы TRACE и DEBUG вырезаются из кода препроцессором(становятся пустыми).

// Define the active log level before including spdlog
#define SPDLOG_ACTIVE_LEVEL SPDLOG_LEVEL_TRACE

#include "spdlog/spdlog.h"

    int main() {


    // Using spdlog to log a message
    spdlog::info("Welcome to spdlog!");
    spdlog::error("Some error message with arg: {}", 1);

    spdlog::warn("Easy padding in numbers like {:08d}", 12);
    spdlog::critical("Support for int: {0:d};  hex: {0:x};  oct: {0:o}; bin: {0:b}", 42);
    spdlog::info("Support for floats {:03.2f}", 1.23456);
    spdlog::info("Positional args are {1} {0}..", "too", "supported");
    spdlog::info("{:<30}", "left aligned");

    spdlog::set_level(spdlog::level::trace); // Set *global* log level to trace
    spdlog::debug("This message should be displayed..");

    // change log pattern
    spdlog::set_pattern("[%H:%M:%S %z] [%n] [%^---%L---%$] [thread %t] %v");

    // Compile time log levels
    // Note that this does not change the current log level, it will only
    // remove (depending on SPDLOG_ACTIVE_LEVEL) the call on the release code.
    SPDLOG_TRACE("********* Some trace message");
    SPDLOG_DEBUG("********* Some debug message with param {}", 42);

    // Using the add function from functions.hpp
    int a = 5;
    int b = 3;
    int result = add(a, b);
    std::cout << "The sum of " << a << " and " << b << " is " << result << std::endl;

    return 0;
}