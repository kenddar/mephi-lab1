#ifndef arraysequence_hpp
#define arraysequence_hpp

#include "dynamicarray.hpp"
#include "../pointers/shared_ptr.h"
#include <iostream>

template<class T>
class ArraySequence {
private:
    SharedPtr<DynamicArray<T>> data;

public:
    ArraySequence(T* items, int count) {
        this->data = SharedPtr<DynamicArray<T>>(new DynamicArray<T>(items, count));
    }

    ArraySequence() {
        this->data = SharedPtr<DynamicArray<T>>(new DynamicArray<T>());
    }


    ArraySequence(int size) {
        this->data = SharedPtr<DynamicArray<T>>(new DynamicArray<T>(size));
    }

    ArraySequence(const ArraySequence<T>& array) {
        this->data = array.data;
    }

    T GetFirst() {
        return this->data->Get(0);
    }

    T GetLast() {
        return this->data->Get(this->data->GetSize() - 1);
    }

    T Get(int index) {
        return this->data->Get(index);
    }


    ArraySequence<T>* GetSubsequence(int startIndex, int endIndex) {
        if (this->data->GetSize() <= 0 || startIndex < 0 || startIndex >= this->data->GetSize() ||
            endIndex < 0 || endIndex >= this->data->GetSize() || endIndex <= startIndex) {
            throw std::out_of_range("Incorrect index.");
        } else {
            auto newItem = new ArraySequence<T>((endIndex - startIndex) + 1);
            int index = 0;
            for (int i = startIndex; i <= endIndex; ++i) {
                T element = this->data->Get(i);
                newItem->data->Set(index++, element);
            }
            return newItem;
        }
    }


    int GetLength() {
        return this->data->GetSize();
    }

    void Append(T item) {
        this->data->Resize(this->data->GetSize() + 1);
        this->data->Set(this->data->GetSize() - 1, item);
    }

    void Prepend(T item) {
        this->data->Resize(this->data->GetSize() + 1);
        for (int i = this->data->GetSize() - 1; i > 0; --i) {
            T element = this->data->Get(i - 1);
            this->data->Set(i, element);
        }
        this->data->Set(0, item);
    }


    void InsertAt(T item, int index) {
        this->data->Resize(this->data->GetSize() + 1);
        for (int i = this->data->GetSize() - 1; i > index; --i) {
            T element = this->data->Get(i - 1);
            this->data->Set(i, element);
        }
        this->data->Set(index, item);
    }


    ArraySequence<T>* Concat(ArraySequence<T>* list) {
        auto newItem = new ArraySequence<T>(this->data->GetSize() + list->data->GetSize());
        int index = 0;

        for (int i = 0; i < this->data->GetSize(); ++i) {
            newItem->data->Set(index++, this->data->Get(i));
        }
        for (int i = 0; i < list->data->GetSize(); ++i) {
            newItem->data->Set(index++, list->data->Get(i));
        }

        return newItem;
    }



};

#endif /* arraysequence_hpp */
