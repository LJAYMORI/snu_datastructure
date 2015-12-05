cmake_minimum_required(VERSION 3.3)
project(james)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES "main/datastructure/graph/arrayGraph/GraphMain.c"
        "main/datastructure/graph/arrayGraph/graph.h"
        "main/datastructure/graph/arrayGraph/graph.c")
add_executable(snu_datastructure ${SOURCE_FILES})