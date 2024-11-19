#ifndef LAB1SEM3_DYNAMICARRAY_HPP
#define LAB1SEM3_DYNAMICARRAY_HPP
#include <stdio.h>
#include <iostream>
#include "../pointers/shared_ptr.h"

template<class T>
class DynamicArray {
private:
    SharedPtr<T> array;
    int count;

public:
    DynamicArray(T* items, int size) {
        T* newArray = new T[size];
        for(int i = 0; i < size; i++) {
            newArray[i] = items[i];
        }
        array.reset(newArray);
        count = size;
    }

    DynamicArray() : count(0) {
        array.reset(nullptr);
    }

    DynamicArray(int size) : count(size) {
        array.reset(new T[size]);
    }

    DynamicArray(const DynamicArray<T>& dynamicArray) : count(dynamicArray.count) {
        T* newArray = new T[count];
        for (int i = 0; i < count; i++) {
            newArray[i] = *(dynamicArray.array.get() + i);
        }
        array.reset(newArray);
    }

    T Get(int index) {
        if (index < 0 || index >= count)
            throw std::out_of_range("index");
        return *(array.get() + index);
    }

    int GetSize() {
        return count;
    }

    void Set(int index, T value) {
        if(index < 0 || index >= count) {
            throw std::out_of_range("index");
        }
        *(array.get() + index) = value;
    }

    void Resize(int newSize) {
        if (newSize < 0) {
            throw std::out_of_range("newSize");
        }

        if (newSize == 0) {
            array.reset(nullptr);
            count = 0;
        } else {
            T* newArray = new T[newSize];

            for (int i = 0; i < (newSize < count ? newSize : count); ++i) {
                newArray[i] = *(array.get() + i);
            }

            array.reset(newArray);
            count = newSize;
        }
    }

    ~DynamicArray() {
        // SharedPtr will automatically handle memory cleanup
    }
};

#endif //LAB1SEM3_DYNAMICARRAY_HPP
