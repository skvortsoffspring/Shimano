cmake_minimum_required(VERSION 3.20)
project(ClientS)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -static-libstdc++ -static-libgcc -static")
add_executable(ClientS source/main.cpp source/Error.cpp headers/Error.h headers/service.h source/service.cpp)
target_link_libraries(ClientS ws2_32)


