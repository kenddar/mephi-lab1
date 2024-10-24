#ifndef SMART_ARRAY_HPP
#define SMART_ARRAY_HPP

#include "../pointers/smart_ptr.h"
#include <stdexcept>
#include <iostream>
#include <iostream>

template<typename T>
class SmartArray {
private:
    SmartPtr<T> data;
    size_t size;

public:
    SmartArray(size_t size) : size(size) {
        data.reset(new T[size]);
    }

    T& operator[](size_t index) {
        return data.get()[index];
    }

    size_t getSize() const {
        return size;
    }

    void append(const T& element) {
        SmartPtr<T> newData(new T[size + 1]);
        for (size_t i = 0; i < size; ++i) {
            newData.get()[i] = data.get()[i];
        }
        newData.get()[size] = element;
        size++;
        data = std::move(newData);
    }


    void print() const {
        for (size_t i = 0; i < size; ++i) {
            std::cout << data.get()[i] << " ";
        }
        std::cout << std::endl;
    }
};

#endif // SMART_ARRAY_HPP
