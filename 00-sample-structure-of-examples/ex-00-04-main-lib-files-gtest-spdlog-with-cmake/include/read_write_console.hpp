#pragma once

#ifndef READ_WRITE_CONSOLE_HPP
#define READ_WRITE_CONSOLE_HPP

#include <string>
#include <vector>

std::vector<std::string> readFromConsole(int numberOfLines);
void writeToConsole(const std::vector<std::string>& lines);

#endif // READ_WRITE_CONSOLE_HPP