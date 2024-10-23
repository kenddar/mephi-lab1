#include "smart_array_with_smart_ptr_tests.h"
#include <iostream>
#include <cassert>
#include "../containers/smart_array.h"

void testInitialization() {
    // Создаем массив целых чисел с 5 элементами
    SmartArray<int> arr(5);

    // Инициализируем массив значениями
    for (size_t i = 0; i < arr.getSize(); ++i) {
        arr[i] = static_cast<int>(i + 1); // Заполняем массив 1, 2, 3, 4, 5
    }

    // Проверка начальных значений
    std::cout << "Initial array: ";
    arr.print(); // Должно вывести: 1 2 3 4 5

    // Проверка размера массива
    assert(arr.getSize() == 5); // Проверяем, что размер массива равен 5
}

void testAccessElements() {
    SmartArray<int> arr(5);

    // Инициализируем массив значениями
    for (size_t i = 0; i < arr.getSize(); ++i) {
        arr[i] = static_cast<int>(i + 1); // Заполняем массив 1, 2, 3, 4, 5
    }

    // Проверка доступа к элементам
    for (size_t i = 0; i < arr.getSize(); ++i) {
        assert(arr[i] == static_cast<int>(i + 1)); // Проверяем, что элементы массива равны ожидаемым значениям
    }
}

void testAppendElements() {
    SmartArray<int> arr(5);

    // Инициализируем массив значениями
    for (size_t i = 0; i < arr.getSize(); ++i) {
        arr[i] = static_cast<int>(i + 1); // Заполняем массив 1, 2, 3, 4, 5
    }

    // Добавляем новый элемент
    arr.append(6);
    std::cout << "After appending 6: ";
    arr.print(); // Должно вывести: 1 2 3 4 5 6
    assert(arr.getSize() == 6); // Проверяем, что размер массива теперь 6
    assert(arr[5] == 6); // Проверяем, что добавленный элемент равен 6

    // Добавляем еще один элемент
    arr.append(7);
    std::cout << "After appending 7: ";
    arr.print(); // Должно вывести: 1 2 3 4 5 6 7
    assert(arr.getSize() == 7); // Проверяем, что размер массива теперь 7
    assert(arr[6] == 7); // Проверяем, что добавленный элемент равен 7
}


void smart_array_with_smart_ptr_test() {
    testInitialization();
    testAccessElements();
    testAppendElements();

    std::cout << "All tests passed!" << std::endl;
}
