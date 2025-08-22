// using in stack push, pop, peek operations
#include<stdio.h>
#define SIZE 5

int stk[SIZE];
int top = -1;

void push(int item) {
    if (top == SIZE-1) {
        printf("Stack overflow\n");
    } else {
        stk[++top] = item;
        printf("%d pushed onto stack\n", item);
    }
}
void pop() {
    if (top == -1) {
        printf("Stack underflow\n");

       
    } else {
    
        top--;
        printf("Popped from stack %d \n",stk[top]);
    }
}
void peek() {
    if (top == -1) {
        printf("Stack is empty\n");
    } else {
        printf("Top element is %d\n", stk[top]);
    }
}
 int main() {
    
    pop(); // This should pop the last pushed element
    peek(); // This should show the top element of the stack
    push(10);
    push(20);
    push(30);
    push(40);
    push(50);
    push(60); // This should indicate stack overflow
    peek(); // This should show the top element of the stack
    pop(); // This should pop the top element
    peek(); // This should show the new top element of the stack
    return 0;
}



