cmake_minimum_required(VERSION 3.0)

set(PROJECT_NAME Tests)

project(${PROJECT_NAME})

enable_testing()

add_subdirectory(../../../googletest googletest)

file(GLOB_RECURSE SRC "src/*.cpp" "src/*.h")
add_executable(${PROJECT_NAME} ${SRC})

target_link_libraries(${PROJECT_NAME} PUBLIC gtest_main Hypocycloid)

add_test(NAME ${PROJECT_NAME} COMMAND ${PROJECT_NAME})
