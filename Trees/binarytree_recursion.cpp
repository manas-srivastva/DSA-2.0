#include<iostream>
#include<queue>
using namespace std;
class Node{
    public:
    int data;
    Node* left,*right;

    Node(int value){
        data=value;
        left=right=NULL;
    }
};

Node *BinaryTree(){
    int x;
    cin>>x;
    if(x==-1)
    return NULL;
    Node *temp=new Node(x);
    // left side
    temp->left=BinaryTree();
    // right side
    temp->right=BinaryTree();


    return temp;
}
int main(){
BinaryTree();
return 0;
}