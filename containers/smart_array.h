#ifndef SMART_ARRAY_HPP
#define SMART_ARRAY_HPP

#include "../pointers/smart_ptr.h"
#include <stdexcept>

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
        if (index >= size) {
            throw std::out_of_range("Index out of range");
        }
        return data[index];
    }

    size_t getSize() const {
        return size;
    }

    void append(const T& element) {
        SmartPtr<T> newData(new T[size + 1]);
        for (size_t i = 0; i < size; ++i) {
            newData[i] = data[i];
        }
        newData[size] = element;
        size++;
        data = std::move(newData);
    }
};

#endif // SMART_ARRAY_HPP
