cmake_minimum_required(VERSION 3.5.1)
project(WriteWavHeader)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

include_directories(inc)

MESSAGE(STATUS "operation system is ${CMAKE_SYSTEM}")

set(SOURCE_FILES src/main.cpp src/WavFunctions.cc)
set(PROJECT_BINARY_DIR D:/project/c++/WriteWavHeader)

if (UNIX)
    set(CMAKE_C_COMPILER arm-linux-androideabi-gcc)
        set(CMAKE_CXX_COMPILER arm-linux-androideabi-g++)
    set(PROJECT_BINARY_DIR /home/franken/projects/WriteWavHeader)
endif (UNIX)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR}/bin)
add_executable(write_header ${SOURCE_FILES})