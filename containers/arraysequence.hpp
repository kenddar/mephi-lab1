#ifndef arraysequence_hpp
#define arraysequence_hpp

#include "dynamicarray.hpp"
#include <iostream>

template<class T>
class ArraySequence {
private:
    DynamicArray<T> data;

public:
    ArraySequence(T* items, int count) : data(items, count) {}

    ArraySequence() : data() {}

    ArraySequence(int size) : data(size) {}

    ArraySequence(const ArraySequence<T>& array) : data(array.data) {}

    T GetFirst() {
        return data.Get(0);
    }

    T GetLast() {
        return data.Get(data.GetSize() - 1);
    }

    T Get(int index) {
        return data.Get(index);
    }

    ArraySequence<T>* GetSubsequence(int startIndex, int endIndex) {
        if (data.GetSize() <= 0 || startIndex < 0 || startIndex >= data.GetSize() ||
            endIndex < 0 || endIndex >= data.GetSize() || endIndex <= startIndex) {
            throw std::out_of_range("Incorrect index.");
        } else {
            auto newItem = new ArraySequence<T>((endIndex - startIndex) + 1);
            int index = 0;
            for (int i = startIndex; i <= endIndex; ++i) {
                T element = data.Get(i);
                newItem->data.Set(index++, element);
            }
            return newItem;
        }
    }

    int GetLength() {
        return data.GetSize();
    }

    void Append(T item) {
        data.Resize(data.GetSize() + 1);
        data.Set(data.GetSize() - 1, item);
    }

    void Prepend(T item) {
        data.Resize(data.GetSize() + 1);
        for (int i = data.GetSize() - 1; i > 0; --i) {
            T element = data.Get(i - 1);
            data.Set(i, element);
        }
        data.Set(0, item);
    }

    void InsertAt(T item, int index) {
        data.Resize(data.GetSize() + 1);
        for (int i = data.GetSize() - 1; i > index; --i) {
            T element = data.Get(i - 1);
            data.Set(i, element);
        }
        data.Set(index, item);
    }

    ArraySequence<T>* Concat(ArraySequence<T>* list) {
        auto newItem = new ArraySequence<T>(data.GetSize() + list->data.GetSize());
        int index = 0;

        for (int i = 0; i < data.GetSize(); ++i) {
            newItem->data.Set(index++, data.Get(i));
        }
        for (int i = 0; i < list->data.GetSize(); ++i) {
            newItem->data.Set(index++, list->data.Get(i));
        }

        return newItem;
    }
};

#endif /* arraysequence_hpp */
