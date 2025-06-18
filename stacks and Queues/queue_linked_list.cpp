#include<iostream>
using namespace std;
class Node{
    public:
    int data;
    Node *next;
    Node(int value){
        data=value;
        next=NULL;
    }
};
class Queue{
    Node *front;
    Node *rear;
    public:
    Queue(){
        front=rear=NULL;
    }
    bool IsEmpty(){
        return front==NULL;
    }
    void push(int x){
        if(IsEmpty()){
            front=new Node(x);
            rear=front;
            return;
        }
        else{
            rear->next=new Node(x);
            rear=rear->next;
        }

    }
    void pop(){
        if(IsEmpty()){
            cout<<"Queue Underflow\n";
            return;
        }
        else{
            Node *temp=front;
            front=front->next;
            delete temp;
        }
    }
    int start(){
        if(IsEmpty()){
            cout<<"Queue is empty\n";
            return -1;
        }
        else
        return front->data;
    }
};
int main(){
Queue q;
q.push(5);
q.push(10);
q.push(22);
q.pop();
cout<<q.start();
return 0;
}