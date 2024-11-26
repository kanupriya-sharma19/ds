#include <stdio.h>

#define MAX 20
int queue[MAX];
int rear = -1, front = -1;

void frontenqueue(int val) {
    if ((rear + 1) % MAX == front) {
        printf("Queue is full\n");
    } else if (front == -1) {
        front = rear = 0;
        queue[front] = val;
    } else if (front == 0) {
        front = MAX - 1;
        queue[front] = val;
    } else {
        front--;
        queue[front] = val;
    }
}

void rearenqueue(int val) {
    if ((rear + 1) % MAX == front) {
        printf("Queue is full\n");
    } else if (front == -1) {
        front = rear = 0;
        queue[rear] = val;
    } else if (rear == MAX - 1) {
        rear = 0;
        queue[rear] = val;
    } else {
        rear++;
        queue[rear] = val;
    }
}

void display(){int i=front;
    if(front==-1||rear==-1)
    printf("empty");    else{
        printf("queue is ");
        while(i!=rear){
            printf("%d ",queue[i]);
            i=(i+1)%MAX;

        }
        printf("%d",queue[rear]);
    }
}

int frontdelete() {
    if (front == -1) {
        printf("Queue is empty\n");
        return -1; 
    } else {
        int temp = queue[front];
        if (front == rear) {
            front = rear = -1; 
        } else {
            front = (front + 1) % MAX;
        }
        return temp;
    }
}

void peek() {
    if (front == -1) {
        printf("Queue is empty\n");
    } else {
        printf("The first element is %d\n", queue[front]);
    }
}

int main() {
    int choice, e;
    printf("Choices: \n1. Enqueue the element from front\n2. Enqueue the element from back\n3. Peek operation\n4. Front delete\n6. Display the queue\n");

    do {
        printf("Enter the choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter the value to enqueue from front: ");
                int val;
                scanf("%d", &val);
                frontenqueue(val);
                break;
            case 2:
                printf("Enter the value to enqueue from back: ");
                int v;
                scanf("%d", &v);
                rearenqueue(v);
                break;
            case 3:
                peek();
                break;
            case 4:
                printf("Deleted element from front: %d\n", frontdelete());
                break;
            
            case 5:
                display();
                break;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    
        printf("Enter 5 to exit or any other number to continue: ");
        scanf("%d", &e);
    
    } while (e != 5);

    return 0;
}
