#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to store student data
typedef struct Student {
    char usn[20];
    char name[30];
    char branch[20];
    int sem;
    char phno[15];
    struct Student *next;
} Student;

Student *head = NULL; // Head pointer of linked list

// Function to create a new student node
Student* createNode() {
    Student *newNode = (Student*)malloc(sizeof(Student));
    if (!newNode) {
        printf("Memory allocation failed!\n");
        exit(0);
    }

    printf("Enter USN: ");
    scanf("%s", newNode->usn);
    printf("Enter Name: ");
    scanf("%s", newNode->name);
    printf("Enter Branch: ");
    scanf("%s", newNode->branch);
    printf("Enter Semester: ");
    scanf("%d", &newNode->sem);
    printf("Enter Phone Number: ");
    scanf("%s", newNode->phno);

    newNode->next = NULL;
    return newNode;
}

// a. Create SLL of N Students using front insertion
void createSLL(int n) {
    for (int i = 0; i < n; i++) {
        printf("\nEnter details of student %d:\n", i + 1);
        Student *newNode = createNode();
        newNode->next = head;  // Insert at front
        head = newNode;
    }
}

// b. Display SLL and count nodes
void displaySLL() {
    Student *temp = head;
    int count = 0;

    if (head == NULL) {
        printf("\nSLL is empty!\n");
        return;
    }

    printf("\nStudent List:\n");
    printf("USN\tName\tBranch\tSem\tPhone\n");
    printf("-------------------------------------------\n");
    while (temp != NULL) {
        printf("%s\t%s\t%s\t%d\t%s\n", temp->usn, temp->name, temp->branch, temp->sem, temp->phno);
        temp = temp->next;
        count++;
    }
    printf("\nTotal number of nodes = %d\n", count);
}

// c. Insertion at End
void insertEnd() {
    Student *newNode = createNode();
    if (head == NULL) {
        head = newNode;
        return;
    }
    Student *temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}

// c. Deletion at End
void deleteEnd() {
    if (head == NULL) {
        printf("\nSLL is empty!\n");
        return;
    }
    if (head->next == NULL) { // Only one node
        printf("Deleted: %s\n", head->usn);
        free(head);
        head = NULL;
        return;
    }
    Student *temp = head;
    while (temp->next->next != NULL) {
        temp = temp->next;
    }
    printf("Deleted: %s\n", temp->next->usn);
    free(temp->next);
    temp->next = NULL;
}

// d. Insertion at Front (Stack push)
void insertFront() {
    Student *newNode = createNode();
    newNode->next = head;
    head = newNode;
}

// d. Deletion at Front (Stack pop)
void deleteFront() {
    if (head == NULL) {
        printf("\nSLL is empty!\n");
        return;
    }
    Student *temp = head;
    head = head->next;
    printf("Deleted: %s\n", temp->usn);
    free(temp);
}

// Menu-driven main function
int main() {
    int choice, n;

    while (1) {
        printf("\n--- Singly Linked List Operations ---\n");
        printf("1. Create SLL (Front Insertion)\n");
        printf("2. Display SLL and Count\n");
        printf("3. Insert at End\n");
        printf("4. Delete at End\n");
        printf("5. Insert at Front (Stack Push)\n");
        printf("6. Delete at Front (Stack Pop)\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("How many students to insert? ");
                scanf("%d", &n);
                createSLL(n);
                break;
            case 2:
                displaySLL();
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
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice! Try again.\n");
        }
    }
    return 0;
}
