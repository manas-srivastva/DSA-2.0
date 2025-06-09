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
Node* deleteNode(Node *curr,int x)
  {

  if(x==1) 
  {
    Node *temp=curr->next;
    delete curr;
    return temp;
  }
   curr->next = deleteNode(curr->next ,x-1);
   return curr;
  }


int main()
{
    Node *Head;
  Head=NULL;
 

  int arr[]={2,4,6,8,10};
  Head=createLinkedList(arr,0,5);
  // delete from a particular node  with recursion
  Node *Head1;
  Head1 =NULL;
  Head1=deleteNode(Head,2);
 
   Node *temp=Head;
 

  while(temp!=NULL)
{
 cout<<temp->data<<" ";
  temp=temp->next;
}
   

return 0;
}