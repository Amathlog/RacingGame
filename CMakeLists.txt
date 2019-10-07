cmake_minimum_required(VERSION 3.7)

project(SDL2Test)

find_package(SDL2 REQUIRED)
include_directories(${SDL2_INCLUDE_DIRS})

add_executable(RacingGame main.cpp)
target_link_libraries(RacingGame ${SDL2_LIBRARIES})
