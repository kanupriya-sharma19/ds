//multiple stacks using an array
#include <stdio.h>

int arr[10];
int top1 = -1;
int top2 = 10;
int max = 10;

void push1(int val) {
    if (top1 == top2 - 1) {
        printf("Stack 1 is Full\n");
    } else {
        top1 = top1 + 1;
        arr[top1] = val;
    }
}

void push2(int val) {
    if (top1 == top2 - 1) {
        printf("Stack 2 is Full\n");
    } else {
        top2 = top2 - 1;
        arr[top2] = val;
    }
}

void pop1(){
    if(top1==-1)
    printf("Stack 1 is empty\n");
    else{
        int temp=arr[top1];
        top1--;

    }
}
void pop2(){
    if(top2==10)
    printf("Stack 2 is empty\n");
    else{
        int temp=arr[top2];
        top2++;

    }
}

void display1() {
    if (top1 == -1) {
        printf("Stack 1 is empty\n");
    } else {
        printf("Stack 1 elements: ");
        for (int i = top1; i >= 0; i--) {
            printf("%d ", arr[i]);
        }
        printf("\n");
    }
}

void display2() {
    if (top2 == max) {
        printf("Stack 2 is empty\n");
    } else {
        printf("Stack 2 elements: ");
        for (int i = top2; i < max; i++) {
            printf("%d ", arr[i]);
        }
        printf("\n");
    }
}

void displayCombined() {
    printf("Combined elements of Stack 1 and Stack 2: ");

    for (int i = top1; i >= 0; i--) {
        printf("%d ", arr[i]);
    }
    for (int i = top2; i < max; i++) {
        printf("%d ", arr[i]);
    }
    
    printf("\n");
}

int main() {
    int choice, e, val;
    do {
        printf("Choices:\n1. Push from Stack1\n2. Push from Stack2\n3. Pop from Stack1\n4. Pop from Stack2\n5. Display Stack1\n6. Display Stack2\n7. Display Combined stacks\n");
        printf("Enter your choice : ");
        scanf("%d", &choice);

        switch (choice) {   
            case 1:
                printf("Enter the value to be pushed from start: ");
                scanf("%d", &val);
                push1(val);
                break;

            case 2:
                printf("Enter the value to be pushed from end: ");
                scanf("%d", &val);
                push2(val);
                break;
            case 3:
                pop1();
                break;

            case 4:
                pop2();
                break;

            case 5:
                display1();
                break;

            case 6:
                display2();
                break;

            case 7:
                displayCombined();
                break;
        }

        
        printf("Enter 8 to continue: ");
        scanf("%d", &e);
    } while(e == 8);
        


    return 0;
}