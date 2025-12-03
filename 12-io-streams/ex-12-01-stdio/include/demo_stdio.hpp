#pragma once

#ifndef DEMO_STDIO_HPP
#define DEMO_STDIO_HPP
#include <string>

struct Student {
    std::string name;
    int age;
    double gpa; // GPA (Grade Point Average) – средний балл
};

void printStudentInfo(const Student& student);
Student readStudentInfo();

int writeToFile(const Student& student);

#endif // DEMO_STDIO_HPP