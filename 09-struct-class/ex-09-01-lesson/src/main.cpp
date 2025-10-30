#include "Lesson.hpp"

int main() {
  // БЕЗ СТРУКТУР
//  vector<string> titles = {"Programming", "Math Analysis", "Geometry"};
//  vector<string> dates = {"07.10.2025", "07.10.2025", "07.10.2025"};
//  vector<string> times = {"08:15", "09:45", "11:15"};
//  vector<unsigned short> rooms = {521, 542, 440};
//  PrintTimeTable(titles, dates, times, rooms);

  // С использованием структур
  std::vector<Lesson> lessons = {{"Programming", "07.10.2025", "08:15", 521},
                            {"Math Analysis", "07.10.2025", "09:45", 542},
                            {"Geometry", "07.10.2025", "11:15", 440}};
  printTimeTable(lessons);

  return 0;
}