cmake_minimum_required(VERSION 3.26)
project(lab1sem3)

set(CMAKE_CXX_STANDARD 17)

add_executable(lab1sem3 main.cpp
        SharedPtr_tests.cpp
        SmartPtr_tests.cpp
        UniquePtr_tests.cpp
        tests.cpp
        tests.h
)
