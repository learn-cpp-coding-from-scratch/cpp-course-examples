# Dependencies.cmake
include(FetchContent)

# Переопределяемые версии
if(NOT DEPS_GTEST_TAG)
    set(DEPS_GTEST_TAG v1.14.0 CACHE STRING "googletest version")
endif()
if(NOT DEPS_SPDLOG_TAG)
    set(DEPS_SPDLOG_TAG v1.12.0 CACHE STRING "spdlog version")
endif()

# Настройки GTest
set(BUILD_GMOCK OFF CACHE BOOL "" FORCE)
set(INSTALL_GTEST OFF CACHE BOOL "" FORCE)
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)

# Git clone вместо ZIP
FetchContent_Declare(
    googletest
    GIT_REPOSITORY https://github.com/google/googletest.git
    GIT_TAG ${DEPS_GTEST_TAG}
)

FetchContent_Declare(
    spdlog
    GIT_REPOSITORY https://github.com/gabime/spdlog.git
    GIT_TAG ${DEPS_SPDLOG_TAG}
)

# Загрузка
FetchContent_MakeAvailable(googletest spdlog)

# Включение тестов 
enable_testing()
include(GoogleTest)

# Диагностика
message(STATUS "Dependencies: googletest=${DEPS_GTEST_TAG}, spdlog=${DEPS_SPDLOG_TAG}")
