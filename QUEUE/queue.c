

//queue
// #include<stdio.h>
// #include <ctype.h>
 
// #define max 20
// int queue[20];int temp;
// int rear=-1,front=1;
// void enque(int val){
//     if(rear==max-1)
//     printf("Queue is full");
//     else if (rear==-1||front==-1)
//     {
// rear++;front++;
//     queue[rear]=val;
//     }
//     else{
//         rear++;
//         queue[rear]=val;
//     }
//     printf("%d",queue[rear]);
// }
// void deque(){
// if(rear==-1){
//     printf("empty");
  
// }
// else if(front==rear){
 
//     temp=queue[front];
//     printf("%d",queue[front]);
//     front=rear=-1;
   
// }
// else{
//     temp=queue[front];
//     front++;
//     }
// }

// void display(){
//     if(front==-1||rear==-1)
//     printf("empty");
//     else
//     for(int i=front;i<rear;i++)
//     printf("%d    ",queue[i]);
// }
// void main(){
//     enque(10);
//     enque(20);
//     enque(30);
// deque();
//     display();
// }

#include <stdio.h>

#define max 20
int queue[max];
int temp;
int rear = -1, front = -1;

void enqueue(int val) {
    if (rear == max - 1)
        printf("Queue is full\n");
    else {
        if (rear == -1) {
            front = 0; // Initialize front to 0 when the first element is added
        }
        rear++;
        queue[rear] = val;
        printf("Enqueued: %d\n", queue[rear]);
    }
}

void dequeue() {
    if (front == -1) {
        printf("Queue is empty\n");
    } else {
        temp = queue[front];
        printf("Dequeued: %d\n", queue[front]);
        if (front == rear) {
            // If the queue becomes empty after dequeuing
            front = rear = -1;
        } else {
            front++;
        }
    }
}
void peek(){ if (front == -1 || rear == -1)
        printf("Queue is empty\n");
        else{
            printf("The 1st element is %d\n",queue[front]);
        }


}
void display() {
    if (front == -1 || rear == -1)
        printf("Queue is empty\n");
    else {
        printf("Queue elements:\n");
        for (int i = front; i <= rear; i++)
            printf("%d ", queue[i]);
        printf("\n");
    }
}

int main() {int choice,e;
printf("Choices: \n1.Enqueue the element\n2.Dequeue the element\n3.Peek operation\n4.Display the queue\n5.Exit the code\n");
   
    do{ 
    printf("Enter the choice:");
    scanf("%d",&choice);
    switch (choice)
    {
    case 1:printf("Enter the value to enqueue: ");
    int val;
    scanf("%d",&val);
        enqueue(val);
        break;
        case 2: dequeue();break;
        case 3: peek();break;
        case 4: display();break;
     
    }
 printf("Enter 5 to continue: ");
        scanf("%d", &e);
    
    }while (e==5);
    return 0;
}
