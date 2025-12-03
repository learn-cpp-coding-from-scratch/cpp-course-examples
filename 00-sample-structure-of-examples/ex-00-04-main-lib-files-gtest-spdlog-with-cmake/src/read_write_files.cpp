
#include "spdlog/spdlog.h"
#include <fstream>
#include <string>
#include <vector>

#include "read_write_files.hpp"

std::vector<std::string> readFromFile(const std::string &fileName)
{
    spdlog::trace("readFromFile called with filename: {}", fileName);
    std::ifstream inFile(fileName);
    if (!inFile)
    {
        spdlog::error("Failed to open file {} for reading.", fileName);
        throw std::runtime_error("Could not open file for reading");
    }
    std::vector<std::string> lines;
    std::string line;
    while (std::getline(inFile, line))
    {
        lines.push_back(line);
    }
    spdlog::debug("Successfully read {} lines from file {}.", lines.size(), fileName);
    return lines;
}

void writeToFile(const std::string& fileName, const std::vector<std::string>& lines) {
    spdlog::trace("writeToFile called with filename: {}", fileName);
    std::ofstream outFile(fileName);
    if (!outFile) {
        spdlog::error("Failed to open file {} for writing.", fileName);
        throw std::runtime_error("Could not open file for writing");
    }
    for (const auto& line : lines) {
        outFile << line << '\n';
    }
    spdlog::debug("Successfully wrote {} lines to file {}.", lines.size(), fileName);
}