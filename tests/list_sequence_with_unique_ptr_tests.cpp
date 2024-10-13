#include <iostream>
#include <cassert>  // Для assert, который помогает проверять условия в тестах
#include "../containers/listsequence.hpp"  // Подключаем ваш класс ListSequence

// Тест метода GetFirst для ListSequence
void TestListGetFirst() {
    int items[] = {1, 2, 3, 4};
    ListSequence<int> seq(items, 4);
    assert(seq.GetFirst() == 1);  // Проверка, что первый элемент равен 1
    std::cout << "TestListGetFirst passed!" << std::endl;
}

// Тест метода GetLast для ListSequence
void TestListGetLast() {
    int items[] = {1, 2, 3, 4};
    ListSequence<int> seq(items, 4);
    assert(seq.GetLast() == 4);  // Проверка, что последний элемент равен 4
    std::cout << "TestListGetLast passed!" << std::endl;
}

// Тест метода Get для ListSequence
void TestListGet() {
    int items[] = {1, 2, 3, 4};
    ListSequence<int> seq(items, 4);
    assert(seq.Get(2) == 3);  // Проверка, что элемент с индексом 2 равен 3
    std::cout << "TestListGet passed!" << std::endl;
}

// Тест метода GetLength для ListSequence
void TestListGetLength() {
    int items[] = {1, 2, 3, 4};
    ListSequence<int> seq(items, 4);
    assert(seq.GetLength() == 4);  // Проверка, что длина списка равна 4
    std::cout << "TestListGetLength passed!" << std::endl;
}

// Тест метода Append для ListSequence
void TestListAppend() {
    ListSequence<int> seq;
    seq.Append(10);  // Добавляем элемент 10 в пустой список
    assert(seq.GetLength() == 1);  // Проверка, что длина списка стала 1
    assert(seq.GetLast() == 10);  // Проверка, что последний элемент равен 10
    std::cout << "TestListAppend passed!" << std::endl;
}

// Тест метода InsertAt для ListSequence
void TestListInsertAt() {
    int items[] = {1, 2, 4, 5};
    ListSequence<int> seq(items, 4);
    seq.InsertAt(3, 2);  // Вставляем элемент 3 в индекс 2
    assert(seq.Get(2) == 3);  // Проверка, что элемент с индексом 2 теперь равен 3
    assert(seq.GetLength() == 5);  // Проверка, что длина списка увеличилась до 5
    std::cout << "TestListInsertAt passed!" << std::endl;
}

// Тест для вставки элемента по недопустимому индексу в ListSequence
void TestListInsertAtOutOfRange() {
    int items[] = {1, 2, 3, 4};
    ListSequence<int> seq(items, 4);
    bool exceptionCaught = false;

    try {
        seq.InsertAt(5, 10);  // Пытаемся вставить элемент в недопустимый индекс (10)
    } catch (const std::out_of_range& e) {
        exceptionCaught = true;  // Если поймали исключение, меняем флаг на true
    }

    assert(exceptionCaught);  // Проверка, что исключение было выброшено
    std::cout << "TestListInsertAtOutOfRange passed!" << std::endl;
}

// Тест для получения элемента по недопустимому индексу в ListSequence
void TestListGetOutOfRange() {
    int items[] = {1, 2, 3, 4};
    ListSequence<int> seq(items, 4);
    bool exceptionCaught = false;

    try {
        seq.Get(10);  // Пытаемся получить элемент с недопустимым индексом (10)
    } catch (const std::out_of_range& e) {
        exceptionCaught = true;  // Если поймали исключение, меняем флаг на true
    }

    assert(exceptionCaught);  // Проверка, что исключение было выброшено
    std::cout << "TestListGetOutOfRange passed!" << std::endl;
}

// Тест для метода Concat в ListSequence
void TestListConcat() {
    int items1[] = {1, 2, 3};
    int items2[] = {4, 5, 6};

    ListSequence<int> seq1(items1, 3);  // Последовательность 1: {1, 2, 3}
    ListSequence<int> seq2(items2, 3);  // Последовательность 2: {4, 5, 6}

    ListSequence<int>* resultSeq = dynamic_cast<ListSequence<int>*>(seq1.Concat(&seq2));

    assert(resultSeq->GetLength() == 6);  // 3 элемента + 3 элемента = 6

    assert(resultSeq->Get(0) == 1);
    assert(resultSeq->Get(1) == 2);
    assert(resultSeq->Get(2) == 3);
    assert(resultSeq->Get(3) == 4);
    assert(resultSeq->Get(4) == 5);
    assert(resultSeq->Get(5) == 6);

    std::cout << "TestListConcat passed!" << std::endl;

    delete resultSeq;  // Освобождаем память для результата конкатенации
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
    TestListConcat();
}
