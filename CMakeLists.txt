cmake_minimum_required(VERSION 3.17)
project(EncStrSet)

set(CMAKE_CXX_STANDARD 17)

add_executable(
        EncStrSet
#        encstrset_test1.c
        encstrset_test2.cpp
        encstrset.cc
        encstrset.h
)