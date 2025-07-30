#include<iostream>
using namespace std;

class Node {
public:
    int data;
    Node *left, *right;

    Node(int value) {
        data = value;
        left = right = NULL;    
    }
};

// Function to build the binary tree recursively
Node* BinaryTree() {
    int x;
    cin >> x;
    if (x == -1)
        return NULL;

    Node* temp = new Node(x);
    temp->left = BinaryTree();
    temp->right = BinaryTree();
    return temp;
}

// Function to count total nodes in the tree
int TotalNode(Node* root) {
    if (root == NULL)
        return 0;

    return (1 + TotalNode(root->left) + TotalNode(root->right));
}

int main() {
    cout << "Enter tree nodes in pre-order (-1 for NULL):\n";
    Node* root = BinaryTree();

    int total = TotalNode(root);
    cout << "\nTotal number of nodes in the binary tree: " << total << endl;

    return 0;
}
