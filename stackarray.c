#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 100

int stack[MAX];
int top = -1;

// Check if stack is full
bool isFull() {
    return (top == MAX - 1);
}

// Check if stack is empty
bool isEmpty() {
    return (top == -1);
}

// Push operation
void push() {
    int data;

    if (isFull()) {
        printf("Stack is full\n");
        return;
    }

    printf("Enter the data: ");
    scanf("%d", &data);

    stack[++top] = data;
    printf("%d pushed to stack\n", data);
}

// Pop operation
void pop() {
    if (isEmpty()) {
        printf("Stack is empty\n");
        return;
    }

    printf("%d is deleted\n", stack[top]);
    top--;
}

// Peek operation
void peek() {
    if (isEmpty()) {
        printf("Stack is empty\n");
        return;
    }

    printf("Top element is %d\n", stack[top]);
}

// Display stack
void display() {
    if (isEmpty()) {
        printf("Stack is empty\n");
        return;
    }

    printf("Stack elements:\n");
    for (int i = 0; i <= top; i++) {
        printf("stack[%d] = %d\n", i + 1, stack[i]);
    }
}

int main() {
    int opt = 1;

    while (1) {
        printf("\n1) PUSH\n");
        printf("2) POP\n");
        printf("3) PEEK\n");
        printf("4) DISPLAY\n");
        printf("5) QUIT\n");
        printf("Choose your option: ");
        scanf("%d", &opt);

        switch (opt) {
            case 1: push(); break;
            case 2: pop(); break;
            case 3: peek(); break;
            case 4: display(); break;
            case 5: exit(0);
            default: printf("Invalid option\n");
        }
    }

    return 0;
}
