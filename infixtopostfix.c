// infix to postfix conversion using stack
// This program converts an infix expression to a postfix expression using a stack.
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

#define SIZE 100

char stack[SIZE];
int top = -1;

// Push function
void push(char c) {
    if (top == SIZE - 1) {
        printf("Stack Overflow\n");
        exit(1);
    }
    stack[++top] = c;
}

// Pop function
char pop() {
    if (top == -1) {
        printf("Stack Underflow\n");
        exit(1);
    }
    return stack[top--];
}

// Peek function (see top element)
char peek() {
    return stack[top];
}

// Function to return precedence
int precedence(char op) {
    if (op == '^')
        return 3;
    else if (op == '*' || op == '/')
        return 2;
    else if (op == '+' || op == '-')
        return 1;
    else
        return 0;
}

// Function to determine associativity
int isRightAssociative(char op) {
    if (op == '^')
        return 1; // right associative
    return 0;     // left associative
}

// Infix to Postfix function
void infixToPostfix(char infix[], char postfix[]) {
    int i, j = 0;
    char ch;

    for (i = 0; infix[i] != '\0'; i++) {
        ch = infix[i];

        if (ch == ' ')
            continue; // ignore spaces

        // If operand, add to postfix
        if (isalnum(ch)) {
            postfix[j++] = ch;
        }
        // If '(', push
        else if (ch == '(') {
            push(ch);
        }
        // If ')', pop until '('
        else if (ch == ')') {
            while (top != -1 && peek() != '(') {
                postfix[j++] = pop();
            }
            if (top != -1)
                pop(); // remove '('
            else {
                printf("Mismatched parentheses\n");
                exit(1);
            }
        }
        // If operator
        else {
            while (top != -1 && peek() != '(' &&
                   ((isRightAssociative(ch) == 0 && precedence(peek()) >= precedence(ch)) ||
                    (isRightAssociative(ch) == 1 && precedence(peek()) > precedence(ch)))) {
                postfix[j++] = pop();
            }
            push(ch);
        }
    }

    // Pop remaining operators
    while (top != -1) {
        if (peek() == '(') {
            printf("Mismatched parentheses\n");
            exit(1);
        }
        postfix[j++] = pop();
    }

    postfix[j] = '\0';
}

int main() {
    char infix[SIZE], postfix[SIZE];

    printf("Enter an Infix expression: ");
    fgets(infix, SIZE, stdin);
    infix[strcspn(infix, "\n")] = '\0';  // remove newline

    infixToPostfix(infix, postfix);

    printf("Postfix expression: %s\n", postfix);

    return 0;
}