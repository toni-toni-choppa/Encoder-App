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
    src/utilities/resolve_path.cpp
    src/utilities/file_management.cpp
)

add_library(encoder SHARED
    src/encoder/validate_file.cpp
)

target_link_libraries(encoder PRIVATE utilities)
target_link_libraries(EncoderApp utilities encoder)

# Include Directories
include_directories(
    include
)