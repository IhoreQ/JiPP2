cmake_minimum_required(VERSION 3.20)
set(CMAKE_CXX_STANDARD 14)
project(matrixLib)

include_directories(include)
add_library(matrixLib STATIC src/matrixLib.cpp)
