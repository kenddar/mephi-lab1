#include "shared_ptr_tests.h"
#include <iostream>
#include "../pointers/shared_ptr.h"

void testDefaultConstructorSharedPtr() {
    SharedPtr<int> ptr;
    if ( ptr.num_count() == 0) {
        std::cout << "TestDefaultConstructor passed!\n";
    } else {
        std::cout << "TestDefaultConstructor failed!\n";
    }
}

void testConstructorWithParameterSharedPtr() {
    SharedPtr<int> ptr(new int(42));
    if (*ptr == 42 && ptr.num_count() == 1) {
        std::cout << "TestConstructorWithParameter passed!\n";
    } else {
        std::cout << "TestConstructorWithParameter failed!\n";
    }
}

void testCopyConstructorSharedPtr() {
    SharedPtr<int> ptr1(new int(42));
    SharedPtr<int> ptr2(ptr1);

    if (*ptr1 == 42 && *ptr2 == 42 && ptr1.num_count() == 2 && ptr2.num_count() == 2) {
        std::cout << "TestCopyConstructor passed!\n";
    } else {
        std::cout << "TestCopyConstructor failed!\n";
    }
}

void testCopyAssignmentSharedPtr() {
    SharedPtr<int> ptr1(new int(42));
    SharedPtr<int> ptr2;
    ptr2 = ptr1;

    if (*ptr1 == 42 && *ptr2 == 42 && ptr1.num_count() == 2 && ptr2.num_count() == 2) {
        std::cout << "TestCopyAssignment passed!\n";
    } else {
        std::cout << "TestCopyAssignment failed!\n";
    }
}

void testDereferenceOperatorSharedPtr() {
    SharedPtr<int> ptr(new int(42));
    if (*ptr == 42) {
        std::cout << "TestDereferenceOperator passed!\n";
    } else {
        std::cout << "TestDereferenceOperator failed!\n";
    }
}

void testArrowOperatorSharedPtr() {
    struct TestClass {
        int value;
        TestClass(int val) : value(val) {}
    };

    SharedPtr<TestClass> ptr(new TestClass(42));
    if (ptr->value == 42) {
        std::cout << "TestArrowOperator passed!\n";
    } else {
        std::cout << "TestArrowOperator failed!\n";
    }
}

void testResetSharedPtr() {
    SharedPtr<int> ptr(new int(42));
    ptr.reset(new int(100));

    if (*ptr == 100 && ptr.num_count() == 1) {
        std::cout << "TestReset passed!\n";
    } else {
        std::cout << "TestReset failed!\n";
    }
}

void testReferenceCountingSharedPtr() {
    SharedPtr<int> ptr1(new int(42));
    SharedPtr<int> ptr2(ptr1);
    SharedPtr<int> ptr3(ptr2);

    if (ptr1.num_count() == 3 && ptr2.num_count() == 3 && ptr3.num_count() == 3) {
        std::cout << "TestReferenceCounting passed!\n";
    } else {
        std::cout << "TestReferenceCounting failed!\n";
    }

    ptr3.reset();
    if (ptr1.num_count() == 2 && ptr2.num_count() == 2 && ptr3.num_count() == 0) {
        std::cout << "TestReferenceCounting after reset passed!\n";
    } else {
        std::cout << "TestReferenceCounting after reset failed!\n";
    }
}


void CallingSharedPtrTests(){
    testArrowOperatorSharedPtr();
    testConstructorWithParameterSharedPtr();
    testCopyAssignmentSharedPtr();
    testCopyConstructorSharedPtr();
    testDefaultConstructorSharedPtr();
    testDereferenceOperatorSharedPtr();
    testReferenceCountingSharedPtr();
    testResetSharedPtr();
}