#include <stdexcept>
#include "Variant.hpp"

void Variant::setInt(int i) {
        value.intValue = i;
        storedType = INT_T; // Обновляем тег
}
    
int Variant::getInt() const {
        // Проверка безопасности:
        if (storedType != INT_T) {
            throw std::runtime_error("Variant currently holds float, not int!");
        }
        return value.intValue;
}

void Variant::setFloat(float i) {
        value.floatValue = i;
        storedType = FLOAT_T; // Обновляем тег
}
    
float Variant::getFloat() const {
        // Проверка безопасности:
        if (storedType != FLOAT_T) {
            throw std::runtime_error("Variant currently holds float, not int!");
        }
        return value.intValue;
}