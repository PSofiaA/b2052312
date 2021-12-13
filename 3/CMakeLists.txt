cmake_minimum_required(VERSION 3.0)

set(PROJECT_NAME Thirdlab)

project(${PROJECT_NAME})

add_subdirectory(src/PCB)
add_subdirectory(src/Console)
add_subdirectory(src/Tests)