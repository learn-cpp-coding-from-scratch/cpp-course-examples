
/**
 * Универсальный Тип Variant
 * Объект, который может быть либо целым числом, либо числом с плавающей точкой, либо указателем, 
 * но никогда не всеми сразу.
 * При использовании union вы несете ответственность за отслеживание того, какой член в данный момент активен. 
 * Для безопасной работы union часто объединяют со структурой (struct) и полем-тегом (tag), чтобы создать 
 * безопасный тип std::variant.
 */
#include <iostream>
#include <string>
#include "Variant.hpp"

// Объединение для хранения одного из трех типов данных
union DataVariant {
    int int_value;      // 4 байта (например)
    double double_value; // 8 байтов (например)
    void* ptr_value;    // 8 байтов (например)
};
// Размер DataVariant будет равен размеру самого большого члена (double_value или ptr_value), 
// то есть 8 байтам, а не 20 байтам, как в struct.

void printData(DataVariant data, char type) {
    std::cout << "Raw Memory Size: " << sizeof(data) << " bytes" << std::endl;
    
    // Интерпретируем одну и ту же память в зависимости от флага 'type'
    if (type == 'i') {
        std::cout << "Value as Int: " << data.int_value << std::endl;
    } else if (type == 'd') {
        std::cout << "Value as Double: " << data.double_value << std::endl;
    } else if (type == 'p') {
        std::cout << "Value as Pointer: " << data.ptr_value << std::endl;
    } else {
        std::cout << "Unknown type." << std::endl;
    }
}

int main() {
    DataVariant dv;
    
    // 1. Используем как целое число
    dv.int_value = 42;
    printData(dv, 'i'); // Выведет: Value as Int: 42

    // 2. Используем как число с плавающей точкой
    // *Предыдущее значение int_value теперь перезаписано.*
    dv.double_value = 3.14159;
    printData(dv, 'd'); // Выведет: Value as Double: 3.14159
    
    // Внимание: Чтение не того члена, который был записан, называется "Type Punning"
    // и приводит к неопределенному поведению (UB) в C++ за пределами POD-типов.
    std::cout << "\nWARNING: Reading wrong member (UB): " << dv.int_value << std::endl;

    //--------------------------------------------------------
    // stuct Variant
    //--------------------------------------------------------
    std::cout << "--- demo data variant ---\n";
    
    Variant data;
    
    // 1. Безопасная установка и получение int
    data.setInt(12345);
    std::cout << "Set type: INT. Value: " << data.getInt() << std::endl;

    // 2. Безопасная установка и получение float
    data.setFloat(3.14159f);
    std::cout << "Set type: FLOAT. Value: " << data.getFloat() << std::endl;

    // --- Демонстрация Ошибок и Небезопасного Доступа ---

    // 3. Попытка безопасного чтения неверного типа (Вызовет исключение)
    std::cout << "\nAttempt to read INT when FLOAT is stored:\n";
    try {
        int retrieved_int = data.getInt();
        std::cout << "Received: " << retrieved_int << " (ERROR, shouldn't work)" << std::endl;
    } catch (const std::runtime_error& e) {
        std::cerr << "Caught the expected error: " << e.what() << std::endl;
    }

    // 4. Небезопасный доступ напрямую к объединению (Неопределенное Поведение)
    // В этом примере мы не используем getInt/getFloat, игнорируя тег.
    std::cout << "\nDemonstration of unsafe access (Type Punning):\n";
    // Активный тип - float, но мы читаем intValue напрямую
    int bad_value = data.value.intValue; 
    
    std::cout << "The active FLOAT (" << data.getFloat() 
              << ") is interpreted as INT: " << bad_value << std::endl;
    std::cout << "(The resulting number is a float bit structure read as an int)." << std::endl;

    return 0;
}