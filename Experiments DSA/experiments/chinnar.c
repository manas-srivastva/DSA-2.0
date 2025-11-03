#include <stdio.h>
#include <stdlib.h>

#define MAX 10   /* change MAX as required */

typedef struct {
    int arr[MAX];
    int top;
} Stack;

void initStack(Stack *s) {
    s->top = -1;
}

int isFull(Stack *s) {
    return s->top == MAX - 1;
}

int isEmpty(Stack *s) {
    return s->top == -1;
}

int push(Stack *s, int value) {
    if (isFull(s)) {
        printf("Stack Overflow! Cannot push %d. (MAX = %d)\n", value, MAX);
        return 0; /* failure */
    }
    s->arr[++(s->top)] = value;
    return 1; /* success */
}

int pop(Stack *s, int *poppedValue) {
    if (isEmpty(s)) {
        printf("Stack Underflow! Nothing to pop.\n");
        return 0; /* failure */
    }
    *poppedValue = s->arr[(s->top)--];
    return 1; /* success */
}

void display(Stack *s) {
    if (isEmpty(s)) {
        printf("Stack is empty.\n");
        return;
    }
    printf("Stack (top -> bottom): ");
    for (int i = s->top; i >= 0; --i)
        printf("%d ", s->arr[i]);
    printf("\n");
}

/* Use a temporary stack to check if an integer is a palindrome by digits */
int isPalindromeNumber(int number) {
    if (number < 0) number = -number; /* consider absolute value for palindrome check */

    Stack temp;
    initStack(&temp);

    int n = number;
    if (n == 0) {
        /* zero is a palindrome */
        return 1;
    }

    /* push digits onto temp stack */
    while (n > 0) {
        int d = n % 10;
        if (!push(&temp, d)) {
            /* overflow in temp stack -- treat as not able to check */
            printf("Temporary stack overflow while checking palindrome (increase MAX).\n");
            return 0;
        }
        n /= 10;
    }

    /* pop digits and build reversed number */
    int rev = 0;
    int digit;
    int mul = 1;
    /* compute multiplier correctly: pop until temp empty */
    while (!isEmpty(&temp)) {
        pop(&temp, &digit);
        rev = rev * 10 + digit;
    }

    return (rev == number);
}

int main() {
    Stack s;
    initStack(&s);

    int choice;
    while (1) {
        printf("\n--- Stack Menu ---\n");
        printf("1. Push an element onto stack\n");
        printf("2. Pop an element from stack\n");
        printf("3. Check if an integer is palindrome (using stack)\n");
        printf("4. Demonstrate Overflow (push until full)\n");
        printf("5. Demonstrate Underflow (pop until empty)\n");
        printf("6. Display stack status\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        if (scanf("%d", &choice) != 1) {
            printf("Invalid input. Exiting.\n");
            break;
        }

        if (choice == 1) {
            int val;
            printf("Enter integer to push: ");
            scanf("%d", &val);
            if (push(&s, val))
                printf("%d pushed onto stack.\n", val);
        } else if (choice == 2) {
            int popped;
            if (pop(&s, &popped))
                printf("Popped element: %d\n", popped);
        } else if (choice == 3) {
            int num;
            printf("Enter integer to check palindrome: ");
            scanf("%d", &num);
            if (isPalindromeNumber(num))
                printf("%d is a palindrome.\n", num);
            else
                printf("%d is NOT a palindrome.\n", num);
        } else if (choice == 4) {
            printf("Pushing values until overflow occurs (to demonstrate overflow):\n");
            int i = 1;
            while (1) {
                if (!push(&s, i)) break;
                printf("pushed %d\n", i);
                ++i;
            }
            display(&s);
        } else if (choice == 5) {
            printf("Popping values until underflow occurs (to demonstrate underflow):\n");
            int val;
            while (pop(&s, &val)) {
                printf("popped %d\n", val);
            }
            display(&s);
        } else if (choice == 6) {
            display(&s);
            printf("Stack size: %d / %d\n", s.top + 1, MAX);
        } else if (choice == 7) {
            printf("Exiting.\n");
            break;
        } else {
            printf("Invalid choice. Try again.\n");
        }
    }

    return 0;
}