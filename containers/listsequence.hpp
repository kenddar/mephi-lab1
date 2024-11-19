#ifndef listsequence_hpp
#define listsequence_hpp

#include <iostream>
#include "linkedlist.hpp"

template<class T>
class ListSequence {
private:
    LinkedList<T> data;

public:
    ListSequence(T* items, int count) : data(items, count) {}

    ListSequence() : data() {}

    ListSequence(const ListSequence<T>& list) : data(list.data) {}

    T GetFirst() {
        return data.GetFirst();
    }

    T GetLast() {
        return data.GetLast();
    }

    T Get(int index) {
        return data.Get(index);
    }

    ListSequence<T>* GetSubsequence(int startIndex, int endIndex) {
        ListSequence<T>* newSeq = new ListSequence<T>();
        LinkedList<T>* sublist = data.GetSubList(startIndex, endIndex);
        newSeq->data = *sublist;
        delete sublist;
        return newSeq;
    }

    int GetLength() {
        return data.GetLength();
    }

    void Append(T item) {
        data.Append(item);
    }

    void Prepend(T item) {
        data.Prepend(item);
    }

    void InsertAt(T item, int index) {
        data.InsertAt(item, index);
    }
};

#endif /* listsequence_hpp */
