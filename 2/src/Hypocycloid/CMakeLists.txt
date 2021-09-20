cmake_minimum_required(VERSION 3.0)

set(PROJECT_NAME Hypocycloid)

project(${PROJECT_NAME})

file(GLOB_RECURSE SRC "src/*.cpp" "src/*.h")
add_library(${PROJECT_NAME} STATIC ${SRC})

target_include_directories(${PROJECT_NAME} PUBLIC "src")
