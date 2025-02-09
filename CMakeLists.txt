cmake_minimum_required(VERSION 3.7)

project(RacingGameProject)

# Enable c++14
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Include SDL
if (WIN32)
    set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/")
    set(SDL2_PATH "${CMAKE_SOURCE_DIR}/external/sdl2")
endif (WIN32)

find_package(SDL2 REQUIRED)

if (WIN32)
    include_directories(${SDL2_INCLUDE_DIR})
else (WIN32)
    include_directories(${SDL2_INCLUDE_DIRS})
endif (WIN32)

# Include Box2D
add_subdirectory(external/box2d)
include_directories(external/box2d)

# Include main project
file(GLOB RACINGGAME_SRC
    "src/include/*.h"
    "src/*.cpp"
)

include_directories("src/include")

add_executable(RacingGame ${RACINGGAME_SRC})

# Add tests
add_executable(TestSDL "tests/test_sdl.cpp")
add_executable(TestBox2D "tests/test_box2d.cpp")

# Link the libraries
if (WIN32)
    target_link_libraries(RacingGame ${SDL2_LIBRARY_TEMP} Box2D)
    target_link_libraries(TestSDL ${SDL2_LIBRARY_TEMP})
else (WIN32)
    target_link_libraries(RacingGame ${SDL2_LIBRARIES} Box2D)
    target_link_libraries(TestSDL ${SDL2_LIBRARIES})
endif (WIN32)
target_link_libraries(TestBox2D Box2D)

# Add a copy command for the dll for Windows
if (WIN32)
    if(CMAKE_SIZEOF_VOID_P EQUAL 8) 
        set(SDL_DLL_PATH "${SDL2_PATH}/lib/x64")
    else() 
        set(SDL_DLL_PATH "${SDL2_PATH}/lib/x86")
    endif()
    
    add_custom_command(TARGET RacingGame POST_BUILD    # Adds a post-build event to MyTest
        COMMAND ${CMAKE_COMMAND} -E copy_if_different  # which executes "cmake - E copy_if_different..."
            "${SDL_DLL_PATH}/SDL2.dll"                 # <--this is in-file
            $<TARGET_FILE_DIR:RacingGame>)             # <--this is out-file path
endif (WIN32)
