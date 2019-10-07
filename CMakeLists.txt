cmake_minimum_required(VERSION 3.7)

project(RacingGameProject)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

find_package(SDL2 REQUIRED)
include_directories(${SDL2_INCLUDE_DIRS})

add_subdirectory(external/box2d)
include_directories(external/box2d)

add_executable(RacingGame main.cpp)
target_link_libraries(RacingGame ${SDL2_LIBRARIES} Box2D)
