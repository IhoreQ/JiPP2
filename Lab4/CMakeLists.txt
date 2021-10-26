cmake_minimum_required(VERSION 3.20)
project(Lab4)

set(CMAKE_CXX_STANDARD 14)
include_directories(include)

add_executable(Lab4 src/main.cpp include/structs.h src/structs.cpp include/prostopadloscian.h src/prostopadloscian.cpp include/kula.h src/kula.cpp include/funkcjaKwadratowa.h include/student.h src/funkcjaKwadratowa.cpp src/student.cpp src/punkt.cpp include/punkt.h include/figura.h src/figura.cpp include/Last.h src/Last.cpp)