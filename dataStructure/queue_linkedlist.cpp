#include <iostream>
#include "node.h"
using namespace std;

class queue{
    public:
        void push(int);
        void pop();
        bool isEmpty();
        void print();
        queue();
    private:
        node* tail;
        node* head;
};
queue::queue(){
    tail = head = NULL;
}
void queue::push(int v){
    if(isEmpty()){
        tail = head = new node(v);
        return;
    }
    node* tmp = new node(v);
    tail->next = tmp;
    tail = tmp;
}
void queue::pop(){
    if(isEmpty()){
        cout <<"there is empty~";
    }
    else if(head == tail){
        node* tmp = head; //!!
        head = tail = NULL;
        delete tmp;
    }else{
    node* tmp = head;
    head = head->next;
    delete tmp;
    tmp = NULL;
    }
}
bool queue::isEmpty(){
    return head == NULL and tail == NULL;
}
void queue::print(){
    if(isEmpty()){
        cout << "nothing can print";
        return;
    }
    node* ptr = head;
    while(head){
        cout << head->val <<" ";
        head = head->next;
    }
}
int main(){
    queue qu;
    qu.push(22);
    qu.pop();
    qu.push(6);
    qu.push(23);
    qu.print();
    return 0;
}