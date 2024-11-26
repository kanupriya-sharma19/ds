#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
    int data;
    struct node*next;
    
}node;
node*top=0;
void push(int val){
    node*newnode;
    newnode=(node*)malloc(sizeof(node));
    newnode->data=val;
    newnode->next=top;
    top=newnode;
}

void display(){
    node*temp;
    temp=top;
    if(top==0)printf("empty");
    else{
        while(temp!=0){
            printf("%d ",temp->data);
            temp=temp->next;
        }
    }
}

void peek(){
    if(top==0)printf("empty");
    else
    printf(" top is %d",top->data);
}

void pop(){
    node*temp;
    temp=top;
    if(top==0){
        printf("empty");
    }else{
        printf("%d",top->data);
        top=top->next;
        free(temp);
    }}
int main() {
    int choice, e, val; 
printf("Enter your choice:\n1. Push\n2. Pop\n3. Display\n4. Peek\n");
    do {
        printf("Enter your choice: ");
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

        printf("\nEnter 5 to continue: ");
        scanf("%d", &e);
    } while(e == 5);

    return 0;
}


