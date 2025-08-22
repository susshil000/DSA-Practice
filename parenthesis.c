#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100   // maximum size of stack

// Stack structure
struct Stack {
    char arr[MAX];
    int top;
};

// Initialize stack
void init(struct Stack *s) {
    s->top = -1;
}

// Check if stack is empty
int isEmpty(struct Stack *s) {
    return s->top == -1;
}

// Check if stack is full
int isFull(struct Stack *s) {
    return s->top == MAX - 1;
}

// Push character onto stack
void push(struct Stack *s, char c) {
    if (isFull(s)) {
        printf("Stack Overflow\n");
        exit(1);
    }
    s->arr[++(s->top)] = c;
}

// Pop character from stack
char pop(struct Stack *s) {
    if (isEmpty(s)) {
        printf("Stack Underflow\n");
        exit(1);
    }
    return s->arr[(s->top)--];
}

// Function to check matching pairs
int isMatchingPair(char open, char close) {
    return (open == '(' && close == ')') ||
           (open == '{' && close == '}') ||
           (open == '[' && close == ']');
}

// Function to check if expression is balanced
int areParenthesesBalanced(char expr[]) {
    struct Stack s;
    init(&s);

    for (int i = 0; expr[i] != '\0'; i++) {
        char c = expr[i];

        // If opening symbol → push
        if (c == '(' || c == '{' || c == '[') {
            push(&s, c);
        }
        // If closing symbol → check match
        else if (c == ')' || c == '}' || c == ']') {
            if (isEmpty(&s)) {
                return 0;  // no opening for this closing
            }
            char top = pop(&s);
            if (!isMatchingPair(top, c)) {
                return 0;  // mismatch
            }
        }
    }

    return isEmpty(&s); // valid if stack is empty
}

int main() {
    char expr[MAX];

    printf("Enter an expression: ");
    scanf("%s", expr);

    if (areParenthesesBalanced(expr))
        printf("True\n");
    else
        printf("False\n");

    return 0;
}