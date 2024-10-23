#include "shared_ptr_tests.h"
#include "../tests/shared_ptr_tests.h"
#include <iostream>
#include "../pointers/shared_ptr.h"

void testDefaultConstructorSharedPtr() {
    SharedPtr<int> ptr;
    if (ptr.get() == nullptr && ptr.num_count() == 0) {
        std::cout << "testDefaultConstructor PASSED\n";
    } else {
        std::cout << "testDefaultConstructor FAILED\n";
    }
}

void testConstructorWithParameterSharedPtr() {
    SharedPtr<int> ptr(new int(42));
    if (*ptr == 42 && ptr.num_count() == 1) {
        std::cout << "testConstructorWithParameter PASSED\n";
    } else {
        std::cout << "testConstructorWithParameter FAILED\n";
    }
}

void testCopyConstructorSharedPtr() {
    SharedPtr<int> ptr1(new int(42));
    SharedPtr<int> ptr2(ptr1);

    if (*ptr1 == 42 && *ptr2 == 42 && ptr1.num_count() == 2 && ptr2.num_count() == 2) {
        std::cout << "testCopyConstructor PASSED\n";
    } else {
        std::cout << "testCopyConstructor FAILED\n";
    }
}

void testCopyAssignmentSharedPtr() {
    SharedPtr<int> ptr1(new int(42));
    SharedPtr<int> ptr2;
    ptr2 = ptr1;

    if (*ptr1 == 42 && *ptr2 == 42 && ptr1.num_count() == 2 && ptr2.num_count() == 2) {
        std::cout << "testCopyAssignment PASSED\n";
    } else {
        std::cout << "testCopyAssignment FAILED\n";
    }
}

void testDereferenceOperatorSharedPtr() {
    SharedPtr<int> ptr(new int(42));
    if (*ptr == 42) {
        std::cout << "testDereferenceOperator PASSED\n";
    } else {
        std::cout << "testDereferenceOperator FAILED\n";
    }
}

void testArrowOperatorSharedPtr() {
    struct TestClass {
        int value;
        TestClass(int val) : value(val) {}
    };

    SharedPtr<TestClass> ptr(new TestClass(42));
    if (ptr->value == 42) {
        std::cout << "testArrowOperator PASSED\n";
    } else {
        std::cout << "testArrowOperator FAILED\n";
    }
}

void testResetSharedPtr() {
    SharedPtr<int> ptr(new int(42));
    ptr.reset(new int(100));

    if (*ptr == 100 && ptr.num_count() == 1) {
        std::cout << "testReset PASSED\n";
    } else {
        std::cout << "testReset FAILED\n";
    }
}

void testReferenceCountingSharedPtr() {
    SharedPtr<int> ptr1(new int(42));
    SharedPtr<int> ptr2(ptr1);
    SharedPtr<int> ptr3(ptr2);

    if (ptr1.num_count() == 3 && ptr2.num_count() == 3 && ptr3.num_count() == 3) {
        std::cout << "testReferenceCounting PASSED\n";
    } else {
        std::cout << "testReferenceCounting FAILED\n";
    }

    ptr3.reset();
    if (ptr1.num_count() == 2 && ptr2.num_count() == 2 && ptr3.num_count() == 0) {
        std::cout << "testReferenceCounting after reset PASSED\n";
    } else {
        std::cout << "testReferenceCounting after reset FAILED\n";
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