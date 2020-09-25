cmake_minimum_required(VERSION 3.17)
project(Server)

set(CMAKE_CXX_STANDARD 14)

add_executable(Server main.cpp floyd_warshall.cpp floyd_warshall.h)