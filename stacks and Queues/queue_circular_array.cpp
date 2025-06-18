#include<iostream>
using namespace std;
class Queue{
    int *arr;
    int front,rear,size;
    public:
    // constructor
    Queue(int n){
        arr=new int[n];
        size=n;
        front=rear=-1;
    }
    bool IsEmpty(){
        return front==-1;
    }
    bool IsFull(){
        return (rear+1)%size==front;
    }
    // push element into queue,end
    void push(int x){
        // empty
        if(IsEmpty()){
            front=rear=0;
            arr[0]=x;
        }
        //FULL
        if(IsFull()){
            cout<<"Queue Underflow\n";
            return;
        }
        // insert
        else{
            rear=(rear+1)%size;
            arr[rear]=x;
        }
    }
    // pop element,starting
    void pop(){
        // empty
        if(IsEmpty()){
            cout<<"Queue Underflow\n";
            return;
        }
        // pop kar do
        else{
            if(front==rear)
            front=rear=-1;
            else{
                front=(front+1)%size;
            }
        }
    
    }
    int start(){
        if(IsEmpty()){
            cout<<"Queue is empty\n";
            return -1;
        }
        else
        return arr[front];
    }
};
int main(){
Queue q(5);
q.push(5);
q.push(10);
q.push(22);
q.pop();
cout<<q.start();
return 0;
}