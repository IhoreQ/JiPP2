cmake_minimum_required(VERSION 3.16)
set(CMAKE_CXX_STANDARD 20)

project(simpleCalc)
include_directories(headers src)
add_executable(simpleCalc src/main.cpp src/calc.cpp headers/calc.h)