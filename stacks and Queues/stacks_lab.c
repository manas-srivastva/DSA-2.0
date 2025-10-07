#include <stdio.h>
#include <stdlib.h>

// Stack structure
struct Stack {
    int *arr;
    int top;
    int capacity;
};

// Initialize stack
void initStack(struct Stack *s, int size) {
    s->capacity = size;
    s->top = -1;
    s->arr = (int *)malloc(s->capacity * sizeof(int));
}

// Check if stack is full
int isFull(struct Stack *s) {
    return s->top == s->capacity - 1;
}

// Check if stack is empty
int isEmpty(struct Stack *s) {
    return s->top == -1;
}

// Push operation
void push(struct Stack *s, int value) {
    if (isFull(s)) {
        printf("Stack Overflow! Cannot push %d\n", value);
        return;
    }
    s->arr[++(s->top)] = value;
    printf("%d pushed\n", value);
}

// Pop operation
int pop(struct Stack *s) {
    if (isEmpty(s)) {
        printf("Stack Underflow! Cannot pop\n");
        return -1;
    }
    return s->arr[(s->top)--];
}

// Peek operation
int peek(struct Stack *s) {
    if (isEmpty(s)) {
        printf("Stack is empty!\n");
        return -1;
    }
    return s->arr[s->top];
}

// Display stack
void display(struct Stack *s) {
    if (isEmpty(s)) {
        printf("Stack is empty!\n");
        return;
    }
    printf("Stack elements (top to bottom): ");
    for (int i = s->top; i >= 0; i--) {
        printf("%d ", s->arr[i]);
    }
    printf("\n");
}

// Main function
int main() {
    struct Stack s;
    int size;

    printf("Enter size of stack: ");
    scanf("%d", &size);

    initStack(&s, size);

    // Perform some operations
    push(&s, 10);
    push(&s, 20);
    push(&s, 30);
    display(&s);

    printf("Top element: %d\n", peek(&s));

    printf("Popped: %d\n", pop(&s));
    display(&s);

    free(s.arr); // free allocated memory
    return 0;
}
