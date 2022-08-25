project(codelet)
cmake_minimum_required(VERSION 3.5)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++0x")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wno-long-long -pedantic")

add_subdirectory(source/utils)
add_subdirectory(source/problems/C)
add_subdirectory(source/problems/C++)
add_subdirectory(tests)
