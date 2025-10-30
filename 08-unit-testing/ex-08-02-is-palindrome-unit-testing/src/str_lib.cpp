#include <iostream>
#include <string>
#include <algorithm>
#include <cctype>

/**
 * @brief Проверяет, является ли строка палиндромом, игнорируя регистр
 * и небуквенные символы.
 * @param str Входная строка.
 * @return true, если строка является палиндромом, иначе false.
 */
bool isPalindrome(const std::string& str) {
    std::string cleanStr;
    
    // 1. Очистка и преобразование в нижний регистр
    for (char c : str) {
        if (std::isalnum(c)) { // Проверяем, является ли символ буквой или цифрой
            cleanStr += std::tolower(c);
        }
    }

    if (cleanStr.empty()) {
        return true; // Пустая строка или строка из одних знаков препинания считается палиндромом
    }

    // 2. Проверка палиндрома
    size_t left = 0;
    size_t right = cleanStr.length() - 1;

    while (left < right) {
        if (cleanStr[left] != cleanStr[right]) {
            return false;
        }
        ++left;
        --right;
    }
    return true;
}