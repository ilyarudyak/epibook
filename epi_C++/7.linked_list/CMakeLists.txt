cmake_minimum_required(VERSION 3.3)
project(7_linked_list)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp 7.1.merge/LinkedList.cpp 7.1.merge/LinkedList.h)
add_executable(7_linked_list ${SOURCE_FILES})