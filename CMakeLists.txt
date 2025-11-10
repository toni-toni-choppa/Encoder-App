cmake_minimum_required(VERSION 3.10)
project(EncoderApp)

# Project Settings
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Executable
add_executable(EncoderApp
    src/main.cpp
)

# Libraries
add_library(utilities SHARED
    src/utilities/parse_arguments.cpp
)

target_link_libraries(EncoderApp utilities)

# Include Directories
include_directories(
    include
)