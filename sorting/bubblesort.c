#include<stdio.h>
#include<conio.h>
void main(){
    int n,i,temp;


printf("Enter the number elements in an array\n");
scanf("%d",&n);
printf("Enter the elements in an array\n");
int arr[n];
for(i=0;i<n;i++){
    scanf("%d",&arr[i]);
}
for(i=0;i<n;i++){
    for(int j=i+1;j<n;j++){
        if(arr[i]>arr[j]){
            temp=arr[i];
            arr[i]=arr[j];
            arr[j]=temp;

        }
    }
}
for(i=0;i<n;i++){
    printf("%d ",arr[i]);
}
}