#ifndef PICT_H
#define PICT_H
#include<iostream>
#include<vector>
using namespace std;

class pict{
private:
    string name;
    string file;
    //vector <string> tags;
public:
    pict(){
        name="";
        file="";
    }
    pict(const char* name_, const char* file_){
        name=name_;
        file=file_;
    }
    //pict(const char* name_, const char* file_, vector<string>& tags_){
    //    name=name_;
    //    file=file_;
    //tags=tags_;
    //}
    pict(const pict & p){
        name=p.name;
        file=p.file;
        //tags=p.tags;
    }
    void operator = (const pict &p){
        name=p.name;
        file=p.file;
        //tags=p.tags;
    }
    string show_name(){
        return name;
    }
    string show_file(){
        return file;
    }
    //vector<string> show_tags(){
    //    return tags;
    //}
    //void add_tag(string a){
    //    tags.push_back(a);
    //}
    string show_all(){
        string text= "File: " + file + "<p>Name: " + name + "</p>" + "Tags: ";
        //for(size_t i=0;i<tags.size();i++){
        //    text= text+"<p>"+tags[i]+"</p>";
        //}
        return text;
    }
};
#endif // PICT_H
