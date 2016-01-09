cmake_minimum_required(VERSION 3.3)
project(james)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES "main/algorithm/160109(Tree)/tee/tree/BinaryTreeMain.c"
        "main/algorithm/160109(Tree)/tee/tree/binarytree.h"
        "main/algorithm/160109(Tree)/tee/tree/binarytree.c")
add_executable(snu_datastructure ${SOURCE_FILES})