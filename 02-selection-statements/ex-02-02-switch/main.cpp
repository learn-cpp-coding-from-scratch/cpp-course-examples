// ============================================
// SELECTION STATEMENTS IN C++
// switch statement examples
// ============================================
// THEORY: основные **ограничения для условия в switch** в C++:
/**
## 1. **Типы данных**
Switch принимает только:
- ✅ int, short, long, char
- ✅ enum (перечисления)
- ✅ bool (технически да, но бессмысленно)
- ❌ **НЕ работает** с: float, double, string, массивами, объектами

```cpp
// ❌ ОШИБКА - нельзя использовать string
string name = "John";
switch (name) { ... }  // Не скомпилируется!

// ❌ ОШИБКА - нельзя использовать float
float price = 10.5;
switch (price) { ... }  // Не скомпилируется!

// ✅ ПРАВИЛЬНО
int choice = 1;
switch (choice) { ... }  // Работает
```

## 2. **Case метки должны быть константами**
```cpp
const int OPTION_A = 1;
int x = 2;

switch (choice) {
    case OPTION_A:  // ✅ Константа - OK
        break;
    case 5:         // ✅ Литерал - OK
        break;
    case x:         // ❌ ОШИБКА - переменная!
        break;
}
```

## 3. **Нельзя использовать диапазоны** (в стандартном C++)
```cpp
// ❌ Так нельзя в стандартном C++
switch (age) {
    case 1...17:    // Ошибка!
        break;
}

// ✅ Нужно перечислять или использовать if
if (age >= 1 && age <= 17) { ... }
```

## 4. **Каждый case должен быть уникальным**
```cpp
switch (x) {
    case 1:  // ✅
        break;
    case 1:  // ❌ ОШИБКА - дубликат!
        break;
}
```

**Вывод:** Для строк, вещественных чисел и сложных условий используйте **if-else**! 

Нужны примеры обхода этих ограничений?
*/

#include <iostream>
#include <string>

// ============================================
// 1. SWITCH STATEMENT (integer)
// ============================================
void switchIntExample() {
    int day = 3;
    
    switch (day) {
        case 1:
            std::cout << "Monday" << std::endl;
            break;
        case 2:
            std::cout << "Tuesday" << std::endl;
            break;
        case 3:
            std::cout << "Wednesday" << std::endl;
            break;
        case 4:
            std::cout << "Thursday" << std::endl;
            break;
        case 5:
            std::cout << "Friday" << std::endl;
            break;
        case 6:
        case 7:
            std::cout << "Weekend!" << std::endl;
            break;
        default:
            std::cout << "Invalid day" << std::endl;
    }
}

// ============================================
// 2. SWITCH STATEMENT (char)
// ============================================
void switchCharExample() {
    char operation = '+';
    int a = 10, b = 5;
    
    switch (operation) {
        case '+':
            std::cout << "Result: " << (a + b) << std::endl;
            break;
        case '-':
            std::cout << "Result: " << (a - b) << std::endl;
            break;
        case '*':
            std::cout << "Result: " << (a * b) << std::endl;
            break;
        case '/':
            if (b != 0) {
                std::cout << "Result: " << (a / b) << std::endl;
            } else {
                std::cout << "Error: Division by zero" << std::endl;
            }
            break;
        default:
            std::cout << "Invalid operation" << std::endl;
    }
}

// ============================================
// 3. SWITCH WITH FALL-THROUGH
// ============================================
void switchFallThroughExample() {
    char grade = 'B';
    
    switch (grade) {
        case 'A':
        case 'B':
            std::cout << "Excellent!" << std::endl;
            break;
        case 'C':
            std::cout << "Good" << std::endl;
            break;
        case 'D':
            std::cout << "Passed" << std::endl;
            break;
        case 'F':
            std::cout << "Failed" << std::endl;
            break;
        default:
            std::cout << "Invalid grade" << std::endl;
    }
}

// ============================================
// MAIN FUNCTION
// ============================================
int main() {
    std::cout << "\n=== SWITCH (INTEGER) ===" << std::endl;
    switchIntExample();
    
    std::cout << "\n=== SWITCH (CHAR) ===" << std::endl;
    switchCharExample();
    
    std::cout << "\n=== SWITCH FALL-THROUGH ===" << std::endl;
    switchFallThroughExample();
    
    return 0;
}