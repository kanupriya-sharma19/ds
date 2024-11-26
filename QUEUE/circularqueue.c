
#include <stdio.h>

#define max 20
int queue[max];
int temp;
int rear = -1, front = -1;

void enqueue(int val){
    if((rear+1)%max==front)
    printf("FULL");
    else if (front==-1){
        front=rear=0;
        queue[rear]=val;
    }
    else{
        rear=(rear+1)%max;
        queue[rear]=val;
    }
}
int dequeue(){ int temp;
     if (front==-1)
         printf("empty");
    else if( front==rear){
        temp=queue[front];
        front=rear=-1;
        return temp;
    }
      else{
        temp=queue[front];
        front=(front+1)%max;
        return temp;
      }
    
    
}
void display(){int i=front;
    if(front==-1||rear==-1)
    printf("empty");    else{
        printf("queue is ");
        while(i!=rear){
            printf("%d ",queue[i]);
            i=(i+1)%max;

        }
        printf("%d",queue[rear]);
    }
}

void peek(){ if (front == -1 || rear == -1)
        printf("Queue is empty\n");
        else{
            printf("The 1st element is %d\n",queue[front]);
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
