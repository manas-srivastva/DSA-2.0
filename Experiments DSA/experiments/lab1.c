#include <stdio.h>

int arr[100];   // Global array
int n = 0;      // Global size variable

// Function declarations
void createArray();
void displayArray();
void insertElement();
void deleteElement();

int main() {
    int choice;

    while (1) {
        printf("\n--- Array Operations Menu ---\n");
        printf("1. Create Array\n");
        printf("2. Display Array\n");
        printf("3. Insert Element\n");
        printf("4. Delete Element\n");
        printf("5. Exit\n");
        printf("-----------------------------\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                createArray();
                break;
            case 2:
                displayArray();
                break;
            case 3:
                insertElement();
                break;
            case 4:
                deleteElement();
                break;
            case 5:
                printf("Exiting program. Goodbye!\n");
                return 0;
            default:
                printf("Invalid choice! Try again.\n");
        }
    }
}

// Function to create array
void createArray() {
    int i;
    printf("Enter number of elements: ");
    scanf("%d", &n);

    if (n <= 0 || n > 100) {
        printf("Invalid size! Must be between 1 and 100.\n");
        n = 0;
        return;
    }

    printf("Enter %d elements:\n", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    printf("Array created successfully!\n");
}

// Function to display array
void displayArray() {
    int i;
    if (n == 0) {
        printf("Array is empty!\n");
        return;
    }

    printf("Array elements are:\n");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Function to insert an element
void insertElement() {
    int elem, pos, i;

    if (n == 0) {
        printf("Array is empty. Create array first!\n");
        return;
    }

    printf("Enter element to insert: ");
    scanf("%d", &elem);
    printf("Enter position (1 to %d): ", n + 1);
    scanf("%d", &pos);

    if (pos < 1 || pos > n + 1) {
        printf("Invalid position!\n");
        return;
    }

    for (i = n; i >= pos; i--) {
        arr[i] = arr[i - 1];
    }

    arr[pos - 1] = elem;
    n++;
    printf("Element inserted successfully!\n");
}

// Function to delete an element
void deleteElement() {
    int pos, i;

    if (n == 0) {
        printf("Array is empty. Nothing to delete!\n");
        return;
    }

    printf("Enter position to delete (1 to %d): ", n);
    scanf("%d", &pos);

    if (pos < 1 || pos > n) {
        printf("Invalid position!\n");
        return;
    }

    for (i = pos - 1; i < n - 1; i++) {
        arr[i] = arr[i + 1];
    }

    n--;
    printf("Element deleted successfully!\n");
}
