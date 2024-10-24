#include "smart_ptr_tests.h"
#include <iostream>
#include "../pointers/smart_ptr.h"

void testDefaultConstructorSmartPtr() {
    SmartPtr<int> ptr;
    if (ptr.get() == nullptr && ptr.num_count() == 0) {
        std::cout << "TestDefaultConstructor passed!\n";
    } else {
        std::cout << "TestDefaultConstructor failed!\n";
    }
}

void testConstructorWithParameterSmartPtr() {
    SmartPtr<int> ptr(new int(42));
    if (*ptr == 42 && ptr.num_count() == 1) {
        std::cout << "TestConstructorWithParameter passed!\n";
    } else {
        std::cout << "TestConstructorWithParameter failed!\n";
    }
}

void testCopyConstructorSmartPtr() {
    SmartPtr<int> ptr1(new int(42));
    SmartPtr<int> ptr2(ptr1);

    if (*ptr1 == 42 && *ptr2 == 42 && ptr1.num_count() == 2 && ptr2.num_count() == 2) {
        std::cout << "TestCopyConstructor passed!\n";
    } else {
        std::cout << "TestCopyConstructor failed!\n";
    }
}

void testCopyAssignmentSmartPtr() {
    SmartPtr<int> ptr1(new int(42));
    SmartPtr<int> ptr2;
    ptr2 = ptr1;

    if (*ptr1 == 42 && *ptr2 == 42 && ptr1.num_count() == 2 && ptr2.num_count() == 2) {
        std::cout << "TestCopyAssignment passed!\n";
    } else {
        std::cout << "TestCopyAssignment failed!\n";
    }
}

void testMoveConstructorSmartPtr() {
    SmartPtr<int> ptr1(new int(42));
    SmartPtr<int> ptr2(std::move(ptr1));

    if (ptr1.get() == nullptr && *ptr2 == 42 && ptr2.num_count() == 1) {
        std::cout << "TestMoveConstructor passed!\n";
    } else {
        std::cout << "TestMoveConstructor failed!\n";
    }
}

void testMoveAssignmentSmartPtr() {
    SmartPtr<int> ptr1(new int(42));
    SmartPtr<int> ptr2;
    ptr2 = std::move(ptr1);

    if (ptr1.get() == nullptr && *ptr2 == 42 && ptr2.num_count() == 1) {
        std::cout << "TestMoveAssignment passed!\n";
    } else {
        std::cout << "TestMoveAssignment failed!\n";
    }
}

void testResetSmartPtr() {
    SmartPtr<int> ptr(new int(42));
    ptr.reset(new int(100));

    if (*ptr == 100 && ptr.num_count() == 1) {
        std::cout << "TestReset passed!\n";
    } else {
        std::cout << "TestReset failed!\n";
    }
}

void testDereferenceOperatorSmartPtr() {
    SmartPtr<int> ptr(new int(42));
    if (*ptr == 42) {
        std::cout << "TestDereferenceOperator passed!\n";
    } else {
        std::cout << "TestDereferenceOperator failed!\n";
    }
}

void testArrowOperatorSmartPtr() {
    struct TestClass {
        int value;
        TestClass(int val) : value(val) {}
    };

    SmartPtr<TestClass> ptr(new TestClass(42));
    if (ptr->value == 42) {
        std::cout << "TestArrowOperator passed!\n";
    } else {
        std::cout << "TestArrowOperator failed!\n";
    }
}

void CallingSmartPtrTests(){
    testArrowOperatorSmartPtr();
    testConstructorWithParameterSmartPtr();
    testCopyAssignmentSmartPtr();
    testCopyConstructorSmartPtr();
    testDefaultConstructorSmartPtr();
    testDereferenceOperatorSmartPtr();
    testMoveAssignmentSmartPtr();
    testMoveConstructorSmartPtr();
    testResetSmartPtr();
}
