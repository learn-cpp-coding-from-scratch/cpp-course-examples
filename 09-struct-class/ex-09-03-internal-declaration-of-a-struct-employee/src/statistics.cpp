#include <iostream>
#include <cmath>

std::tuple<double, double, double> processDataSet(const std::vector<double>& data) {
    // ----------------------------------------------------------------------
    // Локальная структура для агрегации промежуточных результатов
    // ----------------------------------------------------------------------
    struct Stats {
        double sum = 0.0;
        double average = 0.0;
        double min = 0.0;
        // Мы можем добавить здесь приватные детали, если бы это был класс
    };

    Stats s;

    // Вычисляем статистику
    if (!data.empty()) {
        s.min = data[0];
        for (double val : data) {
            s.sum += val;
            if (val < s.min) {
                s.min = val;
            }
        }
        s.average = s.sum / data.size();
    }
    
    // ... используем s для дальнейших действий внутри функции
   return {s.sum, s.average, s.min};
}

