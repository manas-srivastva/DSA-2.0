#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure for Employee node
struct Employee {
    char ssn[20], name[50], dept[20], desig[30];
    float sal;
    long phno;
    struct Employee *next;
};

// Global pointer
struct Employee *head = NULL;

// Function to create a new node
struct Employee* createNode() {
    struct Employee *newNode = (struct Employee*)malloc(sizeof(struct Employee));
    printf("Enter SSN: ");
    scanf("%s", newNode->ssn);
    printf("Enter Name: ");
    scanf("%s", newNode->name);
    printf("Enter Department: ");
    scanf("%s", newNode->dept);
    printf("Enter Designation: ");
    scanf("%s", newNode->desig);
    printf("Enter Salary: ");
    scanf("%f", &newNode->sal);
    printf("Enter Phone Number: ");
    scanf("%ld", &newNode->phno);
    newNode->next = NULL;
    return newNode;
}

// Function to insert at end
void insertEnd() {
    struct Employee *newNode = createNode();
    if (head == NULL) {
        head = newNode;
        newNode->next = head;
    } else {
        struct Employee *temp = head;
        while (temp->next != head)
            temp = temp->next;
        temp->next = newNode;
        newNode->next = head;
    }
    printf("\nEmployee inserted at end successfully!\n");
}

// Function to insert at front
void insertFront() {
    struct Employee *newNode = createNode();
    if (head == NULL) {
        head = newNode;
        newNode->next = head;
    } else {
        struct Employee *temp = head;
        while (temp->next != head)
            temp = temp->next;
        newNode->next = head;
        temp->next = newNode;
        head = newNode;
    }
    printf("\nEmployee inserted at front successfully!\n");
}

// Function to delete from front
void deleteFront() {
    if (head == NULL) {
        printf("\nList is empty.\n");
        return;
    }
    struct Employee *temp = head;
    if (head->next == head) {
        printf("\nDeleted Employee: %s\n", head->name);
        free(head);
        head = NULL;
        return;
    }
    struct Employee *last = head;
    while (last->next != head)
        last = last->next;
    printf("\nDeleted Employee: %s\n", head->name);
    head = head->next;
    last->next = head;
    free(temp);
}

// Function to delete from end
void deleteEnd() {
    if (head == NULL) {
        printf("\nList is empty.\n");
        return;
    }
    struct Employee *temp = head, *prev = NULL;
    if (head->next == head) {
        printf("\nDeleted Employee: %s\n", head->name);
        free(head);
        head = NULL;
        return;
    }
    while (temp->next != head) {
        prev = temp;
        temp = temp->next;
    }
    printf("\nDeleted Employee: %s\n", temp->name);
    prev->next = head;
    free(temp);
}

// Function to display list
void displayList() {
    if (head == NULL) {
        printf("\nList is empty.\n");
        return;
    }
    struct Employee *temp = head;
    int count = 0;
    printf("\n%-15s %-15s %-15s %-15s %-10s %-15s\n", "SSN", "Name", "Dept", "Designation", "Salary", "Phone");
    printf("-------------------------------------------------------------------------------\n");
    do {
        printf("%-15s %-15s %-15s %-15s %-10.2f %-15ld\n",
               temp->ssn, temp->name, temp->dept, temp->desig, temp->sal, temp->phno);
        temp = temp->next;
        count++;
    } while (temp != head);
    printf("\nTotal Employees: %d\n", count);
}

// Function to create list with N employees
void createList() {
    int n, i;
    printf("Enter number of employees: ");
    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        printf("\nEnter details for Employee %d:\n", i + 1);
        insertEnd();
    }
}

// Main menu
int main() {
    int choice;
    while (1) {
        printf("\n--- SINGLE CIRCULAR LINKED LIST MENU ---\n");
        printf("1. Create SCLL using end insertion\n");
        printf("2. Display SCLL and count nodes\n");
        printf("3. Insert at End\n");
        printf("4. Delete at End\n");
        printf("5. Insert at Front\n");
        printf("6. Delete at Front\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: createList(); break;
            case 2: displayList(); break;
            case 3: insertEnd(); break;
            case 4: deleteEnd(); break;
            case 5: insertFront(); break;
            case 6: deleteFront(); break;
            case 7: exit(0);
            default: printf("\nInvalid choice! Try again.\n");
        }
    }
    return 0;
}
