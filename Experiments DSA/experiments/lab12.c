#include <stdio.h>
#include <stdlib.h>

// Define structure for each node in the BST
struct Node {
    int data;
    struct Node *left, *right;
};

// Function to create a new node
struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Function to insert a node into the BST
struct Node* insert(struct Node* root, int value) {
    if (root == NULL)
        return createNode(value);  // Create new node if tree is empty

    if (value < root->data)
        root->left = insert(root->left, value);   // Insert in left subtree
    else if (value > root->data)
        root->right = insert(root->right, value); // Insert in right subtree
    // Duplicate values are ignored
    return root;
}

// Function for Inorder Traversal (Left, Root, Right)
void inorder(struct Node* root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

// Function for Preorder Traversal (Root, Left, Right)
void preorder(struct Node* root) {
    if (root != NULL) {
        printf("%d ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

// Function for Postorder Traversal (Left, Right, Root)
void postorder(struct Node* root) {
    if (root != NULL) {
        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->data);
    }
}

// Function to search for an element in the BST
void search(struct Node* root, int key) {
    if (root == NULL) {
        printf("Element %d not found in the BST.\n", key);
        return;
    }

    if (key == root->data) {
        printf("Element %d found in the BST!\n", key);
        return;
    } else if (key < root->data) {
        search(root->left, key);
    } else {
        search(root->right, key);
    }
}

// Function to create BST with given elements
struct Node* createInitialBST() {
    int elements[] = {6, 9, 5, 2, 8, 15, 24, 14, 7, 8, 5, 2};
    int n = sizeof(elements) / sizeof(elements[0]);

    struct Node* root = NULL;
    for (int i = 0; i < n; i++) {
        root = insert(root, elements[i]);
    }

    printf("BST created successfully with given elements.\n");
    return root;
}

// Main function
int main() {
    struct Node* root = NULL;
    int choice, key;

    printf("=== Binary Search Tree Operations ===\n");

    while (1) {
        printf("\nMenu:\n");
        printf("1. Create BST with given elements\n");
        printf("2. Inorder Traversal\n");
        printf("3. Preorder Traversal\n");
        printf("4. Postorder Traversal\n");
        printf("5. Search for an element\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                root = createInitialBST();
                break;
            case 2:
                if (root == NULL)
                    printf("BST is empty. Please create it first.\n");
                else {
                    printf("Inorder Traversal: ");
                    inorder(root);
                    printf("\n");
                }
                break;
            case 3:
                if (root == NULL)
                    printf("BST is empty. Please create it first.\n");
                else {
                    printf("Preorder Traversal: ");
                    preorder(root);
                    printf("\n");
                }
                break;
            case 4:
                if (root == NULL)
                    printf("BST is empty. Please create it first.\n");
                else {
                    printf("Postorder Traversal: ");
                    postorder(root);
                    printf("\n");
                }
                break;
            case 5:
                if (root == NULL)
                    printf("BST is empty. Please create it first.\n");
                else {
                    printf("Enter element to search: ");
                    scanf("%d", &key);
                    search(root, key);
                }
                break;
            case 6:
                printf("Exiting program.\n");
                exit(0);
            default:
                printf("Invalid choice! Try again.\n");
        }
    }

    return 0;
}
