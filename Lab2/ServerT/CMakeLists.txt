cmake_minimum_required(VERSION 3.20)
project(ServerT)

set(CMAKE_CXX_STANDARD 14)

add_executable(ServerT main.cpp Error.cpp Error.h)
target_link_libraries(ServerT ws2_32)


