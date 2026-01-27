cmake_minimum_required(VERSION 3.15)
project(GameEngine C)

set(CMAKE_C_STANDARD 11)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Compiler flags
if(CMAKE_BUILD_TYPE MATCHES Debug)
    add_compile_options(-g -O0 -Wall -Wextra -DDEBUG)
else()
    add_compile_options(-O3 -DNDEBUG)
endif()

# Find OpenGL and GLFW
find_package(OpenGL REQUIRED)
find_package(glfw3 3.3 REQUIRED)

# GLAD library (we'll add this in Week 1)
add_library(glad STATIC external/glad/src/glad.c)
target_include_directories(glad PUBLIC external/glad/include)

# Main executable
add_executable(${PROJECT_NAME}
    src/main.c
)

target_include_directories(${PROJECT_NAME} PRIVATE
    include
    external/glad/include
)

target_link_libraries(${PROJECT_NAME} PRIVATE
    OpenGL::GL
    glfw
    glad
    m
    dl
)
