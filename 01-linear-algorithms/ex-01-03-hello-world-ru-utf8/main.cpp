#include  <iostream> 
#include <locale>

int  main() {

    system("chcp 65001"); // настраиваем кодировку консоли. 65001 - это консольная кодовая страница для UTF-8.

    std::locale::global(std::locale("ru_RU.UTF-8"));
    std::wcout.imbue(std::locale());
    std::wcin.imbue(std::locale());

    std::wstring name;

    std::wcout << L"Компьютер: Привет, мир!" << std::endl;
    std::wcout << L"Человек, как тебя зовут?" << std::endl;

    
    std::wcin >> name;
    std::wcout << L"Привет, " << name << "!";

    return 0;
}