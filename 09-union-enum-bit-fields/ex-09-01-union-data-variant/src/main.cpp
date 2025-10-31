#include <iostream>
#include <string>

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

    return 0;
}