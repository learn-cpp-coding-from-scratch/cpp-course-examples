#include <iostream>

#include "demo_stdio.hpp"

int main() {
    Student student = readStudentInfo();
    printStudentInfo(student);
    int status = writeToFile(student);
    std::cout << "Data written to file with status: " << status << std::endl;
    return status;
}   