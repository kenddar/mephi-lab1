#ifndef listsequence_hpp
#define listsequence_hpp

#include <iostream>
#include "linkedlist.hpp"
#include "sequence.h"
#include "SharedPtr.h"  // Ваш умный указатель SharedPtr

template<class T>
class ListSequence : public Sequence<T> {
private:
    SharedPtr<LinkedList<T>> data;  // Используем SharedPtr для управления LinkedList

public:
    // Конструктор с массивом элементов и их количеством
    ListSequence(T* items, int count) {
        this->data = SharedPtr<LinkedList<T>>(new LinkedList<T>(items, count));
    }

    // Конструктор по умолчанию
    ListSequence() {
        this->data = SharedPtr<LinkedList<T>>(new LinkedList<T>());
    }

    // Конструктор копирования
    ListSequence(const ListSequence<T>& list) {
        this->data = list.data;  // SharedPtr автоматически увеличивает счетчик ссылок
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
        // Получаем подсписок как SharedPtr
        SharedPtr<LinkedList<T>> sublist = SharedPtr<LinkedList<T>>(this->data->GetSubList(startIndex, endIndex));
        ListSequence<T>* newSeq = new ListSequence<T>();
        newSeq->data = sublist;  // SharedPtr обеспечит корректное управление памятью
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

        // Создаем SharedPtr из нового LinkedList
        SharedPtr<LinkedList<T>> sharedNewList(newList);

        // Создаем новую последовательность
        ListSequence<T>* result = new ListSequence<T>();
        result->data = sharedNewList;  // SharedPtr гарантирует корректное управление памятью
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
