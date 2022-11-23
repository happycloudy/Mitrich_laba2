cmake_minimum_required(VERSION 3.23)
project(laba2)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -fopenmp")

add_executable(laba2 main.cpp src/genNumbers.h src/calculation.h src/genVectors.h src/parallelStarter.h)

enable_testing()
add_subdirectory(test build/test)