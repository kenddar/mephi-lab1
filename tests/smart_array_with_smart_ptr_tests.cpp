#include <iostream>
#include "../containers/smart_array.h"

void testInitialSize() {
    SmartArray<int> array(3);
    if (array.getSize() != 3) {
        std::cout << "TestInitialSize failed!" << std::endl;
    } else {
        std::cout << "TestInitialSize passed!" << std::endl;
    }
}

void testAccessElements() {
    SmartArray<int> array(3);
    array[0] = 1;
    array[1] = 2;
    array[2] = 3;

    if (array[0] != 1 || array[1] != 2 || array[2] != 3) {
        std::cout << "TestAccessElements failed!" << std::endl;
    } else {
        std::cout << "TestAccessElements passed!" << std::endl;
    }
}

void testAppendElement() {
    SmartArray<int> array(3);
    array[0] = 1;
    array[1] = 2;
    array[2] = 3;
    array.append(4);

    if (array.getSize() != 4 || array[3] != 4) {
        std::cout << "TestAppendElement failed!" << std::endl;
    } else {
        std::cout << "TestAppendElement passed!" << std::endl;
    }
}

void testAppendMultipleElements() {
    SmartArray<int> array(3);
    array[0] = 1;
    array[1] = 2;
    array[2] = 3;

    for (int i = 4; i <= 6; ++i) {
        array.append(i);
    }

    if (array.getSize() != 6 || array[3] != 4 || array[4] != 5 || array[5] != 6) {
        std::cout << "TestAppendMultipleElements failed!" << std::endl;
    } else {
        std::cout << "TestAppendMultipleElements passed!" << std::endl;
    }
}

void smart_array_with_smart_ptr_test() {
    testInitialSize();
    testAccessElements();
    testAppendElement();
    testAppendMultipleElements();

}
