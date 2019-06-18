#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

struct A
{
    int x;
    string str;
    friend ostream & operator <<(ostream & os, A &a){
        return os<<a.x<<a.str;
    }
    friend istream & operator >>(istream & is, A &a){
        return is>>a.x>>a.str;
    }
    char* serialize(A &a)
    {
        char* s=new char[(a.str).size()];
        for(int i=0; i<(a.str).size(); i++){
            s[i]=a.str[i];
        }
        return s;
    }
};

void save_array(vector<A> &vt,const char * file)
{
    ofstream of(file,ios::binary);
    size_t size_v;
    for(int i=0;i<vt.size();i++){
        size_v=vt[i].str.size();
        of.write((char*)&vt[i].x, sizeof(int));
        of.write((char*)&size_v,sizeof(size_t));
        of.write(vt[i].str.c_str(),size_v);
    }
    of.close();
}

void load_array(vector <A> &vt, const char* file)
{

    ifstream ifs(file,ios:: binary);
    A s;
    char * vt_b;
    size_t size_v;
    while(ifs.read((char*)&s.x, sizeof(int))){
        ifs.read((char*)&size_v,sizeof(size_t));
        vt_b=new char[size_v + 1];
        ifs.read(vt_b,size_v);
        vt_b[size_v]=0;
        s.str=vt_b;
        vt.push_back(s);
    }
    ifs.close();

}
int main()
{
    A a;
    vector <A> va;
    load_array(va,"out.bin");
    for(int i=0; i<va.size(); i++){
        cout<<va[i]<<endl;
    }
    int n;
    cin>>n;
    while(n!=0){
        cin>>a;
        va.push_back(a);
        n--;
    }
    save_array(va,"out.bin");
    for(int i=0; i<va.size(); i++){
        cout<<va[i]<<endl;
    }
    return 0;
}
