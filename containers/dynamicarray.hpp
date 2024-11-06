
#ifndef LAB1SEM3_DYNAMICARRAY_HPP
#define LAB1SEM3_DYNAMICARRAY_HPP
#include <stdio.h>
#include <iostream>

template<class T>
class DynamicArray{
private:
    T* array= NULL;
    int count;
public:
    DynamicArray(T* items, int size){
        this->array= new T[size];
        this->count=size;
        for(int i=0; i<size; i++){
            this->array[i]=items[i];
        }
    }
    DynamicArray(){
        this->array= NULL;
        this->count=0;
    }
    DynamicArray(int size){
        this->count=size;
        this->array=  new T[size];
    }
    DynamicArray(const DynamicArray<T>& dynamicArray) {
        this->count = dynamicArray.count;
        this->array = new T[this->count];

        for (int i = 0; i < this->count; i++) {
            this->array[i] = dynamicArray.array[i];
        }
    }

    T Get(int index){
        if (index < 0 || index >= count)
            throw std::out_of_range("index");
        return array[index];
    }
    int GetSize(){
        return this->count;
    }
    void Set(int index, T value){
        if(index <0 || index >= count){
            throw std::out_of_range("index");
        }
        this->array[index]=value;
    }

    void Resize(int newSize) {
        if (newSize < 0) {
            throw std::out_of_range("newSize");
        }

        if (newSize == 0) {
            delete[] this->array;
            this->array = nullptr;
            this->count = 0;
        } else {
            T* newArray = new T[newSize];


            for (int i = 0; i < (newSize < this->count ? newSize : this->count); ++i) {
                newArray[i] = this->array[i];
            }

            delete[] this->array;

            this->array = newArray;
            this->count = newSize;
        }
    }


};

#endif //LAB1SEM3_DYNAMICARRAY_HPP
