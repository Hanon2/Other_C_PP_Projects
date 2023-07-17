#ifndef DOUBLY
#define DOUBLY
#include <iostream>
using namespace std;

struct node{
    
    int data;
    node * next; 
    node * prev;
};
class doublylinkedlist{
    public: 
    doublylinkedlist(){
        head = nullptr; 
        tail = nullptr; 
    }
    doublylinkedlist(const doublylinkedlist& rhs);
    void operator=(const doublylinkedlist& rhs);
    ~doublylinkedlist();
    void push(int data); 
    void pop();
    int size() const;
    void print();
    int& at (int idx) const; 
    void insert (int data, int pos);
    void remove(int pos); 
    
    
    
    private:
    node* head; 
    node*tail;
};
#endif