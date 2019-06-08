#include <iostream>
#include <vector>

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
};

void save_array(vector<A> &vt,const char * file)
{
    FILE *of;
    if((of=fopen(file,"ab"))==NULL){
        cout<<"no existe"<<endl;
    }
    else{
    for(int i=0;i<vt.size();i++){
        fwrite(&vt[i],sizeof(vt[i]),1,of);
    }
    fclose(of);
    }
}

void load_array(vector <A> &vt, const char* file)
{
    FILE *ifs;
    A s;
    if((ifs=fopen(file,"rb"))==NULL){
        cout<<"no existe"<<endl;
    }
    else{
    fread(&s,sizeof(s),1,ifs);
    while(! feof(ifs)){
        vt.push_back(s);
        fread(&s,sizeof(s),1,ifs);
    }
    }
    fclose(ifs);
}
int main()
{
    A a;
    vector <A> va;
    while(cin>>a)
        va.push_back(a);
    save_array(va,"out.dat");
    vector <A> va2;
    load_array(va2,"out.dat");
    for(int i=0; i<va.size(); i++){
        cout<<va[i]<<endl;
    }
    return 0;
}
