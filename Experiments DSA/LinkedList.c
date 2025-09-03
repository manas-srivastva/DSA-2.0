#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to store student data
struct Student {
    char usn[20], name[50], branch[20], phno[15];
    int sem;
    struct Student *next;
};

typedef struct Student* NODE;
NODE head = NULL;  // Global head pointer for the SLL

// Function to create a new node
NODE createNode() {
    NODE temp = (NODE)malloc(sizeof(struct Student));
    if (!temp) {
        printf("Memory allocation failed!\n");
        exit(0);
    }
    printf("\nEnter Student Details:\n");
    printf("USN: "); 
    scanf("%s", temp->usn);
    printf("Name: "); 
    scanf("%s", temp->name);
    printf("Branch: "); 
    scanf("%s", temp->branch);
    printf("Semester: "); 
    scanf("%d", &temp->sem);
    printf("Phone No: "); 
    scanf("%s", temp->phno);
    temp->next = NULL;
    return temp;
}

// Function to insert at front
void insertFront() {
    NODE newNode = createNode();
    newNode->next = head;
    head = newNode;
}

// Function to insert at end
void insertEnd() {
    NODE newNode = createNode();
    if (head == NULL) {
        head = newNode;
        return;
    }
    NODE temp = head;
    while (temp->next != NULL)
        temp = temp->next;
    temp->next = newNode;
}

// Function to delete at front
void deleteFront() {
    if (head == NULL) {
        printf("List is empty!\n");
        return;
    }
    NODE temp = head;
    printf("Deleted Student: %s\n", temp->usn);
    head = head->next;
    free(temp);
}

// Function to delete at end
void deleteEnd() {
    if (head == NULL) {
        printf("List is empty!\n");
        return;
    }
    NODE temp = head, prev = NULL;
    if (head->next == NULL) {
        printf("Deleted Student: %s\n", head->usn);
        free(head);
        head = NULL;
        return;
    }
    while (temp->next != NULL) {
        prev = temp;
        temp = temp->next;
    }
    printf("Deleted Student: %s\n", temp->usn);
    prev->next = NULL;
    free(temp);
}

// Function to display the list
void display() {
    if (head == NULL) {
        printf("List is empty!\n");
        return;
    }
    NODE temp = head;
    int count = 0;
    printf("\nStudent List:\n");
    while (temp != NULL) {
        printf("USN: %s | Name: %s | Branch: %s | Sem: %d | Phone: %s\n",
               temp->usn, temp->name, temp->branch, temp->sem, temp->phno);
        temp = temp->next;
        count++;
    }
    printf("Total Students = %d\n", count);
}

// Main menu
int main() {
    int choice, n, i;
    while (1) {
        printf("\n--- Singly Linked List Menu ---\n");
        printf("1. Create SLL of N students (Front Insertion)\n");
        printf("2. Display SLL and Count Nodes\n");
        printf("3. Insert at End\n");
        printf("4. Delete at End\n");
        printf("5. Insert at Front (Stack Demonstration)\n");
        printf("6. Delete at Front (Stack Demonstration)\n");
        printf("7. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter number of students: ");
                scanf("%d", &n);
                for (i = 0; i < n; i++)
                    insertFront();
                break;
            case 2:
                display();
                break;
            case 3:
                insertEnd();
                break;
            case 4:
                deleteEnd();
                break;
            case 5:
                insertFront();
                break;
            case 6:
                deleteFront();
                break;
            case 7:
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    }
    return 0;
}
