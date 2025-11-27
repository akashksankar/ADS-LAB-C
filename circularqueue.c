#include <stdio.h>
#include <stdlib.h>

#define N 5

int queue[N];
int rear = -1, front = -1;

// ENQUEUE
void enqueue() {
    int val;
    printf("Enter the data: ");
    scanf("%d", &val);

    if ((rear + 1) % N == front) {
        printf("Queue is overflow\n");
        return;
    }
    else if (front == -1 && rear == -1) {
        front = rear = 0;
        queue[rear] = val;
    }
    else {
        rear = (rear + 1) % N;
        queue[rear] = val;
    }
}

// DEQUEUE
void dequeue() {
    if (front == -1 && rear == -1) {
        printf("Queue is underflow\n");
        return;
    }
    else if (front == rear) {
        printf("Deleted item is %d\n", queue[front]);
        front = rear = -1;
    }
    else {
        printf("Deleted item is %d\n", queue[front]);
        front = (front + 1) % N;
    }
}

// SEARCH
void search() {
    int data, flag = 0, pos = 1;
    int i;

    if (front == -1 && rear == -1) {
        printf("Queue is underflow\n");
        return;
    }

    printf("Enter the data to search: ");
    scanf("%d", &data);

    i = front;

    while (1) {
        if (queue[i] == data) {
            flag = 1;
            break;
        }

        if (i == rear)
            break;

        i = (i + 1) % N;
        pos++;
    }

    if (flag)
        printf("Element %d found at position %d\n", data, pos);
    else
        printf("Element not found\n");
}

// DISPLAY
void display() {
    if (front == -1 && rear == -1) {
        printf("Queue is underflow\n");
        return;
    }

    int i = front;
    printf("Queue elements: ");

    while (1) {
        printf("%d ", queue[i]);
        if (i == rear)
            break;
        i = (i + 1) % N;
    }

    printf("\n");
}

int main() {
    int opt;

    while (1) {
        printf("\n1) ENQUEUE\n");
        printf("2) DEQUEUE\n");
        printf("3) DISPLAY\n");
        printf("4) SEARCH\n");
        printf("5) EXIT\n");
        printf("Enter the option: ");
        scanf("%d", &opt);

        switch (opt) {
            case 1: enqueue(); break;
            case 2: dequeue(); break;
            case 3: display(); break;
            case 4: search(); break;
            case 5: exit(0);
            default: printf("Invalid option\n");
        }
    }

    return 0;
}
