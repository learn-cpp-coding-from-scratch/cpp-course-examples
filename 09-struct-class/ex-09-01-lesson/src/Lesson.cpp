#include <iostream>
#include <string>
#include <vector>
#include "Lesson.hpp"

std::string Lesson::toString() const {
    return "Lesson[Title: " + title + ", date: " + date + ", time: " + time
            + ", room: " + std::to_string(room) + hello() + "]\n";
}

std::string Lesson::hello() const { 
    return "hello";
 }

// void printLesson(const std::string &title, 
//     const std::string &date, 
//     const std::string &time, 
//     unsigned short &room) {
//         std::cout << "Title: " << title << ", date: " << date
//             << ", time: " << time << ", room: " << room << '\n';
// }


// void printTimeTable(const std::vector<std::string> &titles, 
//     const std::vector<std::string> &dates, 
//     const std::vector<std::string> &times,
//     std::vector<unsigned short> &rooms) {
//         int i = 0;
//         while (i < titles.size()) {
//         // НО м.б. проблемы, если данные не согласованы, например - размер векторов разный
//         // printLesson(titles[i], dates[i], times[i], rooms[i]);
//         ++i;
//         }
// }

void printLesson(const Lesson &lesson) {
    std::cout << "Title: "  << lesson.title 
        << ", date: " << lesson.date
        << ", time: " << lesson.time
        << ", room: " << lesson.room << '\n';
  std::cout << lesson.toString();
}

void printTimeTable(const std::vector<Lesson> &lessons) {
    for (auto &x: lessons) {
        printLesson(x);
    }
}


