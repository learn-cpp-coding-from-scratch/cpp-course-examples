#include <type_traits>
#include <string>
#include <iostream>

#include "symbol_properties.hpp"

int main()
{

    //Для проверки категорий типов используются метафункции из заголовка<type_traits> :
    static_assert(std::is_trivial_v<int>);
    static_assert(std::is_trivially_copyable_v<int>);
    static_assert(std::is_standard_layout_v<int>);

    std::string s = "Привет";
    std::wstring ws = L"Привет";
    std::u16string u16s = u"Привет";
    std::u32string u32s = U"Привет";

    // char_traits работает внутри basic_string
    // Метод length() работает только с null - terminated строками типов char и wchar_t.
    // Для char16_t и char32_t это не гарантировано

    std::cout << std::char_traits<char>::length(s.c_str())
        << std::endl; // 5

    std::wcout << std::char_traits<wchar_t>::length(ws.c_str())
               << std::endl; // 6

    // Для char16_t и char32_t - лучше использовать std::u16string и std::u32string
    std::cout << u16s.length() << std::endl; // используйте .length() строки
    std::cout << u32s.length() << std::endl;


    // Demo
    demoCharProperties();
    demoWcharProperties();

    // Здесь \033[1;32m — зелёный жирный текст, \033[0m — сброс.
    std::cout << "\033[1;32mAPP completed successfully\033[0m\n";

    return 0;
}