cmake_minimum_required(VERSION 3.24)
project(ADT)

set(CMAKE_CXX_STANDARD 17)

add_executable(ADT SLL.cpp ../Tree/Tree.cpp ../heap/heap.h ../heap/heap.cpp)
