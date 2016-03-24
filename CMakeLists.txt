cmake_minimum_required(VERSION 3.3)
project(hackerrank)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES TeamFormation.cpp)
add_executable(hackerrank ${SOURCE_FILES})