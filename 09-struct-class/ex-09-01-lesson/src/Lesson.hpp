#pragma once

#ifndef LESSON_H
#define LESSON_H

#include <string>
#include <vector>

struct Lesson {
    std::string title;
    std::string date;
    std::string time;
    unsigned short room;

    std::string toString() const ;
    std::string hello() const;
};

// void printLesson(const std::string &title, 
//     const std::string &date, 
//     const std::string &time, 
//     unsigned short &room);
// void printTimeTable(const std::vector<std::string> &titles, 
//     const std::vector<std::string> &dates, 
//     const std::vector<std::string> &times,
//     std::vector<unsigned short> &rooms) ;

void printLesson(const Lesson &lesson);
void printTimeTable(const std::vector<Lesson> &lessons);


#endif // LESSON_H