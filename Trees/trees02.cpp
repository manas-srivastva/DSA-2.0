#include<iostream>
using namespace std;
class Node{
    public:
    int data;
    Node *left,*right;
    Node(int value){
        left=right=NULL;
        data =value;
    }
};

void preOrder(Node *root){
    if(root==NULL)
    return;

    // Node
    cout<<root->data<<" ";
    // left
    preOrder(root->left);
    //right
    preOrder(root->right);
}


void InOrder(Node *root){
    if(root==NULL)
    return;

   
    // left
    InOrder(root->left);
    
     // Node
    cout<<root->data<<" ";
    //right
    InOrder(root->right);
}

void PostOrder(Node *root){
    if(root==NULL)
    return;
    // left
    PostOrder(root->left);
    //right
    PostOrder(root->right);
    // Node
    cout<<root->data<<" ";
}

Node *BinaryTree(){
    int x;
    cin>>x;
    if(x==-1)
    return NULL;

    Node *temp=new Node(x);
    // left side
    cout<<"Enter the left child of "<<x<<" ";
    temp->left=BinaryTree();
    // right side
     cout<<"Enter the right child of "<<x<<" ";
    temp->right=BinaryTree();

    return temp;
}
int main(){
cout<<"Enter the root Node: ";
Node *root;
root=BinaryTree();
// tree creation code

// preorder print
cout<<"PreOrder : ";
preOrder(root);

// Inorder
cout<<"\nInorder : ";
InOrder(root);

// Postorder
cout<<"\nPostorder : ";
PostOrder(root);
return 0;
}


//        1
//    2        7
//   3  6        8
//  4  5       9    10