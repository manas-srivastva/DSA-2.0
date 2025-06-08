#include<iostream>
using namespace std;
class NODE{
    public:
    int data;
    NODE *next;
    NODE(int value){
        data=value;
        next=NULL;
    }
};
int main(){
NODE *head,*tail;
head=NULL;
tail=NULL;
 int arr[]={2,4,6,8,10};
  // insert value at end
   // linked list is empty
   for(int i=0;i<5;i++){
    if(head==NULL){
        head=new NODE(arr[i]);
        tail=head;
    }
    else
    {
        tail->next=new NODE(arr[i]);
        tail=tail->next;
    }
   }
   NODE *temp=head;
     while(temp!=NULL)
{
 cout<<temp->data<<" ";
  temp=temp->next;
}
// time complexity=o(n)
// space complexity = o(1)
return 0;
}