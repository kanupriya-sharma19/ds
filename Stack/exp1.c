#include<stdio.h>
int arr[10];
int top = -1;
int n = 10;

void push(int val) {
    if(top == n - 1) {
        printf("Stack is Full\n");
    } else {
        top = top + 1;
        arr[top] = val;
    }
}

void peek() {
    if(top == -1) {
        printf("\nStack is empty\n");
    } else { 
        printf("\nTop element is %d\n", arr[top]);
    }
}

void pop() {
    int temp;
    if(top == -1) {
        printf("Stack is empty\n");
    } else {
        temp = arr[top];
        top = top - 1;
        printf("Deleted item is %d\n", temp);
    }
}

void display() {
    if(top == -1) {
        printf("Stack is empty\n");
    } else {
        for(int i = top; i >= 0; i--) {
            printf("Element: %d\n", arr[i]);
        }
    }
}

int main() {
    int choice, e, val; 
    do {
        printf("Enter your choice:\n1. Push\n2. Pop\n3. Display\n4. Peek\n");
        scanf("%d", &choice);

        switch(choice) {   
            case 1:
                printf("Enter the value to be pushed: ");
                scanf("%d", &val);
                push(val);
                break;

            case 2:
                pop();
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
    } while(e == 5);
    return 0;
}
