#include <iostream>
#include <algorithm>
#include <ctime>
#include <stdlib.h>
#include <cstring>
#include <vector>
#include "sort.h"
using namespace std;

int N=100000;
int *TA;
int *TB;

int main()
{
    int v;
    int* A=new int[N];
    TA=new int[N];
    TB=new int[N];
    vector<Sort<int>*> Ast;
    Ast.push_back(new bubble<int>());
    Ast.push_back(new selection<int>());
    Ast.push_back(new insertion<int>());
    Ast.push_back(new Merge<int>());
    for(int n=100;n<N;n*=10){
        for(int i=0;i<n;i++){
            A[i]=rand()%n;
        }
        cout<<n<<" ";
        for(int s=0;s<4;s++){
            memcpy(TB,A,sizeof(int)*n);
            memcpy(TA,A,sizeof(int)*n);
            clock_t t=clock();
            Ast[s]->sort_(TA,n);
            float time=float(clock()-t)/CLOCKS_PER_SEC;
            std::sort(TB,TB+n);
            for(int i=0;i<n;i++){
                if(TA[i]!=TB[i]){
                    v=0;
                }
            }
            cout<<time<<" ";
            if(v==0)
            {
                cout<<"Fail"<<endl;
                return 0;
            }
            }
            cout<<endl;
    }
    delete[]A;
    delete[]TA;
    delete[]TB;
    return 0;
}
