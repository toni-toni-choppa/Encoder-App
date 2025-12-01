cmake_minimum_required(VERSION 3.10)

# Project Settings
project(EncoderApp VERSION 1.0 LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(CMAKE_CXX_EXTENSIONS False)

# Executable
add_executable(EncoderApp 
    ${PROJECT_SOURCE_DIR}/src/main.cpp
)

# Include Directories
target_include_directories(EncoderApp PRIVATE 
    ${PROJECT_SOURCE_DIR}/include
)