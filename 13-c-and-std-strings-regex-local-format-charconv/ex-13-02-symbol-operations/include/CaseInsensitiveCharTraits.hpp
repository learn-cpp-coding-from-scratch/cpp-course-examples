#pragma once

#ifndef CASE_INSENSITIVE_CHAR_TRAITS_HPP
#define CASE_INSENSITIVE_CHAR_TRAITS_HPP

//
#include <iostream>
#include <string>
#include <cctype>

// Пользовательские свойства символов для нечувствительности к регистру
// Cоздание собственного типа строки CiString = std::basic_string<char, CaseInsensitiveCharTraits>,
// который игнорирует регистр при сравнении, путем определения своего класса свойств символов.
struct CaseInsensitiveCharTraits : public std::char_traits<char>
{
    static char to_upper(char ch);
    static bool eq(char c1, char c2);
    static bool lt(char c1, char c2);
    static int compare(const char *s1, const char *s2, size_t n);
    static const char *find(const char *s, size_t n, char a);
};

// Определяем новый тип строки
using CiString = std::basic_string<char, CaseInsensitiveCharTraits>;

// Перегрузка оператора вывода для удобства
std::ostream &operator<<(std::ostream &os, const CiString &str);


#endif // CASE_INSENSITIVE_CHAR_TRAITS_HPP