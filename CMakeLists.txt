cmake_minimum_required(VERSION 3.14)
project(cpp_course_examples)

# Set C++ standard
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Enable testing for the whole repository
enable_testing()

# Set output directories
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)

# Include shared dependency module (downloads dependencies once)
include(${CMAKE_SOURCE_DIR}/cmake/Dependencies.cmake)

## Find and automatically add all example directories whose names start with 'ex-'.
## Search for top-level CMakeLists.txt in directories directly named ex-*
set(EXAMPLE_DIRS "")

# Find all CMakeLists.txt files at the top level of ex-* directories
# Pattern: ex-*/CMakeLists.txt (direct children of CMAKE_SOURCE_DIR)
file(GLOB _EX_CMAKELISTS RELATIVE ${CMAKE_SOURCE_DIR} "*/ex-*/CMakeLists.txt")

foreach(_cmake IN LISTS _EX_CMAKELISTS)
    # directory containing the CMakeLists.txt -> the example directory
    get_filename_component(_ex_dir ${_cmake} DIRECTORY)
    if(IS_DIRECTORY "${CMAKE_SOURCE_DIR}/${_ex_dir}")
        list(APPEND EXAMPLE_DIRS ${_ex_dir})
    endif()
endforeach()

# Remove duplicates and sort for deterministic order
list(REMOVE_DUPLICATES EXAMPLE_DIRS)
list(SORT EXAMPLE_DIRS)

if(EXAMPLE_DIRS)
    foreach(example_dir IN LISTS EXAMPLE_DIRS)
        message(STATUS "Adding example: ${example_dir}")
        add_subdirectory(${example_dir})
    endforeach()
else()
    message(STATUS "No example directories (ex-*) found to add")
    message(STATUS "Searched patterns: ex-*/CMakeLists.txt")
    message(STATUS "CMAKE_SOURCE_DIR: ${CMAKE_SOURCE_DIR}")
endif()