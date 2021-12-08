cmake_minimum_required(VERSION 3.20)
project(OdtwarzaczMuzyki)

set(CMAKE_CXX_STANDARD 14)

add_executable(OdtwarzaczMuzyki src/main.cpp include/Song.h include/Player.h src/Song.cpp src/Player.cpp)
