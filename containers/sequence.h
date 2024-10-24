#ifndef LAB1SEM3_SEQUENCE_H
#define LAB1SEM3_SEQUENCE_H


template<class T>
class Sequence{
public:
    virtual T GetFirst()=0;
    virtual T GetLast()=0;
    virtual T Get(int index)=0;
    virtual int GetLength()=0;
    virtual void Append(T item)=0;
    virtual void InsertAt(T item, int index)=0;
    virtual void Print()=0;
};

#endif //LAB1SEM3_SEQUENCE_H
