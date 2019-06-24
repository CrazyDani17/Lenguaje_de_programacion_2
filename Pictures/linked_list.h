#ifndef LINKED_LIST_H
#define LINKED_LIST_H
#include <iostream>

using namespace std;
template<class T>
class linked_list{
    struct node{
        T dato;
        node* p_next;
        node(const T & d, node*p_next_=nullptr){
            dato=d;
            p_next=p_next_;
        }
        void setNext(node *nd) {
            this->p_next = nd;
        }

    };
private:
    node*p_head;
public:
    linked_list():p_head(nullptr){}

    class iterator{
    private:
        node * n;
    public:
        iterator(node * n_=nullptr)
        {
            n=n_;
        }
        T& operator *()
        {
            return n->dato;
        }
        bool operator !=(const iterator & it){
            return n!=it.n;
        }
        iterator & operator ++()
        {
            n=n->p_next;
            return *this;
        }
        /*iterator & operator --()
        {
            return *this;
        }*/
        ~iterator () = default;
    };

    iterator begin()
    {
        return iterator(p_head);
    }

    iterator end()
    {
        return iterator(nullptr);
    }

    void push_front(const T & d){
        p_head=new node (d,p_head);
    }

    void push_back(const T & d) {
        node *nd = new node(d);

        if(p_head == nullptr) {
            p_head = nd;
            return;
        }

        node *curr = p_head;

        while(curr && curr->p_next) {
            curr = curr->p_next;
        }
        curr->setNext(nd);
    }


    void remove_front(){
        if(!p_head) return;
        node* del=p_head;
        p_head=p_head->p_next;
        delete del;
    }
    ~linked_list()
    {
        while(p_head) remove_front();
    }

};

#endif // LINKED_LIST_H
