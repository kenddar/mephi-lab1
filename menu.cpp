#include "tests/time_tests.cpp"
#include "menu.h"
#include "tests/array_sequence_with_shared_ptr_tests.h"
#include "tests/smart_array_with_smart_ptr_tests.h"
#include "tests/list_sequence_with_unique_ptr_tests.h"


void print_menu(){
    std::cout << "\nMenu:\n";
    std::cout << "1. Shared pointer tests\n";
    std::cout << "2. Unique pointer tests\n";
    std::cout << "3. Smart pointer tests\n";
    std::cout << "4. Exit\n";
    std::cout << "Choose an option: ";
}

void menu() {
    int choice;

    do {
        print_menu();
        std::cin >> choice;
        std::cin.clear();
        while (std::cin.get() != '\n');

        switch (choice) {
            case 1:
                array_sequence_with_shared_ptr_test();
                break;
            case 2:
                list_sequence_with_unique_ptr_tests();
                break;
            case 3:
                smart_array_with_smart_ptr_test();
            case 4:
                std::cout << "Exit\n";
                break;
            default:
                std::cout << "Incorrect choice. Try again.\n";
                break;
        }
    } while (choice != 4);
}


