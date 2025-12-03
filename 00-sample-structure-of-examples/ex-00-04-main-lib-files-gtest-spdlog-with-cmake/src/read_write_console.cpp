#include "spdlog/spdlog.h"
#include <iostream>
#include <string>
#include <vector>

#include "read_write_console.hpp"

std::vector<std::string> readFromConsole(int numberOfLines) {
    spdlog::trace("readFromConsole called with numberOfLines: {}", numberOfLines);
    std::vector<std::string> lines;
    std::string line;
    for (int i = 0; i < numberOfLines; ++i) {
        std::cout << "Enter line " << (i + 1) << ": ";
        std::getline(std::cin, line);
        lines.push_back(line);
    }
    spdlog::debug("Successfully read {} lines from console.", lines.size());
    return lines;
}

void writeToConsole(const std::vector<std::string> &lines)
{
    spdlog::trace("writeToConsole called.");
    for (const auto &line : lines)
    {
        std::cout << line << std::endl;
    }
    spdlog::debug("Successfully wrote {} lines to console.", lines.size());
}