#include<stdio.h>
#include<conio.h>
void main(){
    int n,i,temp,num;
    
printf("Enter the number elements in an array\n");
scanf("%d",&n);
printf("Enter the elements in an array\n");
int arr[n];
for(i=0;i<n;i++){
    scanf("%d",&arr[i]);
}
printf("Enter the element to be searched \n");
scanf("%d",&num);


for(i=0;i<n;i++){
        if(arr[i]==num){
 printf("The element is found at index %d ",i+1);break;}
  if(i==n-1){
 printf("The element is not found ");}

        }
       
}