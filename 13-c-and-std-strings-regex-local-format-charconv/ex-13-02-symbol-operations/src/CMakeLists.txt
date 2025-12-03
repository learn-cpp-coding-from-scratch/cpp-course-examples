# Create library for calculator
add_library(lib-ex-13-02-symbol-operations
    CaseInsensitiveCharTraits.cpp
)

# Create main executable
add_executable(app-ex-13-02-symbol-operations
     main.cpp
)

#Линкуем библиотеку к исполняемому файлу
target_link_libraries(app-ex-13-02-symbol-operations
    PUBLIC 
        lib-ex-13-02-symbol-operations
        spdlog::spdlog   # Логирование нужно везде
)
# Если у библиотеки есть свои заголовки (.hpp), добавляем:
target_include_directories(lib-ex-13-02-symbol-operations
    PUBLIC
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/../include>
)