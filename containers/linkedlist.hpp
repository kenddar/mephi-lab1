#ifndef linkedlist_hpp
#define linkedlist_hpp
#include <stdio.h>
#include <iostream>
#include "../pointers/unique_ptr.h"

template<class T>
struct Node {
    T item;
    UniquePtr<Node<T>> next;

    Node(const T& value) : item(value), next(nullptr) {}
};

template<class T>
class LinkedList {
private:
    UniquePtr<Node<T>> first;
    Node<T>* last;
    int size;

public:
    LinkedList(T* items, int count) : first(nullptr), last(nullptr), size(0) {
        for (int i = 0; i < count; ++i) {
            Append(items[i]);
        }
    }

    LinkedList() : first(nullptr), last(nullptr), size(0) {}

    LinkedList(const LinkedList<T>& list) : first(nullptr), last(nullptr), size(0) {
        Node<T>* current = list.first.get();
        while (current != nullptr) {
            Append(current->item);
            current = current->next.get();
        }
    }

    T GetFirst() {
        if (!first) {
            throw std::out_of_range("Empty list.");
        }
        return first->item;
    }

    T GetLast() {
        if (!last) {
            throw std::out_of_range("Empty list.");
        }
        return last->item;
    }

    T Get(int index) {
        if (index < 0 || index >= size) {
            throw std::out_of_range("Incorrect index.");
        }

        Node<T>* current = first.get();
        for (int i = 0; i < index; ++i) {
            current = current->next.get();
        }
        return current->item;
    }

    LinkedList<T>* GetSubList(int startIndex, int endIndex) {
        if (startIndex < 0 || endIndex >= size || startIndex > endIndex) {
            throw std::out_of_range("Invalid index range");
        }

        LinkedList<T>* subList = new LinkedList<T>();
        Node<T>* current = first.get();
        int index = 0;

        while (current != nullptr) {
            if (index >= startIndex && index <= endIndex) {
                subList->Append(current->item);
            }
            current = current->next.get();
            index++;
        }
        return subList;
    }

    int GetLength() {
        return size;
    }

    void Append(T item) {
        UniquePtr<Node<T>> newNode(new Node<T>(item));
        if (size == 0) {
            first = std::move(newNode);
            last = first.get();
        } else {
            last->next = std::move(newNode);
            last = last->next.get();
        }
        size++;
    }

    void Prepend(T item) {
        UniquePtr<Node<T>> newNode(new Node<T>(item));
        newNode->next = std::move(first);
        first = std::move(newNode);
        if (size == 0) {
            last = first.get();
        }
        size++;
    }

    void InsertAt(T item, int index) {
        if (index < 0 || index >= size) {
            throw std::out_of_range("Incorrect index.");
        }

        if (index == 0) {
            Prepend(item);
            return;
        }

        Node<T>* current = first.get();
        for (int i = 0; i < index - 1; ++i) {
            current = current->next.get();
        }

        UniquePtr<Node<T>> newNode(new Node<T>(item));
        newNode->next = std::move(current->next);
        current->next = std::move(newNode);

        if (index == size - 1) {
            last = current->next.get();
        }
        size++;
    }

    LinkedList<T>* Concat(LinkedList<T>* list) {
        LinkedList<T>* newList = new LinkedList<T>();

        // Copy elements from this list
        Node<T>* current = first.get();
        while (current != nullptr) {
            newList->Append(current->item);
            current = current->next.get();
        }

        // Copy elements from the parameter list
        current = list->first.get();
        while (current != nullptr) {
            newList->Append(current->item);
            current = current->next.get();
        }

        return newList;
    }

    ~LinkedList() {
        // UniquePtr will handle cleanup automatically
    }
};

#endif /* linkedlist_hpp */
