cmake_minimum_required(VERSION 3.20)
project(ServerU)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -static-libstdc++ -static-libgcc -static")
add_executable(ServerU main.cpp Error.cpp Error.h)
target_link_libraries(ServerU ws2_32)


