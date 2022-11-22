cmake_minimum_required(VERSION 3.23)
project(laba2)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -fopenmp")

add_executable(laba2 main.cpp src/utils.h)
