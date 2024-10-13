#ifndef SMART_ARRAY_HPP
#define SMART_ARRAY_HPP

#include "../pointers/smart_ptr.h"
#include <stdexcept>
#include <iostream>
#include <iostream>

template<typename T>
class SmartArray {
private:
    SmartPtr<T> data; // Умный указатель на первый элемент массива
    size_t size;      // Размер массива

public:
    // Конструктор
    SmartArray(size_t size) : size(size) {
        data.reset(new T[size]); // Выделяем память для массива
    }

    // Доступ к элементу массива
    T& operator[](size_t index) {
        return data.get()[index];
    }

    // Получение размера массива
    size_t getSize() const {
        return size;
    }

    // Метод добавления элемента в конец массива (расширение)
    void append(const T& element) {
        SmartPtr<T> newData(new T[size + 1]); // Создаем новый массив на 1 элемент больше
        for (size_t i = 0; i < size; ++i) {
            newData.get()[i] = data.get()[i]; // Копируем старые элементы
        }
        newData.get()[size] = element; // Добавляем новый элемент
        size++; // Увеличиваем размер
        data = std::move(newData); // Используем move для переноса владения
    }


    // Метод для вывода элементов массива
    void print() const {
        for (size_t i = 0; i < size; ++i) {
            std::cout << data.get()[i] << " ";
        }
        std::cout << std::endl;
    }
};

#endif // SMART_ARRAY_HPP
