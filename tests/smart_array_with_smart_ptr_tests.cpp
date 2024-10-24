#include "smart_array_with_smart_ptr_tests.h"
#include <iostream>
#include "../containers/smart_array.h"

void testInitialization() {
    SmartArray<int> arr(5);
    for (size_t i = 0; i < arr.getSize(); ++i) {
        arr[i] = static_cast<int>(i + 1);
    }

    if (arr.getSize() != 5) {
        std::cout << "TestInitialization failed!" << std::endl;
    } else {
        std::cout << "TestInitialization passed!" << std::endl;
    }
}

void testAccessElements() {
    SmartArray<int> arr(5);
    for (size_t i = 0; i < arr.getSize(); ++i) {
        arr[i] = static_cast<int>(i + 1);
    }

    bool passed = true;
    for (size_t i = 0; i < arr.getSize(); ++i) {
        if (arr[i] != static_cast<int>(i + 1)) {
            std::cout << "TestAccessElements failed!" << std::endl;
            passed = false;
        }
    }

    if (passed) {
        std::cout << "TestAccessElements passed!" << std::endl;
    }
}

void testAppendElements() {
    SmartArray<int> arr(5);
    for (size_t i = 0; i < arr.getSize(); ++i) {
        arr[i] = static_cast<int>(i + 1);
    }

    arr.append(6);
    if (arr.getSize() != 6 || arr[5] != 6) {
        std::cout << "TestAppendElements failed!" << std::endl;
    } else {
        std::cout << "TestAppendElements passed!" << std::endl;
    }

}

void smart_array_with_smart_ptr_test() {
    testInitialization();
    testAccessElements();
    testAppendElements();
}
