cmake_minimum_required(VERSION 3.20)
project(ClientU)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -static-libstdc++ -static-libgcc -static")
add_executable(ClientU main.cpp Error.cpp Error.h)
target_link_libraries(ClientU ws2_32)


