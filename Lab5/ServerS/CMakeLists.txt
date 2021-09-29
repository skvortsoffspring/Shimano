cmake_minimum_required(VERSION 3.20)
project(ServerS)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -static-libstdc++ -static-libgcc -static")
add_executable(ServerS source/main.cpp source/error.cpp headers/error.h source/sendreceive.cpp headers/sendreceive.h source/serice.cpp headers/service.h)
target_link_libraries(ServerS ws2_32)


