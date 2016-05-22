cmake_minimum_required(VERSION 3.5)
project(12_hash)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp NearestRepetition.h PairUsers.h Anagrams.h Palindrome.h LetterFreq.h Plagiarism.h)
add_executable(12_hash ${SOURCE_FILES})