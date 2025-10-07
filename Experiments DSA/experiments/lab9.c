#include <stdio.h>
#include <stdlib.h>

// Define structure for a stack node
struct Node {
    int data;
    struct Node *next;
};

struct Node *top = NULL; // Global pointer to the top of the stack

// Function to push an element onto the stack
void push(int value) {
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Stack Overflow! Memory not available.\n");
        return;
    }
    newNode->data = value;
    newNode->next = top;
    top = newNode;
    printf("✅ %d pushed onto stack.\n", value);
}

// Function to pop an element from the stack
void pop() {
    if (top == NULL) {
        printf("⚠️ Stack Underflow! No elements to pop.\n");
        return;
    }
    struct Node *temp = top;
    int popped = temp->data;
    top = top->next;
    free(temp);
    printf("🗑️ %d popped from stack.\n", popped);
}

// Function to display the stack
void display() {
    if (top == NULL) {
        printf("⚠️ Stack is empty.\n");
        return;
    }
    struct Node *temp = top;
    printf("📦 Stack elements (top to bottom): ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// Function to check if stack is empty
int isEmpty() {
    return (top == NULL);
}

// Function to display the top element
void peek() {
    if (top == NULL) {
        printf("⚠️ Stack is empty.\n");
        return;
    }
    printf("🔝 Top element is: %d\n", top->data);
}

// Main function with menu
int main() {
    int choice, value;

    while (1) {
        printf("\n===== Dynamic Stack Menu =====\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Peek (Top Element)\n");
        printf("4. Display Stack\n");
        printf("5. Check if Stack is Empty\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to push: ");
                scanf("%d", &value);
                push(value);
                break;

            case 2:
                pop();
                break;

            case 3:
                peek();
                break;

            case 4:
                display();
                break;

            case 5:
                if (isEmpty())
                    printf("✅ Stack is empty.\n");
                else
                    printf("❌ Stack is NOT empty.\n");
                break;

            case 6:
                printf("👋 Exiting program...\n");
                // Free remaining nodes
                while (!isEmpty()) {
                    pop();
                }
                exit(0);

            default:
                printf("⚠️ Invalid choice! Please try again.\n");
        }
    }
    return 0;
}
