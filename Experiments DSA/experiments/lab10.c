#include <stdio.h>
#include <stdlib.h>

#define MAX 5   // Maximum size of the Circular Queue

// Global variables for front and rear
int front = -1, rear = -1;
char queue[MAX]; // Array to store the queue elements

// Function to check if the queue is full
int isFull() {
    return ((rear + 1) % MAX == front);
}

// Function to check if the queue is empty
int isEmpty() {
    return (front == -1);
}

// Function to insert an element into the circular queue
void insert() {
    char item;
    if (isFull()) {
        printf("\nQueue Overflow! Cannot insert.\n");
        return;
    }
    printf("Enter the character to insert: ");
    scanf(" %c", &item);

    // If inserting first element
    if (front == -1)
        front = 0;

    // Move rear in circular manner
    rear = (rear + 1) % MAX;
    queue[rear] = item;

    printf("Inserted '%c' into the queue.\n", item);
}

// Function to delete an element from the circular queue
void delete() {
    if (isEmpty()) {
        printf("\nQueue Underflow! Cannot delete.\n");
        return;
    }

    char item = queue[front];

    // If only one element left
    if (front == rear) {
        front = -1;
        rear = -1;
    } else {
        front = (front + 1) % MAX;
    }

    printf("Deleted '%c' from the queue.\n", item);
}

// Function to display the circular queue
void display() {
    if (isEmpty()) {
        printf("\nQueue is empty.\n");
        return;
    }

    printf("\nCircular Queue elements: ");
    int i = front;
    while (1) {
        printf("%c ", queue[i]);
        if (i == rear)
            break;
        i = (i + 1) % MAX;
    }
    printf("\n");
}

// Main function (Menu-driven)
int main() {
    int choice;

    printf("=== Circular Queue (Array Implementation) ===\n");

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
