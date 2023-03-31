#include<stdio.h>
#include<stdlib.h>
#define MAX 10

void createarray(int arr[], int n);
void printarray(int *arr, int n);
int insertarray(int arr[], int pos, int num, int n);

int main()
{
    int *arr,n,num,pos;
    arr=(int *)calloc(MAX, sizeof(int));
    printf("enter no. of element :");
    scanf("%d",&n);
    printf("enter num and pos :");
    scanf("%d%d",&num,&pos);
    createarray(arr,n);
    printarray(arr,n);
    insertarray(arr,pos,num,n);
    //deletearray();

}
void createarray(int arr[], int n)
{   
    printf("take input:\n");
    for (int i=0;i<n;i++)
    {
        scanf("%d", &arr[i]);
    }
}
void printarray(int *arr, int n)
{   
    printf("ouput:\n");
    for (int i=0;i<n;i++)
    {   
        printf("%d\n", *(arr+i));
    }
}
int insertarray(int arr[], int pos, int num, int n)
{ 
    if(pos<=0 || pos>n+1)
    {
        printf("oh no!");
    }
    else
    {
       for(int i=n-1;i>=pos-1;i--)
       {
           arr[i+1]=arr[i];
       }
       arr[pos-1]=num;
       n++;
    }
    printarray(arr,n);
    /*printf("new array:\n");
    for(int i=0;i<n;i++)
    {
        printf("%d\n",arr[i]);
    }*/
   
}
