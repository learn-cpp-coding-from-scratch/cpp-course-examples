#include<iostream>
#include<string>
#include "str_lib.hpp"

int main() {
    std::string input;
    std::cout << "Введите строку для проверки: ";
    std::getline(std::cin, input);

    if (isPalindrome(input)) {
        std::cout << "-> Строка \"" << input << "\" является палиндромом." << std::endl;
    } else {
        std::cout << "-> Строка \"" << input << "\" не является палиндромом." << std::endl;
    }

    return 0;
}