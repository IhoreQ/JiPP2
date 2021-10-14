cmake_minimum_required(VERSION 3.16)
set(CMAKE_CXX_STANDARD 20)

project(firstLibCall)
include_directories(${CMAKE_SOURCE_DIR}/firstLib/headers)
add_executable(firstLibCall main.cpp)
target_link_libraries(firstLibCall firstLib)