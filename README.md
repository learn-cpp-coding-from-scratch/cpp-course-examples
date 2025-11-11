# Описание
Примеры демонстрационных программ на языке С++ для курса "Основы и методологии программирования".

**Язык программирования:** С++20

**Автор:** [Ольга Казанцева](https://github.com/avelana)

# Licence
<img src="https://upload.wikimedia.org/wikipedia/commons/thumb/2/2e/MIT_Logo_New.svg/330px-MIT_Logo_New.svg.png" width="5%" /> MIT License

# Description
Examples of C++ programs for the course "Fundamentals and Methodologies of Programming".

**Programming language:** C++20

**Copyright (c)** 2025 [Olga Kazantseva](https://github.com/avelana)

# Description
Examples of C++ programs for the course "Fundamentals and Methodologies of Programming"

# Организация репозитория
Репозиторий содержит множество учебных примеров, используемых для обучения С++. В проектах используются современные инструменты для модульного тестирования gtest и логирования событий spdlog. Сборка проекта ведется под управлением CMake, при этом библиотеки gtest и spdlog скачиваются один раз и папка build одна на репозиторий.

# Список тем (* - вне тем курса, дополнительные темы)
1. Линейные алгоритмы
2. Инструкции выбора
3. Циклические алгоритмы
4. Структура программ
5. Функции. Перегрузка, шаблоны
6. Контейреры, потоки (строковые, файловые, ...)
7. Константы, ссылки, указатели. Адресная арифметика
8. Unit-тестирование
9. Пользовательские типы данных - классы, структуры. Объединения, перечисления, битовые поля
10. Конструкторы, деструкторы, перегрузка операторов
11. Инстументы разработки: обработка исключений, логирование, тестирование(фикстуры)
12. Принципы объектно-ориентированного программирования и объектно-ориентированного проектировангия
13. Реализация линейных и нелинейных структур данных
14. Наследование, полиморфизм. Шаброны классов
15. Библиотеки stl: контейнеров, итераторов, алгоритмов. Функциональные объекты, лямбда-выражения
16. С-строки и библиотека строк stl
17. * Управление директориями и файлами
18. * Работа с файлами csv, json, proto
19. * Библиотека chrono
20. * Многопоточное программирование
21. * Работа с библиотекой sfml

# Запуск проектов в VS Code
1) Откройте палитру команд (Cmd+Shift+P) → «CMake: Select a Kit» → выберите нужный компилятор (Clang, GCC и т.д.).
2) (Cmd+Shift+P) -> CMake: Configure
3) (Cmd+Shift+P) -> CMake: Build
4) (Cmd+Shift+P) -> CMake: Set Launch/Debug Target - выбираем цели запууска - приложение или тесты
5) Запуск выбранного целевого объекта в окне терминала: внизу IDE с помощью панели CMake стрелка запуска ▶ .

## Цели запуска в проекте имеют следующие названия 
- app-ex-* - приложения соответствующих демо примеров.
- tests-ex-* - запуск тестов соответстующих демо примеров.

## Зависимости
- Google Test и spdlog загружаются только один раз с помощью FetchContent.
- Они хранятся в корневом каталоге сборки.
- Все проекты могут использовать их без повторной загрузки.

## Общая организация проекта "cpp_course_examples" с демо проектами
- Каждый пример проекта будет собран в одном и том же каталоге сборки: исполняемые файлы — в `build/bin/<example-name>`, а библиотеки — в `build/lib`.
- Один файл в корне `CMakeLists.txt`, и собственные `CMakeLists.txt` файлы в каждом проекте.
- Все примеры используют общие зависимости (gtest, spdlog) через `target_link_libraries`.
- Все примеры автоматически наследуют общие настройки от корневого CMakeLists.txt.

## Структура каждого проекта ex-*

Каждый учебный проект имеет следующую структуру:

```
ex-projectname/
├── CMakeLists.txt           # Корневой файл для этого проекта
├── src/                     # Исходный код основного приложения
│   ├── CMakeLists.txt
│   ├── main.cpp             # Точка входа приложения
│   ├── module.cpp           # Реализация функций/классов
│   └── module.h             # Заголовки (для include директив)
├── include/                 # (опционально) Публичные заголовки библиотеки
│   └── module.h
└── tests/                   # Модульные тесты (используют Google Test)
    ├── CMakeLists.txt
    └── test_module.cpp      # Тесты для module.cpp
```

### Описание каждого компонента

#### 1) `ex-projectname/CMakeLists.txt` — корневой файл проекта
Этот файл **добавляется корневым CMakeLists.txt репозитория** через `add_subdirectory(ex-projectname)`.

**Содержит:**
- Вызов `project(ex-projectname)` — определяет имя проекта (унаследуется подпроектами).
- Поддиректории: `add_subdirectory(src)` и `add_subdirectory(tests)`.
- Может содержать базовые настройки, общие для src и tests.

**Пример:**
```cmake
project(ex-myproject)

add_subdirectory(src)
add_subdirectory(tests)
```

#### 2) `src/` — исходный код приложения

**`src/CMakeLists.txt`:**
- Определяет библиотеку (`add_library`) с основным кодом (если нужна переиспользуемость).
- Определяет исполняемый файл приложения (`add_executable`).
- Указывает публичные/приватные заголовки и зависимости.

**Пример `src/CMakeLists.txt`:**
```cmake
# Создаём библиотеку (для переиспользования в тестах)
add_library(mylib module.cpp)
target_include_directories(mylib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(mylib PRIVATE spdlog::spdlog)

# Создаём основное приложение
add_executable(myapp main.cpp)
target_link_libraries(myapp PRIVATE mylib spdlog::spdlog)
```

**`src/main.cpp`:**
- Точка входа в приложение (`int main() { ... }`).
- Использует функции/классы из `module.h` / `module.cpp`.

**`src/module.h` и `src/module.cpp`:**
- Заголовок и реализация основных функций/классов приложения.
- Могут содержать логику обработки данных, бизнес-логику и т.д.

#### 3) `include/` — (опционально) публичные заголовки
Если вы хотите чётко отделить публичный интерфейс, используйте папку `include/`.

**Структура:**
```
include/
└── mylib.h   # публичный заголовок библиотеки
```

**В `src/CMakeLists.txt`:**
```cmake
add_library(mylib src/module.cpp)
target_include_directories(mylib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/../include)
```

#### 4) `tests/` — модульные тесты (Google Test)

**`tests/CMakeLists.txt`:**
- Создаёт исполняемый файл с тестами.
- Линкует его с библиотекой из `src/` и с `GTest::gtest_main`.
- Регистрирует тесты для запуска (`gtest_discover_tests`).

**Пример `tests/CMakeLists.txt`:**
```cmake
# Создаём исполняемый файл тестов
add_executable(myapp_tests test_module.cpp)

# Линкуем с библиотекой и Google Test
target_link_libraries(myapp_tests
    PRIVATE
    mylib              # библиотека из src/
    GTest::gtest_main  # основной фреймворк Google Test
    spdlog::spdlog     # логирование (если нужно)
)

# Регистрируем тесты для запуска через ctest
include(GoogleTest)
gtest_discover_tests(myapp_tests)
```

**`tests/test_module.cpp`:**
- Содержит тестовые случаи (test fixtures).
- Использует макросы Google Test: `TEST`, `TEST_F`, `ASSERT_*`, `EXPECT_*`.

**Пример теста:**
```cpp
#include <gtest/gtest.h>
#include "../src/module.h"

TEST(ModuleTest, BasicFunctionality) {
    int result = myFunction(5);
    EXPECT_EQ(result, 10);
}
```

### Рекомендации по организации

1. **Минимальная структура** (для простых примеров):
   ```
   ex-simple/
   ├── CMakeLists.txt
   ├── src/
   │   ├── CMakeLists.txt
   │   └── main.cpp
   └── tests/
       ├── CMakeLists.txt
       └── test_main.cpp
   ```

2. **Полная структура** (для более сложных проектов):
   ```
   ex-complex/
   ├── CMakeLists.txt
   ├── include/
   │   ├── module1.h
   │   └── module2.h
   ├── src/
   │   ├── CMakeLists.txt
   │   ├── main.cpp
   │   ├── module1.cpp
   │   └── module2.cpp
   └── tests/
       ├── CMakeLists.txt
       ├── test_module1.cpp
       └── test_module2.cpp
   ```

3. **Типичный CMakeLists.txt в проекте ex-***

   ```cmake
   # ex-projectname/CMakeLists.txt
   project(ex-projectname)
   
   add_subdirectory(src)
   add_subdirectory(tests)
   ```

   ```cmake
   # ex-projectname/src/CMakeLists.txt
   add_library(projectlib module.cpp)
   target_include_directories(projectlib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
   target_link_libraries(projectlib PRIVATE spdlog::spdlog)
   
   add_executable(projectapp main.cpp)
   target_link_libraries(projectapp PRIVATE projectlib spdlog::spdlog)
   ```

   ```cmake
   # ex-projectname/tests/CMakeLists.txt
   add_executable(projectapp_tests test_module.cpp)
   target_link_libraries(projectapp_tests PRIVATE projectlib GTest::gtest_main spdlog::spdlog)
   
   include(GoogleTest)
   gtest_discover_tests(projectapp_tests)
   ```

# CMakeLists.txt в проектах и в папках src / tests
- Корневой CMakeLists.txt в каждом приложении — подключение subdirectories через `add_subdirectory`.
- **Модульность:** каждый пример/модуль определяет свои таргеты (`add_library`, `add_executable`) и интерфейсы (include dirs, public/private link).
- **Переиспользуемость:** корень просто делает `add_subdirectory(example)`, а его `CMakeLists.txt` знает как собрать именно этот пример.
- **Читаемость и поддержка:** легче найти код, относящийся к конкретному таргету.