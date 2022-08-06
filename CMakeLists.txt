cmake_minimum_required (VERSION 3.13.4)
project(topsort)

set (CMAKE_BUILD_TYPE Debug)

set (SOURCES sources/main.cpp sources/topological_sort.cpp sources/stack.cpp sources/list.cpp)

add_executable (${PROJECT_NAME} ${SOURCES})
target_include_directories (${PROJECT_NAME} PRIVATE includes)

add_compile_options (-g -Werror -Wall -Wextra -Wpedantic)