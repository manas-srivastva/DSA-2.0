#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure for Student
struct Student {
    char usn[15];
    char name[50];
    char branch[20];
    int sem;
    char phno[15];
    struct Student *next;
};

// Head pointer for SLL
struct Student *head = NULL;

// Function prototypes
void createSLL();
void displaySLL();
void insertAtEnd();
void deleteAtEnd();
void insertAtFront();
void deleteAtFront();
int countNodes();

// Function to create SLL using front insertion
void createSLL() {
    int n;
    printf("Enter number of students: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        struct Student *newNode = (struct Student*)malloc(sizeof(struct Student));
        if (!newNode) {
            printf("Memory allocation failed!\n");
            return;
        }

        printf("\nEnter details of student %d:\n", i + 1);
        printf("USN: "); scanf("%s", newNode->usn);
        printf("Name: "); scanf("%s", newNode->name);
        printf("Branch: "); scanf("%s", newNode->branch);
        printf("Semester: "); scanf("%d", &newNode->sem);
        printf("Phone No: "); scanf("%s", newNode->phno);

        newNode->next = head;
        head = newNode;
    }
    printf("SLL created successfully using front insertion!\n");
}

// Function to display SLL
void displaySLL() {
    if (head == NULL) {
        printf("Singly Linked List is empty!\n");
        return;
    }

    struct Student *temp = head;
    printf("\n--- Student List ---\n");
    while (temp != NULL) {
        printf("USN: %s, Name: %s, Branch: %s, Sem: %d, PhNo: %s\n",
               temp->usn, temp->name, temp->branch, temp->sem, temp->phno);
        temp = temp->next;
    }
}

// Function to count nodes
int countNodes() {
    int count = 0;
    struct Student *temp = head;
    while (temp != NULL) {
        count++;
        temp = temp->next;
    }
    return count;
}

// Function to insert at end
void insertAtEnd() {
    struct Student *newNode = (struct Student*)malloc(sizeof(struct Student));
    if (!newNode) {
        printf("Memory allocation failed!\n");
        return;
    }

    printf("\nEnter details of student to insert at end:\n");
    printf("USN: "); scanf("%s", newNode->usn);
    printf("Name: "); scanf("%s", newNode->name);
    printf("Branch: "); scanf("%s", newNode->branch);
    printf("Semester: "); scanf("%d", &newNode->sem);
    printf("Phone No: "); scanf("%s", newNode->phno);

    newNode->next = NULL;
    if (head == NULL) {
        head = newNode;
    } else {
        struct Student *temp = head;
        while (temp->next != NULL) temp = temp->next;
        temp->next = newNode;
    }
    printf("Student inserted at end successfully!\n");
}

// Function to delete at end
void deleteAtEnd() {
    if (head == NULL) {
        printf("List is empty. Nothing to delete!\n");
        return;
    }

    if (head->next == NULL) {
        free(head);
        head = NULL;
    } else {
        struct Student *temp = head;
        while (temp->next->next != NULL)
            temp = temp->next;
        free(temp->next);
        temp->next = NULL;
    }
    printf("Student deleted from end successfully!\n");
}

// Function to insert at front (Stack Push)
void insertAtFront() {
    struct Student *newNode = (struct Student*)malloc(sizeof(struct Student));
    if (!newNode) {
        printf("Memory allocation failed!\n");
        return;
    }

    printf("\nEnter details of student to insert at front:\n");
    printf("USN: "); scanf("%s", newNode->usn);
    printf("Name: "); scanf("%s", newNode->name);
    printf("Branch: "); scanf("%s", newNode->branch);
    printf("Semester: "); scanf("%d", &newNode->sem);
    printf("Phone No: "); scanf("%s", newNode->phno);

    newNode->next = head;
    head = newNode;
    printf("Student inserted at front successfully!\n");
}

// Function to delete at front (Stack Pop)
void deleteAtFront() {
    if (head == NULL) {
        printf("List is empty. Nothing to delete!\n");
        return;
    }

    struct Student *temp = head;
    head = head->next;
    free(temp);
    printf("Student deleted from front successfully!\n");
}

// Main function
int main() {
    int choice;

    while (1) {
        printf("\n--- Student SLL Menu ---\n");
        printf("1. Create SLL (Front Insertion)\n");
        printf("2. Display SLL and Count Nodes\n");
        printf("3. Insert at End\n");
        printf("4. Delete at End\n");
        printf("5. Insert at Front (Stack Push)\n");
        printf("6. Delete at Front (Stack Pop)\n");
        printf("7. Exit\n");
        printf("------------------------\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                createSLL();
                break;
            case 2:
                displaySLL();
                printf("Total Nodes: %d\n", countNodes());
                break;
            case 3:
                insertAtEnd();
                break;
            case 4:
                deleteAtEnd();
                break;
            case 5:
                insertAtFront();
                break;
            case 6:
                deleteAtFront();
                break;
            case 7:
                printf("Exiting program. Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice! Try again.\n");
        }
    }
    return 0;
}
