#include <iostream>

using namespace std;

template <class T>
void bubble<T> :: sort_(T * &A, int n)
{
    int aux;
    while(n>1){
    for(int i=0;i<n-1;i++){
        if(A[i]>A[i+1])
        {
            aux=A[i+1];
            A[i+1]=A[i];
            A[i]=aux;
        }
    }
    n--;
    }
}
template<class T>
void selection<T> :: sort_(T * &A, int n)
{
    int aux;
    int m;
    for(int j=0;j<n-1;j++){
        m=j;
        for(int i=j+1;i<n;i++){
            if(A[i]<A[m]){
                m=i;
            }
        }
        aux=A[j];
        A[j]=A[m];
        A[m]=aux;
    }
}



template<class T>
void insertion<T> :: sort_(T * &A, int  n)
{
    int ext;
    int j=1;
    int aux;
    while(j<n){
        ext=A[j];
        for(int i=j-1;i>=0;i--){
            if(A[i]>ext){
                A[i+1]=A[i];
            }
            else{
                A[i+1]=ext;
                i=-1;
            }
            aux=i;
        }
        if(aux==0){
            A[0]=ext;
        }
        j++;
    }
}
template<class T>
void Merge<T> :: merge(T *&A,int i,int m,int j)
{
    int r=i;int t=m+1; int x=0; int aux[j+1-i];
    while(r<=m && t<=j){
        if(A[r]<=A[t]){
            aux[x++]=A[r++];
        }
        else{
            aux[x++]=A[t++];
        }
    }
    while(r<=m){aux[x++]=A[r++];}
    while(t<=j){aux[x++]=A[t++];}
    for(int in=0;in<j-i+1;in++){
        A[in+i]=aux[in];
    }

}

template <class T>
void Merge<T>:: sort_(T * &A, int  n)
{
    merge_sort(A,0,n-1);
}

template<class T>
void Merge<T>:: merge_sort(T * &A,int i,int j)
{
    if(i==j)return;
    int m=(i+j)/2;
    merge_sort(A,i,m);
    merge_sort(A,m+1,j);
    merge(A,i,m,j);
}
