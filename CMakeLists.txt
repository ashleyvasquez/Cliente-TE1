cmake_minimum_required(VERSION 3.15)
project(T_ExtraclaseCliente)

set(CMAKE_CXX_STANDARD 17)
SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -pthread")

add_executable(T_ExtraclaseCliente main.cpp Cliente.cpp Cliente.h)