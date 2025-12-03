//CaseInsensitiveCharTraits.cpp
#include <iostream>
#include <string>
#include <cctype>
#include "CaseInsensitiveCharTraits.hpp"

char CaseInsensitiveCharTraits::to_upper(char ch)
{
    return std::toupper((unsigned char)ch);
}
bool CaseInsensitiveCharTraits::eq(char c1, char c2)
{
    return to_upper(c1) == to_upper(c2);
}

bool CaseInsensitiveCharTraits::lt(char c1, char c2)
{
    return to_upper(c1) < to_upper(c2);
}

int CaseInsensitiveCharTraits::compare(const char *s1, const char *s2, size_t n)
{
    while (n-- != 0)
    {
        if (to_upper(*s1) < to_upper(*s2))
            return -1;
        if (to_upper(*s1) > to_upper(*s2))
            return 1;
        ++s1;
        ++s2;
    }
    return 0;
}

const char* CaseInsensitiveCharTraits::find(const char* s, size_t n, char a)
{
    while (n-- > 0) {
        if (to_upper(*s) == to_upper(a)) {
            return s;
        }
        ++s;
    }
    return nullptr;
}

// Перегрузка оператора вывода для удобства
std::ostream& operator<<(std::ostream& os, const CiString& str) {
    return os << str.c_str();
}
