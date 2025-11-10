#pragma once

#ifndef NATURAL_NUMBER_H
#define NATURAL_NUMBER_H

#include<string>

struct NaturalNumber{
    unsigned int value = 1;

    std::string toString() const;

};

NaturalNumber theNextNumber(NaturalNumber& other);

#endif //NATURAL_NUMBER_H

