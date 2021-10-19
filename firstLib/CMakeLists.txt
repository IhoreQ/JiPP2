cmake_minimum_required(VERSION 3.16)
set(CMAKE_CXX_STANDARD 20)

project(firstLib)
include_directories(headers)
add_library(firstLib STATIC src/lib.cpp)