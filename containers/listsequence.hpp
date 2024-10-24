#ifndef listsequence_hpp
#define listsequence_hpp

#include <iostream>
#include "linkedlist.hpp"
#include "sequence.h"
#include "../pointers/unique_ptr.h"

template<class T>
class ListSequence : public Sequence<T> {
private:
    UniquePtr<LinkedList<T>> data;

public:
    ListSequence(T* items, int count) {
        this->data = UniquePtr<LinkedList<T>>(new LinkedList<T>(items, count));
    }

    ListSequence() {
        this->data = UniquePtr<LinkedList<T>>(new LinkedList<T>());
    }


    ListSequence(ListSequence<T>&& list) noexcept {
        this->data = std::move(list.data);
    }

    ListSequence<T>& operator=(ListSequence<T>&& list) noexcept {
        if (this != &list) {
            this->data = std::move(list.data);
        }
        return *this;
    }

    T GetFirst() {
        return this->data->GetFirst();
    }

    T GetLast() {
        return this->data->GetLast();
    }

    T Get(int index) {
        return this->data->Get(index);
    }

    ListSequence<T>* GetSubsequence(int startIndex, int endIndex) {
        UniquePtr<LinkedList<T>> sublist = UniquePtr<LinkedList<T>>(this->data->GetSubList(startIndex, endIndex));
        ListSequence<T>* newSeq = new ListSequence<T>();
        newSeq->data = std::move(sublist);
        return newSeq;
    }

    int GetLength() {
        return this->data->GetLength();
    }

    void Append(T item) {
        this->data->Append(item);
    }

    void Prepend(T item) {
        this->data->Prepend(item);
    }

    void InsertAt(T item, int index) {
        this->data->InsertAt(item, index);
    }

    Sequence<T>* Concat(ListSequence<T>* list) {
        LinkedList<T>* newList = this->data->Concat(list->data.get());


        UniquePtr<LinkedList<T>> uniqueNewList(newList);

        ListSequence<T>* result = new ListSequence<T>();
        result->data = std::move(uniqueNewList);
        return result;
    }

    void Print() {
        for (int i = 0; i < this->data->GetLength(); ++i) {
            std::cout << this->data->Get(i) << " ";
        }
        std::cout << std::endl;
    }
};

#endif /* listsequence_hpp */
