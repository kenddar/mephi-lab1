#ifndef listsequence_hpp
#define listsequence_hpp

#include <iostream>
#include "linkedlist.hpp"
#include "sequence.h"
#include "../pointers/unique_ptr.h"  // Подключаем ваш умный указатель UniquePtr

template<class T>
class ListSequence : public Sequence<T> {
private:
    UniquePtr<LinkedList<T>> data;  // Используем UniquePtr для управления LinkedList

public:
    // Конструктор с массивом элементов и их количеством
    ListSequence(T* items, int count) {
        this->data = UniquePtr<LinkedList<T>>(new LinkedList<T>(items, count));
    }

    // Конструктор по умолчанию
    ListSequence() {
        this->data = UniquePtr<LinkedList<T>>(new LinkedList<T>());
    }

    // Конструктор перемещения
    ListSequence(ListSequence<T>&& list) noexcept {
        this->data = std::move(list.data);  // Используем перемещение для передачи владения указателем
    }

    // Оператор присваивания перемещения
    ListSequence<T>& operator=(ListSequence<T>&& list) noexcept {
        if (this != &list) {
            this->data = std::move(list.data);  // Перемещаем указатель
        }
        return *this;
    }

    // Получить первый элемент
    T GetFirst() {
        return this->data->GetFirst();
    }

    // Получить последний элемент
    T GetLast() {
        return this->data->GetLast();
    }

    // Получить элемент по индексу
    T Get(int index) {
        return this->data->Get(index);
    }

    // Получить подсписок
    ListSequence<T>* GetSubsequence(int startIndex, int endIndex) {
        // Получаем подсписок как UniquePtr
        UniquePtr<LinkedList<T>> sublist = UniquePtr<LinkedList<T>>(this->data->GetSubList(startIndex, endIndex));
        ListSequence<T>* newSeq = new ListSequence<T>();
        newSeq->data = std::move(sublist);  // Используем перемещение для передачи владения указателем
        return newSeq;
    }

    // Получить длину списка
    int GetLength() {
        return this->data->GetLength();
    }

    // Добавить элемент в конец списка
    void Append(T item) {
        this->data->Append(item);
    }

    // Добавить элемент в начало списка
    void Prepend(T item) {
        this->data->Prepend(item);
    }

    // Вставить элемент по индексу
    void InsertAt(T item, int index) {
        this->data->InsertAt(item, index);
    }

    // Конкатенация двух последовательностей
    Sequence<T>* Concat(ListSequence<T>* list) {
        // Получаем новый LinkedList
        LinkedList<T>* newList = this->data->Concat(list->data.get());  // Используем get() для доступа к сырому указателю

        // Создаем UniquePtr из нового LinkedList
        UniquePtr<LinkedList<T>> uniqueNewList(newList);

        // Создаем новую последовательность
        ListSequence<T>* result = new ListSequence<T>();
        result->data = std::move(uniqueNewList);  // Передаем владение указателем
        return result;
    }

    // Печать элементов списка
    void Print() {
        for (int i = 0; i < this->data->GetLength(); ++i) {
            std::cout << this->data->Get(i) << " ";
        }
        std::cout << std::endl;
    }
};

#endif /* listsequence_hpp */
