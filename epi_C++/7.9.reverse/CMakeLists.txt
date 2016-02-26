cmake_minimum_required(VERSION 3.3)
project(7_9_reverse)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp LinkedList.cpp LinkedList.h)
add_executable(7_9_reverse ${SOURCE_FILES})