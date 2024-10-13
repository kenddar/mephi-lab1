#ifndef linkedlist_hpp
#define linkedlist_hpp
#include <stdio.h>
#include <iostream>
template<class T>
struct Node{
    T item;
    Node *next;
};

template<class T>
class LinkedList{
private:
    Node<T> *first;
    Node<T> *last;
    int size;
public:
    LinkedList (T* items, int count){
        int list_size = 0;
        int items_index = 0;
        Node<T> *tmp1 = NULL;
        Node<T> *tmp2 = NULL;
        do{
            if(this->first == NULL){
                tmp1 = (Node<T> *)malloc(sizeof(Node<T>));
                tmp1->item = items[items_index];
                tmp1->next = this->first;
                this->first = tmp1;
                items_index++;
            }else{
                if(items_index == count){
                    tmp1->next = NULL;
                    this->last = tmp1;
                    break;
                }
                tmp2 = (Node<T> *)malloc(sizeof(Node<T>));
                tmp2->item = items[items_index];
                tmp1->next = tmp2;
                tmp1 = tmp2;
                items_index++;
            }
            list_size++;
        }while(true);

        this->size = list_size;

    }
    LinkedList (){
        this->first=NULL;
        this->size=NULL;
    }
    LinkedList (LinkedList <T> & list ){
        for (auto item : list) {
            Append(item);
        }

        this->count = list.count;
    }
    T GetFirst(){
        T firstElement;

        
            if(this->first == NULL){
                throw std::out_of_range("Empty list.");
            }else{
                firstElement = this->first->item;
                return firstElement;
            }
        }
    
    T GetLast(){
        T lastElement;
        if(this->first == NULL){
            throw std::out_of_range("Empty list.");
        }else{
            lastElement = this->last->item;
            return lastElement;
        }
    }
    T Get(int index){
        T item;
        Node<T>* tmp;
        int count = 0;

        tmp = this->first;
    
            if(index < 0 || index >= this->size){
                throw std::out_of_range("Incorrect index.");
            }else{
                while(count != index){
                    tmp = tmp->next;
                    count++;
                }

                item = tmp->item;

                return item;
            }
    }
    LinkedList<T>* GetSubList(int startIndex, int endIndex) {
        if (startIndex < 0 || endIndex >= size || startIndex > endIndex) {
            throw std::out_of_range("Invalid index range");
        }
        LinkedList<T> *subList = new LinkedList<T>();
        Node<T> *current = first;
        int index = 0;
        while (current != NULL) {
            if (index >= startIndex && index <= endIndex) {
                subList->Append(current->item);
            }
            current = current->next;
            index++;
        }
        return subList;
    }

    int GetLength(){
        return this->size;
    }
    void Append(T item) {
        Node<T> *newNode = new Node<T>;
        newNode->item = item;
        newNode->next = NULL;
        if (size == 0) {
            first = newNode;
        } else {
            last->next = newNode;
        }
        last = newNode;
        size++;
    }


    void Prepend(T item){
        auto *node = (Node<T> *)malloc(sizeof(Node<T>));
        node->item = item;
        node->next = this->first;
        this->first = node;
        this->size++;
    }
    void InsertAt(T item, int index){
        Node<T> *prev=NULL;
        Node<T> *tmp;
        int count = 0;
        if(index < 0 || index >= this->size){
            throw std::out_of_range("Incorrect index.");
        }else{
            tmp = this->first;
            while(count != index){
                if(count == index - 1){
                    prev = tmp;
                }
                tmp = tmp->next;
                count++;
            }
            auto *node = (Node<T> *)malloc(sizeof(Node<T>));
            node->item = item;
            prev->next = node;
            node->next = tmp;
            this->size++;
        }
    }
    LinkedList<T>* Concat(LinkedList<T> *list){
        LinkedList<T> *newList = new LinkedList<T>();
        newList->size = (this->size) + (list->size);
        newList->first = this->first;
        this->last->next = list->first;
        newList->last = list->last;
        return newList;
    }
    
};

#endif /* linkedlist_hpp */
