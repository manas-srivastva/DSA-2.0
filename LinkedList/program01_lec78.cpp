// inserting note without array knowledge

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
NODE *Head;
Head=NULL;
if(Head==NULL){
    Head=new NODE(28);
}
else
{
    NODE *temp;
    temp=new NODE(28);
    temp->next=Head;
    Head=temp;
}

NODE *temp=Head;
while(temp!=NULL){
    cout<<temp->data<<" ";
    temp=temp->next;
}
return 0;
}