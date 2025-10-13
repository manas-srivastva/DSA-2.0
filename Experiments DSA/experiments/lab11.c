#include <stdio.h>
#include <stdlib.h>

// Define a node structure for the queue
struct Node {
    char data;
    struct Node *next;
};

// Pointers to track front and rear of the queue
struct Node *front = NULL;
struct Node *rear = NULL;

// Function to check if the queue is empty
int isEmpty() {
    return (front == NULL);
}

// Function to insert (enqueue) an element into the queue
void insert() {
    char item;
    struct Node *newNode;

    newNode = (struct Node *)malloc(sizeof(struct Node));

    // Check for memory allocation failure (Overflow)
    if (newNode == NULL) {
        printf("\nQueue Overflow! Memory not available.\n");
        return;
    }

    printf("Enter the character to insert: ");
    scanf(" %c", &item);

    newNode->data = item;
    newNode->next = NULL;

    // If queue is empty
    if (front == NULL) {
        front = rear = newNode;
    } else {
        rear->next = newNode;
        rear = newNode;
    }

    printf("Inserted '%c' into the queue.\n", item);
}

// Function to delete (dequeue) an element from the queue
void delete() {
    if (isEmpty()) {
        printf("\nQueue Underflow! Cannot delete.\n");
        return;
    }

    struct Node *temp = front;
    char item = temp->data;

    // Move front to next node
    front = front->next;

    // If queue becomes empty, set rear to NULL
    if (front == NULL)
        rear = NULL;

    free(temp);
    printf("Deleted '%c' from the queue.\n", item);
}

// Function to display the queue
void display() {
    if (isEmpty()) {
        printf("\nQueue is empty.\n");
        return;
    }

    struct Node *temp = front;
    printf("\nQueue elements: ");
    while (temp != NULL) {
        printf("%c ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// Main function (Menu-driven)
int main() {
    int choice;

    printf("=== Dynamic Queue (Linked List Implementation) ===\n");

    while (1) {
        printf("\nMenu:\n");
        printf("1. Insert an Element\n");
        printf("2. Delete an Element\n");
        printf("3. Display Queue\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                insert();
                break;
            case 2:
                delete();
                break;
            case 3:
                display();
                break;
            case 4:
                printf("Exiting program.\n");
                exit(0);
            default:
                printf("Invalid choice! Try again.\n");
        }
    }

    return 0;
}
