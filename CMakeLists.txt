cmake_minimum_required(VERSION 3.26)
project(lab1sem3)

set(CMAKE_CXX_STANDARD 17)

add_executable(lab1sem3 main.cpp
        containers/arraysequence.hpp
        tests/array_sequence_with_shared_ptr_tests.cpp
        tests/array_sequence_with_shared_ptr_tests.h
        containers/linkedlist.hpp
        containers/listsequence.hpp
        tests/list_sequence_with_unique_ptr_tests.cpp
        tests/list_sequence_with_unique_ptr_tests.h
        tests/smart_array_with_smart_ptr_tests.cpp
        tests/smart_array_with_smart_ptr_tests.h
        containers/smart_array.h
)
