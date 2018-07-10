cmake_minimum_required(VERSION 3.5.1)
set(CMAKE_BUILD_TYPE Debug)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

project(LinkedLists)
include_directories(include)
add_executable(LinkedList src/main.cpp src/List.cpp include/List.h)
