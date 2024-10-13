
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
    DynamicArray(DynamicArray<T> & dynamicArray){
        this->count = dynamicArray.count;
        for(int i = 0; i < this->count; i++){
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
    void Resize(int newSize){
        if(newSize < 0 )
            throw std::out_of_range("newSize");
        if(newSize == 0){
            this->count=0;
            this->array= NULL;
        }
        this->array = (T *)realloc(this->array, newSize * sizeof(T));
        this->count = newSize;
    }
    
    
};

#endif //LAB1SEM3_DYNAMICARRAY_HPP
