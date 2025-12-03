#include <iostream>
#include <sstream>

int main()
{
    // Обычный iostream (char)
    std::ostream *io = &(std::cout);
    *io << "Hello, Алисаааа!\n";

    // Широкий поток (wchar_t)
    std::wostringstream wss;
    std::basic_ostream<wchar_t> *wio = &wss;
    *wio << L"ответ: " << L"Привет, Алиса!\n";
    std::wcout << wss.str();

    return 0;
}
