#include <iostream>
#include <string>
#include "NaturalNumber.hpp"

std::string NaturalNumber::toString() const {
    return std::to_string(value);
}

NaturalNumber theNextNumber(NaturalNumber& other) {
    NaturalNumber tmp {++other.value};
    return tmp;
}

