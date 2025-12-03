#pragma once

#ifndef READ_WRITE_FILES_HPP
#define READ_WRITE_FILES_HPP

#include <string>
#include <vector>

void writeToFile(const std::string& fileName, const std::vector<std::string>& lines);
std::vector<std::string> readFromFile(const std::string& fileName);

#endif // READ_WRITE_FILES_HPP