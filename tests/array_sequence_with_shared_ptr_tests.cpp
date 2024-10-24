#include <iostream>
#include <cassert>
#include "../containers/arraysequence.hpp"

void TestGetFirst() {
    int items[] = {1, 2, 3, 4, 5};
    ArraySequence<int> sequence(items, 5);
    assert(sequence.GetFirst() == 1);
    std::cout << "TestGetFirst passed!" << std::endl;
}

void TestGetLast() {
    int items[] = {1, 2, 3, 4, 5};
    ArraySequence<int> sequence(items, 5);
    assert(sequence.GetLast() == 5);
    std::cout << "TestGetLast passed!" << std::endl;
}

void TestGet() {
    int items[] = {1, 2, 3, 4, 5};
    ArraySequence<int> sequence(items, 5);
    assert(sequence.Get(2) == 3);
    std::cout << "TestGet passed!" << std::endl;
}

void TestGetOutOfRange() {
    int items[] = {1, 2, 3, 4, 5};
    ArraySequence<int> sequence(items, 5);
    try {
        sequence.Get(10);
        std::cout << "TestGetOutOfRange failed!" << std::endl;
    } catch (std::out_of_range& e) {
        std::cout << "TestGetOutOfRange passed!" << std::endl;
    }
}

void TestGetLength() {
    int items[] = {1, 2, 3, 4, 5};
    ArraySequence<int> sequence(items, 5);
    assert(sequence.GetLength() == 5);
    std::cout << "TestGetLength passed!" << std::endl;
}

void TestAppend() {
    ArraySequence<int> sequence;
    sequence.Append(10);
    assert(sequence.GetLength() == 1);
    assert(sequence.Get(0) == 10);
    std::cout << "TestAppend passed!" << std::endl;
}

void TestInsertAt() {
    int items[] = {1, 2, 4, 5};
    ArraySequence<int> sequence(items, 4);
    sequence.InsertAt(3, 2);
    assert(sequence.Get(2) == 3);
    assert(sequence.GetLength() == 5);
    std::cout << "TestInsertAt passed!" << std::endl;
}

void TestInsertAtOutOfRange() {
    ArraySequence<int> sequence;
    try {
        sequence.InsertAt(1, 5);
        std::cout << "TestInsertAtOutOfRange failed!" << std::endl;
    } catch (std::out_of_range& e) {
        std::cout << "TestInsertAtOutOfRange passed!" << std::endl;
    }
}



void array_sequence_with_shared_ptr_test() {
    TestGetFirst();
    TestGet();
    TestAppend();
    TestGetLast();
    TestGetLength();
    TestGetOutOfRange();
    TestInsertAt();
    TestInsertAtOutOfRange();
}
