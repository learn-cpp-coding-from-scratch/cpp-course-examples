#include "functions.hpp"
#include "spdlog/spdlog.h"

int add(int a, int b) {
    spdlog::trace("Add function called with arguments: {} and {}.", a, b);
    spdlog::debug("Debug:  {} +  {} = {}", a, b, a + b);
    return a + b;
}