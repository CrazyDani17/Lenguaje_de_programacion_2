#ifndef PICT_H
#define PICT_H
#include<iostream>
#include<vector>
using namespace std;

class pict{
private:
    string name;
    string file;
public:
    //vector <string> tags;
    //string * tags;
    pict(){
        name="";
        file="";
    }
    pict(const char* name_, const char* file_){
        name=name_;
        file=file_;
    }
    /*pict(const char* name_, const char* file_, vector<string>& tags_){
        name=name_;
        file=file_;
        for(size_t i=0;i<tags_.size();i++){
            tags[i]=tags_[i];
        }
    }*/
    /*pict(const pict & p){
        name=p.name;
        file=p.file;
        for(size_t i=0;i<(p.tags).size();i++){
            tags[i]=p.tags[i];
        }
    }*/
    /*void operator = (const pict &p){
        name=p.name;
        file=p.file;
        tags.clear();
        for(size_t i=0;i<p.tags.size();i++){
            tags.push_back(p.tags[i]);
        }
    }*/

    void add_name(string st){
        name=st;
    }
    void add_file(string st){
        file=st;
    }
    string show_name(){
        return name;
    }
    string show_file(){
        return file;
    }
    /*vector<string> show_tags(){
        return tags;
    }*/
    /*void add_tag(string a){
        tags.push_back(a);
    }*/
    /*void add_tag(string a){
        string*aux;
        for(size_t i=0; tags[i]!=nullptr; i++){

        }
        delete this->tags;

    }*/
    string show_all(){
        string text= "File: " + file + "<p>Name: " + name + "</p>" + "Tags: ";
        /*for(size_t i=0;i<tags.size();i++){
            text= text+"<p>"+tags[i]+"</p>";
        }*/
        return text;
    }

};
#endif // PICT_H
