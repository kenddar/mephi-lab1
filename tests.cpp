#include "tests.h"
#include <iostream>
#include <cassert>
#include "listsequence.hpp"

// Тест конструктора с массивом элементов
void TestConstructorWithArray() {
    int items[] = {1, 2, 3, 4, 5};
    ListSequence<int> sequence(items, 5);

    assert(sequence.GetLength() == 5);
    assert(sequence.GetFirst() == 1);
    assert(sequence.GetLast() == 5);

    std::cout << "TestConstructorWithArray: test PASSED" << std::endl;
}

// Тест конструктора по умолчанию
void TestDefaultConstructor() {
    ListSequence<int> sequence;

    assert(sequence.GetLength() == 0);  // Пустой список

    std::cout << "TestDefaultConstructor: test PASSED" << std::endl;
}

// Тест конструктора копирования
void TestCopyConstructor() {
    int items[] = {1, 2, 3};
    ListSequence<int> sequence1(items, 3);
    ListSequence<int> sequence2(sequence1);  // Копирование

    assert(sequence2.GetLength() == 3);
    assert(sequence2.GetFirst() == 1);
    assert(sequence2.GetLast() == 3);

    std::cout << "TestCopyConstructor: test PASSED" << std::endl;
}

// Тест метода GetFirst
void TestGetFirst() {
    int items[] = {10, 20, 30};
    ListSequence<int> sequence(items, 3);

    assert(sequence.GetFirst() == 10);

    std::cout << "TestGetFirst: test PASSED" << std::endl;
}

// Тест метода GetLast
void TestGetLast() {
    int items[] = {10, 20, 30};
    ListSequence<int> sequence(items, 3);

    assert(sequence.GetLast() == 30);

    std::cout << "TestGetLast: test PASSED" << std::endl;
}

// Тест метода Get
void TestGet() {
    int items[] = {10, 20, 30, 40};
    ListSequence<int> sequence(items, 4);

    assert(sequence.Get(1) == 20);
    assert(sequence.Get(2) == 30);

    std::cout << "TestGet: test PASSED" << std::endl;
}

// Тест метода GetSubsequence
void TestGetSubsequence() {
    int items[] = {1, 2, 3, 4, 5};
    ListSequence<int> sequence(items, 5);

    ListSequence<int>* subsequence = sequence.GetSubsequence(1, 3);  // Получаем подсписок

    assert(subsequence->GetLength() == 3);
    assert(subsequence->Get(0) == 2);
    assert(subsequence->Get(2) == 4);

    delete subsequence;  // Не забываем освободить подсписок

    std::cout << "TestGetSubsequence: test PASSED" << std::endl;
}

// Тест метода GetLength
void TestGetLength() {
    int items[] = {1, 2, 3};
    ListSequence<int> sequence(items, 3);

    assert(sequence.GetLength() == 3);

    std::cout << "TestGetLength: test PASSED" << std::endl;
}

// Тест метода Append
void TestAppend() {
    ListSequence<int> sequence;
    sequence.Append(10);
    sequence.Append(20);

    assert(sequence.GetLength() == 2);
    assert(sequence.GetFirst() == 10);
    assert(sequence.GetLast() == 20);

    std::cout << "TestAppend: test PASSED" << std::endl;
}

// Тест метода Prepend
void TestPrepend() {
    ListSequence<int> sequence;
    sequence.Append(10);
    sequence.Append(20);
    sequence.Prepend(5);  // Вставляем в начало

    assert(sequence.GetLength() == 3);
    assert(sequence.GetFirst() == 5);
    assert(sequence.Get(1) == 10);
    assert(sequence.GetLast() == 20);

    std::cout << "TestPrepend: test PASSED" << std::endl;
}

// Тест метода InsertAt
void TestInsertAt() {
    ListSequence<int> sequence;
    sequence.Append(10);
    sequence.Append(30);
    sequence.InsertAt(20, 1);  // Вставляем 20 на индекс 1

    assert(sequence.GetLength() == 3);
    assert(sequence.Get(1) == 20);

    std::cout << "TestInsertAt: test PASSED" << std::endl;
}

// Тест метода Concat
void TestConcat() {
    int items1[] = {1, 2, 3};
    int items2[] = {4, 5, 6};

    ListSequence<int> sequence1(items1, 3);
    ListSequence<int> sequence2(items2, 3);

    Sequence<int>* concatenatedSequence = sequence1.Concat(&sequence2);

    assert(concatenatedSequence->GetLength() == 6);
    assert(concatenatedSequence->Get(0) == 1);
    assert(concatenatedSequence->Get(5) == 6);

    delete concatenatedSequence;  // Освобождаем память после конкатенации

    std::cout << "TestConcat: test PASSED" << std::endl;
}

// Тест на правильное использование умных указателей SharedPtr
void TestSharedPtrUsage() {
    {
        ListSequence<int> sequence1;
        sequence1.Append(1);
        sequence1.Append(2);

        // Создаем копию sequence1, увеличиваем счетчик ссылок
        ListSequence<int> sequence2 = sequence1;
        assert(sequence2.GetLength() == 2);

        // Выйдем из этого блока, но SharedPtr должен корректно управлять памятью
    }
    // После выхода из блока память автоматически освободится SharedPtr

    std::cout << "TestSharedPtrUsage: test PASSED" << std::endl;
}

