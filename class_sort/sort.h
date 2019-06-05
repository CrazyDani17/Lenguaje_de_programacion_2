#ifndef SORT_H
#define SORT_H
#include <iostream>

template<class T>
class Sort{
private:

public:
    virtual void sort_(T * &A, int n)=0;
    virtual ~Sort(){}
};

template<class T>
class bubble:public Sort<T>{
private:
public:
    void sort_(T *& A, int n);
    ~bubble(){
    }
};

template<class T>
class selection:public Sort<T>{
private:
public:
    void sort_(T * &A, int n);
    ~selection(){
    }
};

template<class T>
class insertion:public Sort<T>{
private:
public:
    void sort_(T * &A, int n);
    ~insertion(){
    }
};

template<class T>
class Merge:public Sort<T>{
private:

public:
    void sort_(T * &A, int n);
    void merge_sort(T * &A,int i,int j);
    void merge(T *&A,int i,int m,int j);
    ~Merge(){
    }
};

#include "sort.inl"
#endif
