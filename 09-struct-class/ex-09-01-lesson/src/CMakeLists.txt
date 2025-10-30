add_library(lesson Lesson.cpp)
add_executable(lesson_app main.cpp)
target_link_libraries(lesson_app lesson)