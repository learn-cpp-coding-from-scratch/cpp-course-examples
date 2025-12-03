# Create library for calculator
add_library(lib-ex-13-01-symbols 
    symbol_properties.cpp
)

# Create main executable
add_executable(app-ex-13-01-symbols
    main.cpp
)

# Линкуем библиотеку к исполняемому файлу
target_link_libraries(app-ex-13-01-symbols
    PUBLIC 
        lib-ex-13-01-symbols
        spdlog::spdlog   # Логирование нужно везде
)

#Если у библиотеки есть свои заголовки (.hpp), добавляем:
target_include_directories(lib-ex-13-01-symbols
    PUBLIC
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/../include>
)
