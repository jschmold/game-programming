# Project Related
cmake_minimum_required(VERSION 3.0.0)
project (GAME_3)

# Prerequisites
find_package(PkgConfig REQUIRED)
find_package(SFML 2.5 COMPONENTS window graphics REQUIRED)

# OpenGL
set (OpenGL_GL_PREFERENCE GLVND) # OpenGL Vendor Neutral Dispatch
find_package(OpenGL REQUIRED)
find_package(GLEW REQUIRED)

# Versioning
set (APPLICATION_VERSION_MAJOR 0)
set (APPLICATION_VERSION_MINOR 1)

# C++
set (CMAKE_CXX_STANDARD 17)
set (CMAKE_CXX_STANDARD_REQUIRED ON)
set (CMAKE_CXX_EXTENSIONS OFF)

# The game executable
add_executable(game src/index.cpp src/player.cpp)

target_include_directories(game PUBLIC "/usr/local/include/Box2D")

target_link_libraries(game box2d)
target_link_libraries(game sfml-system sfml-window sfml-graphics)
target_link_libraries(game GLU)
target_link_libraries(game GL)
target_link_libraries(game GLEW)
