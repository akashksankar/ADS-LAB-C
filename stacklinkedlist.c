#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node *newnode, *head = NULL;

void push() {
    newnode = (struct node*)malloc(sizeof(struct node));

    printf("Enter the data: ");
    scanf("%d", &newnode->data);

    newnode->next = head;
    head = newnode;

    printf("\n%d is pushed into the stack\n", head->data);
}

void pop() {
    struct node *temp;

    if (head == NULL) {
        printf("\nStack is empty\n");
        return;
    }

    temp = head;
    printf("The deleted data is %d\n", temp->data);

    head = head->next;
    free(temp);
}

void peek() {
    if (head == NULL) {
        printf("\nStack is empty\n");
        return;
    }

    printf("Top element is %d\n", head->data);
}

void display() {
    struct node *temp;

    if (head == NULL) {
        printf("Stack is empty\n");
        return;
    }

    temp = head;
    printf("Stack elements: ");

    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    int opt;

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

