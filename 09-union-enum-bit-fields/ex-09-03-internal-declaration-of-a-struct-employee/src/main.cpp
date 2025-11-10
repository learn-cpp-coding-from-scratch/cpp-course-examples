#include <iostream>
#include <string>
#include "statistics.hpp"

int main() {
// ----------------------------------------------------------------------
// Внутреннее объявление структуры Employee
// ----------------------------------------------------------------------
struct Employee {
    short id;
    int age;
    float salary;

    std::string toString() {
        return "Employee[id: " + std::to_string(id)
            + ", age: " + std::to_string(age)
            + ", salary: " + std::to_string(salary) + "]";
    }
};
// ----------------------------------------------------------------------
// Внутреннее объявление структуры Company
// ----------------------------------------------------------------------
struct Company {
    Employee CEO;
    int numberOfEmployees;

    std::string toString() {
        return "Company[\nCEO: " + CEO.toString()
               + ",\n numberOfEmployees: " 
               + std::to_string(numberOfEmployees) + "]\n";
    }
}; 
// ----------------------------------------------------------------------
// Работа со структурами, объявленными внутри функции
// ----------------------------------------------------------------------
Company myCompany {{3, 35, 2050.0f}, 7};
std::cout << myCompany.toString();

std::cout << "myCompany.CEO.id = " << myCompany.CEO.id << '\n';

// ----------------------------------------------------------------------
// Пример работы с функцией, у которой свое внутренняя структура
// ----------------------------------------------------------------------
std::vector<double> numbers = {10.0, 20.0, 5.0, 15.0};
std::tuple<double, double, double> stat =  processDataSet(numbers);
std::cout << "Sum:" << std::get<0>(stat) 
    << ", Local Average: " << std::get<1>(stat) 
    << ", Min: " << std::get<2>(stat) << std::endl;

return 0;
}