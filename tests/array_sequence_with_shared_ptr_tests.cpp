#include <iostream>
#include <cassert>
#include "../containers/arraysequence.hpp"

void TestGetFirst() {
    int items[] = {1, 2, 3, 4, 5};
    ArraySequence<int> sequence(items, 5);
    assert(sequence.GetFirst() == 1);  // Проверяем, что первый элемент равен 1
    std::cout << "TestGetFirst passed!" << std::endl;
}

void TestGetLast() {
    int items[] = {1, 2, 3, 4, 5};
    ArraySequence<int> sequence(items, 5);
    assert(sequence.GetLast() == 5);  // Проверяем, что последний элемент равен 5
    std::cout << "TestGetLast passed!" << std::endl;
}

void TestGet() {
    int items[] = {1, 2, 3, 4, 5};
    ArraySequence<int> sequence(items, 5);
    assert(sequence.Get(2) == 3);  // Проверяем, что элемент с индексом 2 равен 3
    std::cout << "TestGet passed!" << std::endl;
}

void TestGetOutOfRange() {
    int items[] = {1, 2, 3, 4, 5};
    ArraySequence<int> sequence(items, 5);
    try {
        sequence.Get(10);  // Обращаемся к индексу за пределами массива
        std::cout << "TestGetOutOfRange failed!" << std::endl;  // Если исключение не выброшено
    } catch (std::out_of_range& e) {
        std::cout << "TestGetOutOfRange passed!" << std::endl;  // Ожидаем выброс исключения
    }
}

void TestGetLength() {
    int items[] = {1, 2, 3, 4, 5};
    ArraySequence<int> sequence(items, 5);
    assert(sequence.GetLength() == 5);  // Проверяем, что длина массива равна 5
    std::cout << "TestGetLength passed!" << std::endl;
}

void TestAppend() {
    ArraySequence<int> sequence;
    sequence.Append(10);
    assert(sequence.GetLength() == 1);  // Проверяем, что длина увеличилась до 1
    assert(sequence.Get(0) == 10);      // Проверяем, что элемент добавлен в массив
    std::cout << "TestAppend passed!" << std::endl;
}

void TestInsertAt() {
    int items[] = {1, 2, 4, 5};
    ArraySequence<int> sequence(items, 4);
    sequence.InsertAt(3, 2);  // Вставляем элемент 3 на индекс 2
    assert(sequence.Get(2) == 3);       // Проверяем, что элемент вставлен корректно
    assert(sequence.GetLength() == 5);  // Проверяем, что длина массива увеличилась
    std::cout << "TestInsertAt passed!" << std::endl;
}

void TestInsertAtOutOfRange() {
    ArraySequence<int> sequence;
    try {
        sequence.InsertAt(1, 5);  // Пытаемся вставить элемент за пределами массива
        std::cout << "TestInsertAtOutOfRange failed!" << std::endl;  // Если исключение не выброшено
    } catch (std::out_of_range& e) {
        std::cout << "TestInsertAtOutOfRange passed!" << std::endl;  // Ожидаем выброс исключения
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
