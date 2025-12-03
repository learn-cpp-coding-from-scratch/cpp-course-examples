#include <stdio.h>
#include "demo_stdio.hpp"

/**
 * @brief Prints student information in the following format: "Student name: <name>, age: <age>, GPA: <gpa>\n"
 * @param student Student object with name, age and GPA
 */
void printStudentInfo(const Student &student)
{
    // Используем printf для форматированного вывода
    printf("Student name: %s, age: %d, GPA: %.2f\n", student.name.c_str(), student.age, student.gpa);
}

/**
 * @brief Reads student information from stdin and returns it as a Student object.
 * Reads student name (string with max length 20), age (integer), and GPA (floating-point number).
 * Prints out the entered information.
 * @return Student object with name, age, and GPA
 */
Student readStudentInfo()
{
    Student student;
    char nameBuffer[21];
    printf("Enter student name: ");
    scanf("%20s", nameBuffer); // читаем строку с ограничением длины
    student.name = std::string(nameBuffer);

    printf("Enter student age: ");
    scanf("%d", &student.age); // читаем целое число

    printf("Enter student GPA: ");
    scanf("%lf", &student.gpa); // читаем число с плавающей точкой

    printf("You entered:\nstudent name: %s\nstudent age: %d\nstudent GPA: %.2f\n", student.name.c_str(), student.age, student.gpa);
    return student;
}

// Пример работы с файлами через stdio.h
int writeToFile(const Student &student)
{
    FILE *filePtr = fopen("data/ex-12-01-stdio-student.txt", "w"); // открыть файл для записи
    if (filePtr == NULL)
    {
        printf("Error opening file!\n");
        return  -1; // ошибка при открытии файла
    }

    fprintf(filePtr, "The student name is %s, age is %d, and GPA is %.2f!\n", student.name.c_str(), student.age, student.gpa); // запись в файл
    fclose(filePtr);                    // закрыть файл

    return 0;                   
}