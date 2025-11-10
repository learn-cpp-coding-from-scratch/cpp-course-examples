<<<<<<< HEAD
# Description
Examples of C++ programs for the course "Fundamentals and Methodologies of Programming"

# Организация репозитория
Репозиторий содержит множество учебных примеров, используемых для обучения С++. В проектах используются современные инструменты для модульного тестирования gtest и логирования событий spdlog. Сборка проекта ведется под управлением CMake, при этом библиотеки gtest и spdlog скачиваются один раз и папка build одна на репозиторий.

# Зависимости
Google Test и spdlog загружаются только один раз с помощью FetchContent.
Они хранятся в корневом каталоге сборки.
Все проекты могут использовать их без повторной загрузки.

# Пример структуры учебного проекта (например, ex-08-01-calculator-unit-testing):
- Каждый пример проекта будет собран в одном и том же каталоге сборки: исполняемые файлы — в build/bin, а библиотеки — в build/lib.
- Один файл в корне CMakeLists.txt
- Использует общие зависимости через target_link_libraries
- Автоматически наследует общие настройки от root.

# CMakeLists.txt файл в корне репозитория
- Централизованное управление: стандарт C++/флаги/директории вывода, включение общих модулей (задано в Dependencies.cmake), включение тестирования (enable_testing()), общие опции/переменные.
- Одна общая сборка (единая папка build) — зависимости скачиваются один раз, бинарники/библиотеки идут в предсказуемые папки.
- Удобство CI/IDE: настроить сборку всего репозитория проще именно из корня.

## CMakeLists.txt в пректах и в папках src / tests
- Корневой CMakeLists.txt в каждом приложении.
- Модульность: каждый пример/модуль определяет свои таргеты (add_library, add_executable) и интерфейсы (include dirs, public/private link).
- Переиспользуемость: корень просто делает add_subdirectory(example), а CMakeLists.txt знает как собрать именно этот пример.
- Читаемость и поддержка: легче найти код, относящийся к конкретному таргету.


CMakeLists.txt — минимальная, предполагается включение через add_subdirectory:
Не содержать project() (чтобы не дублировать).
Определять таргеты и их интерфейсы:
add_library/my_executable
target_include_directories(... PUBLIC ...)
target_link_libraries(... PRIVATE spdlog::spdlog)




# Запуск проектов
1) Откройте палитру команд (Cmd+Shift+P) → «CMake: Select a Kit» → выберите нужный (Apple Clang, Homebrew GCC и т.д.).
2) Shift + Cmd + P -> CMake: Configure
3) Shift + Cmd + P -> CMake: Build


# Спмсок тем:
1) Линейные алгоритмы
2) Инструкции выбора
8) Unit-тестирование
9) Пользовательские типы данных
=======
# Описание
Примеры демонстрационных программ на языке С++ для курса "Основы и методологии программирования".

**Язык программирования:** С++

**Автор:** [Ольга Казанцева](https://github.com/avelana)

# Licence
<img src="https://upload.wikimedia.org/wikipedia/commons/thumb/2/2e/MIT_Logo_New.svg/330px-MIT_Logo_New.svg.png" width="5%" /> MIT License

# Description
Examples of C++ programs for the course "Fundamentals and Methodologies of Programming".

**Programming language:** C++

**Copyright (c)** 2025 [Olga Kazantseva](https://github.com/avelana)


>>>>>>> 6aa32c0546baabe7597bc680b6df7a0780a6dfb0
