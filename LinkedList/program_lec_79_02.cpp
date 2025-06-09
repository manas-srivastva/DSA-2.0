#include<iostream>
using namespace std;

class Node
{
    public:
    int data;
    Node *next;
    Node(int value)
    {
        data =value;
        next =NULL;
    }
};
Node *createLinkedList(int arr[],int index,int size)
{
    if(index==size)
    return NULL;
    Node *temp;
    temp=new Node(arr[index]);
    temp->next=createLinkedList(arr,index+1,size);
    return temp;
}
int main(){
   Node *Head;
  Head=NULL;
 

  int arr[]={2,4,6,8,10};
  Head=createLinkedList(arr,0,5);
  // delete a node at last
  if(Head!=NULL){
    // only one node is present
    if(Head->next==NULL){
        Node*temp=Head;
        delete temp;
        Head=NULL;
    }
    // more than 1 node present
    else
    {
        Node *curr=Head;
        Node *prev=NULL;
        while(curr->next!=NULL){
            prev=curr;
            curr=curr->next;

        }
        prev->next=curr->next;
        delete curr;
    }
  }
    Node *temp=Head;
 

  while(temp!=NULL)
{
 cout<<temp->data<<" ";
  temp=temp->next;
}
return 0;
}