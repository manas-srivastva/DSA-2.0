#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure for Employee node
struct Employee {
    char ssn[20], name[50], dept[20], desig[30];
    float sal;
    long phno;
    struct Employee *prev, *next;
};

// Global head and tail pointers
struct Employee *head = NULL, *tail = NULL;

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
    newNode->prev = newNode->next = NULL;
    return newNode;
}

// Function to insert at end
void insertEnd() {
    struct Employee *newNode = createNode();
    if (head == NULL) {
        head = tail = newNode;
    } else {
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    }
    printf("\nEmployee inserted at end successfully!\n");
}

// Function to insert at front
void insertFront() {
    struct Employee *newNode = createNode();
    if (head == NULL) {
        head = tail = newNode;
    } else {
        newNode->next = head;
        head->prev = newNode;
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
    printf("\nDeleted Employee: %s\n", head->name);
    if (head == tail) {
        head = tail = NULL;
    } else {
        head = head->next;
        head->prev = NULL;
    }
    free(temp);
}

// Function to delete from end
void deleteEnd() {
    if (tail == NULL) {
        printf("\nList is empty.\n");
        return;
    }
    struct Employee *temp = tail;
    printf("\nDeleted Employee: %s\n", tail->name);
    if (head == tail) {
        head = tail = NULL;
    } else {
        tail = tail->prev;
        tail->next = NULL;
    }
    free(temp);
}

// Function to display all employees
void displayList() {
    if (head == NULL) {
        printf("\nList is empty.\n");
        return;
    }
    struct Employee *temp = head;
    int count = 0;
    printf("\n%-15s %-15s %-15s %-15s %-10s %-15s\n", "SSN", "Name", "Dept", "Designation", "Salary", "Phone");
    printf("-------------------------------------------------------------------------------\n");
    while (temp != NULL) {
        printf("%-15s %-15s %-15s %-15s %-10.2f %-15ld\n",
               temp->ssn, temp->name, temp->dept, temp->desig, temp->sal, temp->phno);
        temp = temp->next;
        count++;
    }
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

// Main function (Menu driven)
int main() {
    int choice;
    while (1) {
        printf("\n--- DOUBLY LINKED LIST MENU ---\n");
        printf("1. Create DLL using end insertion\n");
        printf("2. Display DLL and count nodes\n");
        printf("3. Insert at End\n");
        printf("4. Delete at End\n");
        printf("5. Insert at Front (Queue/Stack demo)\n");
        printf("6. Delete at Front (Queue/Stack demo)\n");
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
