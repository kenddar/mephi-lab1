#include <iostream>
#include <chrono>
#include "../pointers/unique_ptr.h"
#include "../pointers/smart_ptr.h"
#include "../pointers/shared_ptr.h"

template<typename Func>
void measureTime(const std::string& description, Func func){
    auto start = std::chrono::high_resolution_clock::now();
    func();
    auto end = std::chrono::high_resolution_clock::now();

    std::chrono::duration<double, std::milli> duration = end - start;
    std::cout << description << ": " << duration.count() << " ms\n";
}

void testPointerCreation(){
    measureTime("unique_ptr Creation", [](){
        for(int i = 0; i < 1000000; ++i){
            UniquePtr<int> ptr(new int(42));
        }
    });

    measureTime("smart_ptr Creation", [](){
        for(int i = 0; i < 1000000; ++i){
            SmartPtr<int> ptr(new int(42));
        }
    });

    measureTime("shared_ptr Creation", [](){
        for(int i = 0; i < 1000000; ++i){
            SharedPtr<int> ptr(new int(42));
        }
    });
}

void testPointerCopy() {
    measureTime("smart_ptr Copy", [](){
        SmartPtr<int> ptr1(new int(42));
        for(int i = 0; i < 1000000; ++i){
            SmartPtr<int> ptr2(ptr1);
        }
    });

    measureTime("shared_ptr Copy", [](){
        SharedPtr<int> ptr1(new int(42));
        for(int i = 0; i < 1000000; ++i){
            SharedPtr<int> ptr2(ptr1);
        }
    });
}

void testPointerMove() {
    measureTime("unique_ptr Move", []() {
        for(int i = 0; i < 1000000; ++i){
            UniquePtr<int> ptr1(new int(42));
            UniquePtr<int> ptr2(std::move(ptr1));
        }
    });

    measureTime("smart_ptr Move", []() {
        for(int i = 0; i < 1000000; ++i){
            SmartPtr<int> ptr1(new int(42));
            SmartPtr<int> ptr2(std::move(ptr1));
        }
    });

    measureTime("shared_ptr Move", []() {
        for(int i = 0; i < 1000000; ++i){
            SharedPtr<int> ptr1(new int(42));
            SharedPtr<int> ptr2(std::move(ptr1));
        }
    });
}
#include "time_tests.h"
