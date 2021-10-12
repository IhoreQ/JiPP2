cmake_minimum_required(VERSION 3.16)
set(CMAKE_CXX_STANDARD 20)

project(allocation_basics)
include_directories(headers)
add_executable(allocation_basics main.cpp zadania.cpp headers/zadania.h)


