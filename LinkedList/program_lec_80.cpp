#include<iostream>
#include<vector>
using namespace std;
class Listnode
{
    public:
    int val;
    Listnode *next;
    Listnode(int data)
    {
        val=data;
        next=NULL;
    }
};
Listnode *createLinkedList (int arr[],int index,int size,Listnode*prev)
{
    // base case
    if(index== size)
    {
        return prev;
    }
    Listnode *temp;
    temp=new Listnode(arr[index]);
    temp->next=prev;
   return createLinkedList(arr,index+1,size,temp);
}
int main(){
Listnode  *Head;
  Head =NULL;

  int arr[]={2,4,6,8,10};
  Head=createLinkedList(arr,0,5,Head);

 vector<int>ans;
 Listnode *temp=Head;
 while(temp!=NULL)
 {
    ans.push_back(temp->val);
    temp=temp->next;
 }
 int i=ans.size()-1;
 temp =Head;
 while(temp!=NULL)
 {
    temp->val=ans[i];
    i--;
    temp=temp->next;
 }
Listnode*temp1=Head;
 

  while(temp1!=NULL)
{
 cout<<temp1->val<<" ";
  temp1=temp1->next;
}
   
return 0;
}