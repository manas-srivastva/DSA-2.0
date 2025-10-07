#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX 100

char stack[MAX];
int top = -1;

// Function to push into stack
void push(char c) {
    if (top == MAX - 1) {
        printf("Stack Overflow!\n");
        return;
    }
    stack[++top] = c;
}

// Function to pop from stack
char pop() {
    if (top == -1) {
        printf("Stack Underflow!\n");
        return -1;
    }
    return stack[top--];
}

// Function to get precedence of operators
int precedence(char c) {
    switch (c) {
        case '^': return 3;
        case '*':
        case '/':
        case '%': return 2;
        case '+':
        case '-': return 1;
        default: return 0;
    }
}

// Function to check if operator is right associative
int isRightAssociative(char c) {
    if (c == '^')
        return 1;
    return 0;
}

// Function to check if character is an operator
int isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/' || c == '%' || c == '^');
}

// Function to convert infix to postfix
void infixToPostfix(char infix[], char postfix[]) {
    int i, j = 0;
    char c;

    for (i = 0; infix[i] != '\0'; i++) {
        c = infix[i];

        // If operand, add to postfix
        if (isalnum(c)) {
            postfix[j++] = c;
        }
        // If '(' push to stack
        else if (c == '(') {
            push(c);
        }
        // If ')' pop until '(' is found
        else if (c == ')') {
            while (top != -1 && stack[top] != '(') {
                postfix[j++] = pop();
            }
            pop(); // remove '('
        }
        // If operator
        else if (isOperator(c)) {
            while (top != -1 && precedence(stack[top]) > 0 &&
                  ((isRightAssociative(c) == 0 && precedence(c) <= precedence(stack[top])) ||
                   (isRightAssociative(c) == 1 && precedence(c) < precedence(stack[top])))) {
                postfix[j++] = pop();
            }
            push(c);
        }
    }

    // Pop all remaining operators
    while (top != -1) {
        postfix[j++] = pop();
    }

    postfix[j] = '\0';  // Null terminate string
}

// Main function
int main() {
    char infix[MAX], postfix[MAX];

    printf("Enter Infix Expression: ");
    scanf("%s", infix);

    infixToPostfix(infix, postfix);

    printf("Postfix Expression: %s\n", postfix);

    return 0;
}
