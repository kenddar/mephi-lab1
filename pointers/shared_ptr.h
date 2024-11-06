

#ifndef LAB1SEM3_SHARED_PTR_H
#define LAB1SEM3_SHARED_PTR_H


template<typename T>
class SharedPtr{
private:
    T* ptr;
    int* ref_count;

    void release(){
        if(ref_count){
            --(*ref_count);
            if(*ref_count == 0){
                delete ptr;
                delete ref_count;
                ptr = nullptr;
                ref_count = nullptr;
            }
        }
    }

    T* get() const{
        return ptr;
    }

public:
    SharedPtr() : ptr(nullptr), ref_count(nullptr){}

    explicit SharedPtr(T* p) : ptr(p), ref_count(new int(1)) {}

    SharedPtr(const SharedPtr& other) : ptr(other.ptr), ref_count(other.ref_count){
        if(ref_count){
            ++(*ref_count);
        }
    }

    SharedPtr& operator=(const SharedPtr& other){
        if(this != &other){
            release();
            ptr = other.ptr;
            ref_count = other.ref_count;
            if(ref_count){
                ++(*ref_count);
            }
        }
        return *this;
    }

    ~SharedPtr(){
        release();
    }

    int num_count() const {
        if(ref_count){
            return *ref_count;
        }else{
            return 0;
        }
    }

    T& operator*() const {
        return *ptr;
    }

    T* operator->() const {
        return ptr;
    }



    void reset(T* p = nullptr){
        release();
        if(p){
            ptr = p;
            ref_count = new int(1);
        } else{
            ptr = nullptr;
            ref_count = nullptr;
        }
    }
};
#endif //LAB1SEM3_SHARED_PTR_H
