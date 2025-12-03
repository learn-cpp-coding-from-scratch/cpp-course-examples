#include <iostream>
#include <cctype>  // для std::isalpha, std::toupper и т.д. (char)
#include <cwctype> // для std::iswalpha, std::towupper и т.д. (wchar_t)
#include <locale>  // для std::toupper(char, locale)

#include "symbol_properties.hpp"

bool isTrivialType(const std::type_info& type) {
    if (type == typeid(int) ||
        type == typeid(long) ||
        type == typeid(short) ||
        type == typeid(unsigned int) ||
        type == typeid(unsigned long) ||
        type == typeid(unsigned short) ||
        type == typeid(double) ||
        type == typeid(long double) ||
        type == typeid(float) ||
        type == typeid(char) ||
        type == typeid(wchar_t) ||
        type == typeid(char16_t) ||
        type == typeid(char32_t) ||
        type == typeid(bool))
    {
        return true;
    }
    return false;
}

void demoCharProperties() {
    std::cout << "--- char properties ---\n";
    char c = 'a';
    if (std::islower(c)) {
        std::cout << "'" << c << "' is lowercase.\n";
        c = std::toupper(c);
        std::cout << "Uppercased: '" << c << "'\n";
    }
    
    char d = '9';
    if (std::isdigit(d)) {
        std::cout << "'" << d << "' is a digit.\n";
    }

    // С использованием локали (корректно для не-ASCII в некоторых кодировках)
    std::locale loc("");
    char r = 'z';
    std::cout << "Locale toupper('z'): " << std::toupper(r, loc) << "\n";
}

void demoWcharProperties() {
    std::cout << "\n--- wchar_t properties ---\n";
    wchar_t wc = L'я'; // Кириллический символ (требует корректной локали терминала)
    
    // Примечание: для корректной работы с кириллицей нужна настройка локали
    std::setlocale(LC_ALL, ""); 
    
    if (std::iswlower(wc)) {
        std::wcout << L"'" << wc << L"' is lowercase wide char.\n";
        wc = std::towupper(wc);
        std::wcout << L"Uppercased: '" << wc << L"'\n";
    }
}
