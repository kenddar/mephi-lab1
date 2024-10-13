#ifndef arraysequence_hpp
#define arraysequence_hpp

#include "dynamicarray.hpp"
#include "sequence.h"
#include "SharedPtr.h"  // Ваш умный указатель SharedPtr
#include <iostream>

template<class T>
class ArraySequence : public Sequence<T> {
private:
    SharedPtr<DynamicArray<T>> data;  // Используем SharedPtr для управления DynamicArray

public:
    // Конструктор с массивом элементов и их количеством
    ArraySequence(T* items, int count) {
        this->data = SharedPtr<DynamicArray<T>>(new DynamicArray<T>(items, count));
    }

    // Конструктор по умолчанию
    ArraySequence() {
        this->data = SharedPtr<DynamicArray<T>>(new DynamicArray<T>());
    }

    // Конструктор с размером массива
    ArraySequence(int size) {
        this->data = SharedPtr<DynamicArray<T>>(new DynamicArray<T>(size));
    }

    // Конструктор копирования
    ArraySequence(const ArraySequence<T>& array) {
        this->data = array.data;  // SharedPtr автоматически управляет копированием
    }

    // Получить первый элемент
    T GetFirst() {
        return this->data->Get(0);
    }

    // Получить последний элемент
    T GetLast() {
        return this->data->Get(this->data->GetSize() - 1);
    }

    // Получить элемент по индексу
    T Get(int index) {
        return this->data->Get(index);
    }

    // Получить подмассив
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

    // Получить длину массива
    int GetLength() {
        return this->data->GetSize();
    }

    // Добавить элемент в конец массива
    void Append(T item) {
        this->data->Resize(this->data->GetSize() + 1);
        this->data->Set(this->data->GetSize() - 1, item);
    }

    // Добавить элемент в начало массива
    void Prepend(T item) {
        this->data->Resize(this->data->GetSize() + 1);
        for (int i = this->data->GetSize() - 1; i > 0; --i) {
            T element = this->data->Get(i - 1);
            this->data->Set(i, element);
        }
        this->data->Set(0, item);
    }

    // Вставить элемент по индексу
    void InsertAt(T item, int index) {
        this->data->Resize(this->data->GetSize() + 1);
        for (int i = this->data->GetSize() - 1; i > index; --i) {
            T element = this->data->Get(i - 1);
            this->data->Set(i, element);
        }
        this->data->Set(index, item);
    }

    // Конкатенация двух массивов
    Sequence<T>* Concat(ArraySequence<T>* list) {
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

    // Печать массива
    void Print() {
        for (int i = 0; i < this->data->GetSize(); ++i) {
            std::cout << this->data->Get(i) << " ";
        }
        std::cout << std::endl;
    }
};

#endif /* arraysequence_hpp */
