cmake_minimum_required(VERSION 3.3)
project(7_linked_list)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp LinkedList.cpp LinkedList.h 7.2.cycle/LinkedList.cpp 7.2.cycle/LinkedList.h)
add_executable(7_linked_list ${SOURCE_FILES})