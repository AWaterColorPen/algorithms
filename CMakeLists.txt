cmake_minimum_required(VERSION 3.10)
project(algorithms)

set(CMAKE_CXX_STANDARD 17)

add_library(algorithms SHARED library.cpp library.h datastructures/binary_indexed_trees.cpp datastructures/binary_indexed_trees.h math/matrix.cpp math/matrix.h)