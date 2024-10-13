#include "time_tests.cpp"
#include "SmartPtr_tests.h"
#include "SharedPtr_tests.h"
#include "UniquePtr_tests.h"
#include "menu.h"
#include "tests.h"

void option1(){
    testDefaultConstructorUniquePtr();
    testExplicitConstructorUniquePtr();
    testMoveConstructorUniquePtr();
    testMoveAssignmentUniquePtr();
    testDereferenceOperatorUniquePtr();
    testArrowOperatorUniquePtr();
    testReleaseMethodUniquePtr();
    testResetMethodUniquePtr();
}

void option2(){
    testDefaultConstructorSmartPtr();
    testConstructorWithParameterSmartPtr();
    testCopyConstructorSmartPtr();
    testCopyAssignmentSmartPtr();
    testMoveConstructorSmartPtr();
    testMoveAssignmentSmartPtr();
    testResetSmartPtr();
    testDereferenceOperatorSmartPtr();
    testArrowOperatorSmartPtr();
}

void option3(){
    testDefaultConstructorSharedPtr();
    testConstructorWithParameterSharedPtr();
    testCopyConstructorSharedPtr();
    testCopyAssignmentSharedPtr();
    testDereferenceOperatorSharedPtr();
    testArrowOperatorSharedPtr();
    testResetSharedPtr();
    testReferenceCountingSharedPtr();
}

void option4(){
    testPointerCreation();
    testPointerCopy();
    testPointerMove();
}

void option5(){
    TestConstructorWithArray();
    TestDefaultConstructor();
    TestCopyConstructor();
    TestGetFirst();
    TestGetLast();
    TestGet();
    TestGetSubsequence();
    TestGetLength();
    TestAppend();
    TestPrepend();
    TestInsertAt();
    TestConcat();
    TestSharedPtrUsage();
}

void menu() {
    int choice;

    do {
        std::cout << "\nMenu:\n";
        std::cout << "1. UniquePtr tests\n";
        std::cout << "2. SmartPtr tests\n";
        std::cout << "3. SharedPtr tests\n";
        std::cout << "4. Time tests\n";
        std::cout << "5. Arr tests\n";
        std::cout << "6. Exit\n";
        std::cout << "Choose an option: ";
        std::cin >> choice;
        std::cin.clear();
        while (std::cin.get() != '\n');

        switch (choice) {
            case 1:
                option1();
                break;
            case 2:
                option2();
                break;
            case 3:
                option3();
                break;
            case 4:
                option4();
                break;
            case 5:
                option5();
                break;
            case 6:
                std::cout << "Exit\n";
                break;
            default:
                std::cout << "Incorrect choice. Try again.\n";
                break;
        }
    } while (choice != 6);
}

