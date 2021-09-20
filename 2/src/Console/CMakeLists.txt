cmake_minimum_required(VERSION 3.0)

set(PROJECT_NAME Console)

project(${PROJECT_NAME})

file(GLOB_RECURSE SRC "src/*.cpp" "src/*.h")
add_executable(${PROJECT_NAME} ${SRC})

target_link_libraries(${PROJECT_NAME} PUBLIC Hypocycloid)
