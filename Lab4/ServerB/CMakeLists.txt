cmake_minimum_required(VERSION 3.20)
project(ServerB)

set(CMAKE_CXX_STANDARD 14)

add_executable(ServerB source/main.cpp source/error.cpp headers/error.h source/sendreceive.cpp headers/sendreceive.h source/serice.cpp headers/service.h)
target_link_libraries(ServerB ws2_32)


