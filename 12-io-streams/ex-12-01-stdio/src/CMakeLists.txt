# Create library for calculator
add_library(lib-ex-12-01-stdio demo_stdio.cpp)

# Create main executable
add_executable(app-ex-12-01-stdio main.cpp)

# Линкуем библиотеку к исполняемому файлу
target_link_libraries(app-ex-12-01-stdio
    PUBLIC 
        lib-ex-12-01-stdio
        spdlog::spdlog   # Логирование нужно везде
)
# Если у библиотеки есть свои заголовки (.hpp), добавляем:
target_include_directories(lib-ex-12-01-stdio
    PUBLIC
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/../include>
)

