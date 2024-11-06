#ifndef listsequence_hpp
#define listsequence_hpp

#include <iostream>
#include "linkedlist.hpp"
#include "../pointers/unique_ptr.h"

template<class T>
class ListSequence{
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




};

#endif /* listsequence_hpp */
