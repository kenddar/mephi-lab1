#include <iostream>
#include <cassert>
#include "../containers/listsequence.hpp"

void TestListGetFirst() {
    int items[] = {1, 2, 3, 4};
    ListSequence<int> seq(items, 4);
    assert(seq.GetFirst() == 1);
    std::cout << "TestListGetFirst passed!" << std::endl;
}

void TestListGetLast() {
    int items[] = {1, 2, 3, 4};
    ListSequence<int> seq(items, 4);
    assert(seq.GetLast() == 4);
    std::cout << "TestListGetLast passed!" << std::endl;
}

void TestListGet() {
    int items[] = {1, 2, 3, 4};
    ListSequence<int> seq(items, 4);
    assert(seq.Get(2) == 3);
    std::cout << "TestListGet passed!" << std::endl;
}

void TestListGetLength() {
    int items[] = {1, 2, 3, 4};
    ListSequence<int> seq(items, 4);
    assert(seq.GetLength() == 4);
    std::cout << "TestListGetLength passed!" << std::endl;
}


void TestListAppend() {
    ListSequence<int> seq;
    seq.Append(10);
    assert(seq.GetLength() == 1);
    assert(seq.GetLast() == 10);
    std::cout << "TestListAppend passed!" << std::endl;
}

void TestListInsertAt() {
    int items[] = {1, 2, 4, 5};
    ListSequence<int> seq(items, 4);
    seq.InsertAt(3, 2);
    assert(seq.Get(2) == 3);
    assert(seq.GetLength() == 5);
    std::cout << "TestListInsertAt passed!" << std::endl;
}


void TestListInsertAtOutOfRange() {
    int items[] = {1, 2, 3, 4};
    ListSequence<int> seq(items, 4);
    bool exceptionCaught = false;

    try {
        seq.InsertAt(5, 10);
    } catch (const std::out_of_range& e) {
        exceptionCaught = true;
    }

    assert(exceptionCaught);
    std::cout << "TestListInsertAtOutOfRange passed!" << std::endl;
}

void TestListGetOutOfRange() {
    int items[] = {1, 2, 3, 4};
    ListSequence<int> seq(items, 4);
    bool exceptionCaught = false;

    try {
        seq.Get(10);
    } catch (const std::out_of_range& e) {
        exceptionCaught = true;
    }

    assert(exceptionCaught);
    std::cout << "TestListGetOutOfRange passed!" << std::endl;
}


void list_sequence_with_unique_ptr_tests() {
    TestListInsertAt();
    TestListAppend();
    TestListGetLength();
    TestListGet();
    TestListGetFirst();
    TestListGetLast();
    TestListGetOutOfRange();
    TestListInsertAtOutOfRange();
}
