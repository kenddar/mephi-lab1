#include "unique_ptr_tests.h"
#include <iostream>
#include "../pointers/unique_ptr.h"

void testDefaultConstructorUniquePtr() {
    UniquePtr<int> ptr;
    if (ptr.get() == nullptr) {
        std::cout << "TestDefaultConstructor passed!\n";
    } else {
        std::cout << "TestDefaultConstructor failed!\n";
    }
}

void testExplicitConstructorUniquePtr() {
    UniquePtr<int> ptr(new int(42));
    if (*ptr == 42) {
        std::cout << "TestExplicitConstructor passed!\n";
    } else {
        std::cout << "TestExplicitConstructor failed!\n";
    }
}

void testMoveConstructorUniquePtr() {
    UniquePtr<int> ptr1(new int(42));
    UniquePtr<int> ptr2(std::move(ptr1));

    if (ptr1.get() == nullptr && *ptr2 == 42) {
        std::cout << "TestMoveConstructor passed!\n";
    } else {
        std::cout << "TestMoveConstructor failed!\n";
    }
}

void testMoveAssignmentUniquePtr() {
    UniquePtr<int> ptr1(new int(100));
    UniquePtr<int> ptr2;

    ptr2 = std::move(ptr1);

    if (ptr1.get() == nullptr && *ptr2 == 100) {
        std::cout << "TestMoveAssignment passed!\n";
    } else {
        std::cout << "TestMoveAssignment failed!\n";
    }
}

void testDereferenceOperatorUniquePtr() {
    UniquePtr<int> ptr(new int(55));
    if (*ptr == 55) {
        std::cout << "TestDereferenceOperator passed!\n";
    } else {
        std::cout << "TestDereferenceOperator failed!\n";
    }
}

void testArrowOperatorUniquePtr() {
    struct TestClass {
        int value;
        TestClass(int val) : value(val) {}
    };

    UniquePtr<TestClass> ptr(new TestClass(42));
    if (ptr->value == 42) {
        std::cout << "TestArrowOperator passed!\n";
    } else {
        std::cout << "TestArrowOperator failed!\n";
    }
}

void testReleaseMethodUniquePtr() {
    UniquePtr<int> ptr(new int(88));
    int* rawPtr = ptr.release();

    if (ptr.get() == nullptr && *rawPtr == 88) {
        std::cout << "TestReleaseMethod passed!\n";
    } else {
        std::cout << "TestReleaseMethod failed!\n";
    }

    delete rawPtr;
}

void testResetMethodUniquePtr() {
    UniquePtr<int> ptr(new int(77));
    ptr.reset(new int(99));

    if (*ptr == 99) {
        std::cout << "TestResetMethod passed!\n";
    } else {
        std::cout << "TestResetMethod failed!\n";
    }
}

void CallingUniquePtrTests(){
    testArrowOperatorUniquePtr();
    testDefaultConstructorUniquePtr();
    testDereferenceOperatorUniquePtr();
    testExplicitConstructorUniquePtr();
    testMoveAssignmentUniquePtr();
    testMoveConstructorUniquePtr();
    testReleaseMethodUniquePtr();
    testResetMethodUniquePtr();
}