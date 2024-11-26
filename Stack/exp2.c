//decimal to binary
#include<stdio.h>
#include<conio.h>
int arr[10];int n=10;
int top=-1;
int i;

void push(int val){
   
    if(top==n-1){
        printf("Full stack");
    }
    else{
        top=top+1;
        arr[top]=val;
    }
}

void display(){
    for(i=top;i>=0;i--){
        printf("%d",arr[i]);
    }
}


 void main(){
        int n;
printf("Enter the number :");
scanf("%d",&n);
while(n>0){
    int i=n%2;
    n=n/2;
    push(i);
}printf("Binary format is :");
 display();}