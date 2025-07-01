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
int countleaft(Node *root){
    if(root==NULL)
    return 0;

    if(!root->left && !root->right)
    return 1;

    return (countleaft(root->left)+countleaft(root->right));
}
int main(){
int x;
cout<<"Enter the root element : ";
cin>>x;
int first,second;
queue<Node*>q;
Node *root=new Node(x);
q.push(root);

// Build the binary tree
while(!q.empty()){
    Node *temp=q.front();
    q.pop();
    cout<<"Enter the left child of "<<temp->data<<" : ";
    cin>>first;// left node ki value
    // left node
    if(first!=-1){
        temp->left=new Node(first);
        q.push(temp->left);
    }

    // right side
    cout<<"Enter the Right child of "<<temp->data<<" : ";
    cin>>second;
      if(second!=-1){
        temp->right=new Node(second);
        q.push(temp->right);
    }

}
cout<<countleaft(root)<<" ";
return 0;
}