add_library(lib-ex-09-01-lesson Lesson.cpp)
add_executable(app-ex-09-01-lesson main.cpp)
target_link_libraries(app-ex-09-01-lesson lib-ex-09-01-lesson)