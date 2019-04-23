#ifndef MATRIX_H
#define MATRIX_H
#include <iostream>

using namespace std;

template <class T>
class matrix{
    private:
        T** M;
        size_t n_rows;
        size_t n_colums;
    public:
        //matrix(const T** dat);
        matrix(size_t nr=0, size_t nc=0);
        matrix(const matrix<T> & dat);
        ~matrix();
        T & operator()(size_t i, size_t j);
        matrix<T> operator + (const matrix<T> & dat);
        //matrix<T> operator + (const T ** dat);
        matrix<T> operator * (const matrix<T> & dat);
        matrix<T> operator << (T&v);
        friend ostream & operator << (ostream & os,const matrix<T> & dat);
};
#include "matrix.inl"
#endif