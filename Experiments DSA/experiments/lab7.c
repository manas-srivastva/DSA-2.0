#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100  // Maximum size of stack

int stack[MAX];   // Stack array
int top = -1;     // Indicates top of stack

// Function to push element into stack
void push(int element) {
    if (top == MAX - 1) {
        printf("\nStack Overflow! Cannot push %d.\n", element);
        return;
    }
    stack[++top] = element;
    printf("\n%d pushed onto stack.\n", element);
}

// Function to pop element from stack
void pop() {
    if (top == -1) {
        printf("\nStack Underflow! No element to pop.\n");
        return;
    }
    printf("\nPopped element: %d\n", stack[top--]);
}

// Function to display the stack
void display() {
    if (top == -1) {
        printf("\nStack is empty.\n");
        return;
    }
    printf("\nStack elements are:\n");
    for (int i = top; i >= 0; i--) {
        printf("%d\n", stack[i]);
    }
    printf("Top = %d\n", top);
}

// Function to check palindrome using stack
void checkPalindrome() {
    char str[100];
    char temp[100];
    int i, j, len;

    printf("Enter a string: ");
    scanf("%s", str);
    len = strlen(str);

    // Push all characters into stack
    top = -1;
    for (i = 0; i < len; i++) {
        if (top == MAX - 1) {
            printf("\nStack Overflow! Cannot check palindrome.\n");
            return;
        }
        stack[++top] = str[i];
    }

    // Pop and build reverse string
    for (i = 0; i < len; i++) {
        temp[i] = stack[top--];
    }
    temp[i] = '\0';

    if (strcmp(str, temp) == 0)
        printf("\nThe string \"%s\" is a Palindrome.\n", str);
    else
        printf("\nThe string \"%s\" is NOT a Palindrome.\n", str);
}

// Main Menu
int main() {
    int choice, element;

    while (1) {
        printf("\n--- STACK OPERATIONS MENU ---\n");
        printf("1. Push an Element\n");
        printf("2. Pop an Element\n");
        printf("3. Display Stack\n");
        printf("4. Check Palindrome using Stack\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter element to push: ");
                scanf("%d", &element);
                push(element);
                break;
            case 2:
                pop();
                break;
            case 3:
                display();
                break;
            case 4:
                checkPalindrome();
                break;
            case 5:
                exit(0);
            default:
                printf("\nInvalid choice! Try again.\n");
        }
    }

    return 0;
}
