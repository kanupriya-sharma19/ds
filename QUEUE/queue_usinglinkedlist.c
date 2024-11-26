#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
    int data;
    struct node*next;
    
}node;
node * front=0;node*rear=0;

void enqueue(int val){node *newnode;
newnode=(node *)malloc(sizeof (node));
newnode->data=val;
newnode->next=0;
    if(front==0&&rear==0){
        front=rear=newnode;
}else{
rear->next=newnode;
rear=newnode;
}
}

void dequeue(){node * temp;
    temp==front;
if(front==0&&rear==0){
        printf("empty");
}else{
  front=  front->next;
    free(temp);
}
}

void display(){
    node*temp;
    temp=front;
    if(front==0)printf("empty");
    else{
        while(temp!=0){
            printf("%d ",temp->data);
            temp=temp->next;
        }
    }
}

void peek(){
    if(front==0)printf("empty");
    else
    printf(" top is %d\n",front->data);
}

int main() {
    int choice, e, val; 
 printf("Enter your choice:\n1. Push\n2. Pop\n3. Display\n4. Peek\n");
    do {
        printf("Enter your choice:");
        scanf("%d", &choice);

        switch(choice) {   
            case 1:
                printf("Enter the value to be pushed: ");
                scanf("%d", &val);
                enqueue(val);
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

        printf("\nEnter 5 to continue: ");
        scanf("%d", &e);
    } while(e == 5);

    return 0;
}