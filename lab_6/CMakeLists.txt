cmake_minimum_required(VERSION 3.20)
project(lab_6)

set(CMAKE_CXX_STANDARD 17)

add_executable(lab_6 src/main.cpp src/vector.cpp include/vector.h include/Node.h src/Node.cpp include/ComplexNumber.h src/ComplexNumber.cpp include/Triangle.h src/Triangle.cpp)
