cmake_minimum_required(VERSION 3.20)
project(ClientU)

set(CMAKE_CXX_STANDARD 14)

add_executable(ClientU source/main.cpp source/Error.cpp headers/Error.h headers/service.h source/service.cpp)
target_link_libraries(ClientU ws2_32)


