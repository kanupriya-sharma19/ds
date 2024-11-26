#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    int priority;
    struct node *next;
} node;

node *front = 0, *temp = 0;

void enqueue(int val, int pri) {
    node *newnode;
    newnode = (node *)malloc(sizeof(node));
    newnode->data = val;
    newnode->priority = pri;
    newnode->next = 0;

    if (front == 0 || pri < front->priority) {
        newnode->next = front;
        front = newnode;
    } else {
        temp = front;
        while (temp->next != 0 && temp->next->priority <= pri)
            temp = temp->next;
        newnode->next = temp->next;
        temp->next = newnode;
    }
}

void dequeue() {
    if (front == 0) {
        printf("Queue is empty\n");
    } else {
        temp = front;
        front = front->next;
        free(temp);
    }
}

void display() {
    if (front == 0) {
        printf("Queue is empty\n");
    } else {
        temp = front;
        while (temp != 0) {
            printf("Value: %d, Priority: %d\n", temp->data, temp->priority);
            temp = temp->next;
        }
    }
}

void peek() {
    if (front == 0) {
        printf("Queue is empty\n");
    } else {
        printf("Top value is %d with priority %d\n", front->data, front->priority);
    }
}

int main() {
    int choice, e, val, pri;

    do {
        printf("Enter your choice:\n1. Enqueue\n2. Dequeue\n3. Display\n4. Peek\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the value and priority to be enqueued: ");
                scanf("%d %d", &val, &pri);
                enqueue(val, pri);
                break;

            case 2:
                dequeue();
                break;

            case 3:
                display();
                break;

            case 4:
                peek();
                break;

            default:
                printf("Invalid choice\n");
        }

        printf("Enter 5 to continue: ");
        scanf("%d", &e);
    } while (e == 5);

    return 0;
}
