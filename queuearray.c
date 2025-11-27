#include <stdio.h>
#include <stdlib.h>

#define N 10

int queue[N];
int rear = -1, front = -1;

void enqueue() {
    int val;
    printf("Enter the data: ");
    scanf("%d", &val);

    if (rear == N - 1) {
        printf("Queue is overflow\n");
        return;
    }
    else if (front == -1 && rear == -1) {
        front = rear = 0;
        queue[rear] = val;
    }
    else {
        rear++;
        queue[rear] = val;
    }
}

void dequeue() {
    if (front == -1 && rear == -1) {
        printf("Queue is underflow\n");
        return;
    }
    else if (front == rear) {
        printf("Deleted element is %d\n", queue[front]);
        front = rear = -1;
    }
    else {
        printf("Deleted element is %d\n", queue[front]);
        front++;
    }
}

void display() {
    if (front == -1 && rear == -1) {
        printf("Queue is empty\n");
        return;
    }

    printf("Queue elements: ");
    for (int i = front; i <= rear; i++) {
        printf("%d ", queue[i]);
    }
    printf("\n");
}

int main() {
    int opt;

    while (1) {
        printf("\n1) ENQUEUE\n");
        printf("2) DEQUEUE\n");
        printf("3) DISPLAY\n");
        printf("4) EXIT\n");
        printf("Enter your option: ");
        scanf("%d", &opt);

        switch (opt) {
            case 1: enqueue(); break;
            case 2: dequeue(); break;
            case 3: display(); break;
            case 4: exit(0);
            default: printf("Invalid option\n");
        }
    }

    return 0;
}
