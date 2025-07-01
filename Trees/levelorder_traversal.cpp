#include<iostream>
#include<queue>
#include<vector>
using namespace std;class Node{
    public:
    int data;
    Node* left,*right;

    Node(int value){
        data=value;
        left=right=NULL;
    }
};
vector<int>LevelOrder(Node* root)
{
    queue<Node*>q;
    q.push(root);
    vector<int>ans;
    Node *temp;
    while(!q.empty()){
        temp=q.front();
        q.pop();
        ans.push_back(temp->data);
        if(temp->left)
        q.push(temp->left);

        if(temp->right)
        q.push(temp->right);
    }
return ans;
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

    // Get the level order traversal
    vector<int> result = LevelOrder(root);

    // Print the result
    cout << "Level Order Traversal: ";
    for (int val : result) {
        cout << val << " ";
    }
    cout << endl;
return 0;
}