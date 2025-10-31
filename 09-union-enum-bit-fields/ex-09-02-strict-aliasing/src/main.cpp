/**
 * Доступ к битам вещественного числа.
 * Реализуем вычисление модуля вещественного числа путём ручного сброса старшего бита.
 */
 
#include <iostream>
#include <string>

float funkyFloatAbs(float a) {
    // неопределенное поведение
    unsigned int tmp = *(unsigned int *)&a;
    tmp &= 0x7fffffff;
    std::cout << "if get as the int value = " << tmp << "\n";
    return *(float *)&tmp;
}


int main() {
  float value = -42.78;
  float tmp = funkyFloatAbs(value);
  std::cout << "Float value: " << tmp << "\n";
}