#include <iostream>
#include <string>
#include <string_view>
#include <charconv>
#include <cstring>
#include "CaseInsensitiveCharTraits.hpp"

/**
 * Пример демонстрирует низкоуровневые операции со строками через std::char_traits: 
 * сравнение, поиск, копирование и перемещение памяти.
 * Также показано использование пользовательских символов с нечувствительностью к регистру.
 */

int main()
{
     using Traits = std::char_traits<char>;

     std::cout << "------ Example of low-level character operations using std::char_traits:" << std::endl;

     const char *text = "Hello World";

     // 1.a) assign – присвоение символа
     char c1, c2 = 'A';
     Traits::assign(c1, c2);
     std::cout << "assign: " << c1 << std::endl; // A

     // 1.b) Заполнение (assign) - аналог memset
     char buffer[7] = "Hello";
     Traits::assign(buffer, 5, '*');
     buffer[5] = '\0';
     std::cout << "assigned string: " << buffer << std::endl;

     // 2. eq – сравнение символов
     std::cout << "eq('A','A'): " << Traits::eq('A', 'A') << std::endl; // true
     // 3. lt – сравнение <
     std::cout << "lt('A','B'): " << Traits::lt('A', 'B') << std::endl; // true

     // 4. move – перемещение последовательности
     char buffer1[20] = "Hello";
     Traits::move(buffer1 + 1, buffer1, 4);  // перекрывающиеся области
     std::cout << "move: " << buffer1 << std::endl; // HHell

     // 5. copy – копирование последовательности
     // аналог memcpy, области не должны перекрываться
     char buffer2[20];
     Traits::copy(buffer2, text, 5);
     buffer2[5] = '\0';
     std::cout << "copy: " << buffer2 << std::endl; // Hello

     // 6. compare – лексикографическое сравнение
     std::cout << "compare(\"abc\",\"abd\",3): "
          << Traits::compare("abc", "abd", 3) << std::endl; // -1
     // 7. length – длина строки
     std::cout << "length(\"Hello World\"): "
          << Traits::length(text) << std::endl; // 11

     // 8. find – поиск символа
     const char *found = Traits::find(text, Traits::length(text), 'W');
     std::cout << "find 'W': " << (found ? found : "not found") << std::endl; // World...
     // 9. to_char_type – int -> char
     std::cout << "to_char_type(65): "
          << Traits::to_char_type(65) << std::endl; // 'A'

     // 10. to_int_type – char -> int
     std::cout << "to_int_type('A'): "
          << Traits::to_int_type('A') << std::endl; // 65
     // 11. eq_int_type – сравнение int_type
     std::cout << "eq_int_type(65,65): "
          << Traits::eq_int_type(65, 65) << std::endl; // true

     // 12. eof – значение EOF
     std::cout << "eof(): " << Traits::eof() << std::endl;

     // 13. not_eof – проверка EOF
     std::cout << "not_eof(65): "
          << Traits::not_eof(65) << std::endl; // 65
    
     
     // Пример использования пользовательских символов с нечувствительностью к регистру
     std::cout << "----- Example of case-insensitive characters:" << std::endl;
     CiString s1 = "Hello";
     CiString s2 = "hello";

     if (s1 == s2)
     {
          std::cout << s1 << " is equal to " << s2 << " (case-insensitive)\n";
     }

     if (s1.find('E') != CiString::npos)
     {
          std::cout << "Found 'E' in " << s1 << std::endl;
     }

     return 0;
}
