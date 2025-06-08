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
Node *createLinkedList(int arr[],int index,int size){
    // base case
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
 Head= createLinkedList(arr,0,5);// 2 ka address
 Node *temp=Head;
 

  while(temp!=NULL)
{
 cout<<temp->data<<" ";
  temp=temp->next;
}
   // time complexity O(N)
   // space  complexity O(N) // as we are using a stack


return 0;
}