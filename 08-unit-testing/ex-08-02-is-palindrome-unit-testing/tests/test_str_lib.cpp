#include <gtest/gtest.h>
#include <string>
#include <iostream>

#include "../src/str_lib.hpp"

// Предполагаем, что функция isPalindrome объявлена в отдельном заголовочном файле
// или добавлена в область видимости для тестов.
// Для простоты в этом примере мы могли бы включить весь файл palindrome.cpp
// или объявить прототип:
// bool isPalindrome(const std::string& str);

// --- Группа тестов для функции isPalindrome ---
TEST(PalindromeTest, HandlesSimplePalindromes) {
    // Проверка обычных палиндромов
    EXPECT_TRUE(isPalindrome("radar"));
    EXPECT_TRUE(isPalindrome("level"));
}

TEST(PalindromeTest, HandlesNonPalindromes) {
    // Проверка строк, которые не являются палиндромами
    EXPECT_FALSE(isPalindrome("hello"));
    EXPECT_FALSE(isPalindrome("world"));
}

TEST(PalindromeTest, HandlesCaseInsensitivity) {
    // Проверка игнорирования регистра
    EXPECT_TRUE(isPalindrome("Madam"));
    EXPECT_TRUE(isPalindrome("Racecar"));
}

TEST(PalindromeTest, HandlesSpacesAndPunctuation) {
    // Проверка игнорирования пробелов, знаков препинания и небуквенных символов
    EXPECT_TRUE(isPalindrome("A man, a plan, a canal: Panama"));
    EXPECT_TRUE(isPalindrome("Was it a car or a cat I saw?"));
    EXPECT_TRUE(isPalindrome("Eva, can I see bees in a cave?"));
}

TEST(PalindromeTest, HandlesEmptyOrSingleCharacter) {
    // Проверка граничных случаев
    EXPECT_TRUE(isPalindrome(""));      // Пустая строка
    EXPECT_TRUE(isPalindrome("a"));     // Строка из одного символа
    EXPECT_TRUE(isPalindrome(".,!"));   // Строка только из знаков препинания
}

// --- Дополнительные примеры GTest для строковых операций ---

// 1. Тестирование равенства строк (ASSERT_EQ)
TEST(StringEqualityTest, HandlesStringComparison) {
    std::string s1 = "C++";
    std::string s2 = "C++";
    std::string s3 = "Java";
    
    // Проверка, что s1 и s2 идентичны
    ASSERT_EQ(s1, s2);
    // Проверка, что s1 и s3 не равны
    ASSERT_NE(s1, s3);
}

// 2. Тестирование префиксов и суффиксов (EXPECT_TRUE с find)
TEST(StringSubstringTest, ChecksForSubstringPresence) {
    std::string full = "This is a C++ programming course.";
    std::string sub = "programming";

    // Проверяем, что подстрока найдена (find возвращает не std::string::npos)
    EXPECT_NE(full.find(sub), std::string::npos) << "Подстрока 'programming' должна быть найдена.";
    
    // Проверяем отсутствие подстроки
    EXPECT_EQ(full.find("Python"), std::string::npos);
}

// 3. Тестирование длины строки
TEST(StringLengthTest, ChecksExpectedLength) {
    std::string test_str = "abcde";
    // Проверяем, что длина строки равна ожидаемому значению
    EXPECT_EQ(test_str.length(), 5);
}

// Если не используете CMake, вам может потребоваться основной блок main для GTest
/*
int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
*/