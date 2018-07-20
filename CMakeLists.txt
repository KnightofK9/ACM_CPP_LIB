cmake_minimum_required(VERSION 3.10)
project(ACM_CPP_LIB)

set(CMAKE_CXX_STANDARD 11)

add_executable(ACM_CPP_LIB
        test.cpp data_structure/BinarySearchTree.h data_structure/Graph.h data_structure/UnionFind.h data_structure/SegmentTree.h)
