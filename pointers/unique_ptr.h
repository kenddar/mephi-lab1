

#ifndef LAB1SEM3_UNIQUE_PTR_H
#define LAB1SEM3_UNIQUE_PTR_H


template<typename T>
class UniquePtr{
private:
    T* ptr;

    T* release(){
        T* temp = ptr;
        ptr = nullptr;
        return temp;
    }




public:
    UniquePtr() : ptr(nullptr) {}

    explicit UniquePtr(T* ptr) : ptr(ptr) {}

    ~UniquePtr() {
        delete ptr;
    }

    UniquePtr(const UniquePtr&) = delete;
    UniquePtr& operator=(const UniquePtr&)=delete;

    UniquePtr(UniquePtr&& other) noexcept : ptr(other.ptr){
        other.ptr = nullptr;
    }

    UniquePtr& operator=(UniquePtr&& other) noexcept{
        if(this != &other){
            delete ptr;
            ptr = other.ptr;
            other.ptr = nullptr;
        }
        return *this;
    }

    T& operator*() const{
        return *ptr;
    }

    T* operator->() const{
        return ptr;
    }

    void reset(T* newPtr = nullptr){
        delete ptr;
        ptr = newPtr;
    }

    T* get() const{
        return ptr;
    }
};

#endif //LAB1SEM3_UNIQUE_PTR_H
