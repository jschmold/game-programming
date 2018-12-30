# Requirements
#  - Add GLFW as a library
#  - Make it easy to generate make files
#  - Have subdirs included as "modules"
#

# 3.0.0 because why not, right?
cmake_minimum_required(VERSION 3.0.0)


# Apparently this is the project name?
project (GAME_1)

set (OpenGL_GL_PREFERENCE GLVND)


# These appear to allow @TAG@ comments for post-processing
# in files within the project
set (APPLICATION_VERSION_MAJOR 0)
set (APPLICATION_VERSION_MINOR 1)

# C++ 14 because latest features
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)


# Usage:
#  // Place this in the .in files
#  #define VERSION_MAJOR @VERSION_MAJOR@

add_executable(game src/index.cpp src/window.cpp)
include_directories(${GLFW_INCLUDE_DIRS})

find_package(PkgConfig REQUIRED)
find_package(glfw3 3.2 REQUIRED)
find_package(OpenGL REQUIRED)


# OpenGL specific
target_link_libraries(game glfw3)
target_link_libraries(game GLU)
target_link_libraries(game GL)
target_link_libraries(game GLEW)

# Dynamic linking
target_link_libraries(game dl)
target_link_libraries(game pthread)

#Just GLFW
target_link_libraries(game X11)
target_link_libraries(game Xrandr)
target_link_libraries(game Xinerama)
target_link_libraries(game Xxf86vm)
target_link_libraries(game Xcursor)
