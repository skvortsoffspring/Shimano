cmake_minimum_required(VERSION 3.20)
project(ClientT)

set(CMAKE_CXX_STANDARD 14)

add_executable(ClientT main.cpp Error.cpp Error.h)
target_link_libraries(ClientT ws2_32)


