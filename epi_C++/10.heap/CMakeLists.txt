cmake_minimum_required(VERSION 3.5)
project(10_heap)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp BinaryHeap.h FileMerger.h StackWithHeap.h ClosestStars.h)
add_executable(10_heap ${SOURCE_FILES})