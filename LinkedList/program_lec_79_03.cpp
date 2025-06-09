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
  // delete from a particular node
  int X=3;
  if(X==1)
  {
    Node*temp=Head;
    Head=Head->next;
    delete temp;
  }
  X--;
  Node *curr=Head;
  Node *prev=NULL;
  while(X--){
    prev=curr;
    curr=curr->next;
  }
  prev->next=curr->next;
  delete curr;
  Node *temp=Head;
 

  while(temp!=NULL)
{
 cout<<temp->data<<" ";
  temp=temp->next;
}
   

return 0;
}