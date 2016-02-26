cmake_minimum_required(VERSION 3.3)
project(7_3_circular_median)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp)
add_executable(7_3_circular_median ${SOURCE_FILES})