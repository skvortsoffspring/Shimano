cmake_minimum_required(VERSION 3.20)
project(ServerMS)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -static-libstdc++ -static-libgcc -static")

add_executable(ServerMS main.cpp error.cpp error.h)
