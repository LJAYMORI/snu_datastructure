cmake_minimum_required(VERSION 3.3)
project(james)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES "main/algorithm/151205(kruscal)/james/kruscal.c")
add_executable(snu_datastructure ${SOURCE_FILES})