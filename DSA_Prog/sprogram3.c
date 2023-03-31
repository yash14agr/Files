#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define MAX 1000000

int traverse(int *a, int n);
void bestcase(int *a,int n);
void averagecase(int *a,int n);
void worstcase(int *a,int n);
void copy(int *a,int *b, int n);
int partition_best(int *a, int low, int high);
void quicksort_best(int *a, int low, int high);
int partition_worst(int *a, int low, int high);
void quicksort_worst(int *a, int low, int high);
void merge(int *a, int low, int mid, int high);
void mergesort(int *a, int low, int high);

int main()
{

    int *a,*b,input,option,n;
    clock_t begin,end;
    double time_spent=0.0;
    a=(int*)calloc(MAX,sizeof(int));
    b=(int*)calloc(MAX,sizeof(int));

    srand(time(NULL));
    do{
        printf("\nenter array length in multiples of 10: ");
        scanf("%d",&n);
        if(n%10!=0)
        printf("invalid length\n");
    }while(n%10!=0);
    
    while(1)
    {
        int original=0,flag=1;
        printf("Select the type of input:\n1.Best case\n2.Worst case\n3.Average case\n4.exit\n");
        scanf("%d",&input);
        switch (input)
        { 
            case 1:    
            	bestcase(a,n);       
            	break;
            case 2: 
                flag=0;
        		worstcase(a,n);     
        		break;
        	case 3:
                averagecase(a,n);      
            	break;
        	case 4:
        		exit(0);
            default:
                printf("\ninvalid option.\n");
        }
        copy(a,b,n);
        while(1)
        {
            printf("Select the type of sorting:\n1.Quick sort\n2.Merge sort\n3.exit\n");
            scanf("%d",&option);
            switch(option)
            {
                case 1:
                   if(flag==0)
                   {
                      begin=clock();
                      quicksort_worst(a,0,n-1);
                      end=clock();
                      time_spent=(double)(end-begin)/CLOCKS_PER_SEC; 
                      printf("\ntime required to quick sort is--> %lf sec\n", time_spent); 
                      copy(a,b,n);
                   }
                   else
                   {
                      begin=clock();
                      quicksort_best(a,0,n-1);
                      end=clock();
                      time_spent=(double)(end-begin)/CLOCKS_PER_SEC; 
                      printf("\ntime required to quick sort is--> %lf sec\n", time_spent); 
                      copy(a,b,n);
                   }
                   break;

                case 2:
                   begin=clock();
                   mergesort(a,0,n-1);
                   end=clock(); 
                   time_spent=(double)(end-begin)/CLOCKS_PER_SEC; 
                   printf("\ntime required to merge sort is--> %lf sec\n", time_spent); 
                   copy(a,b,n);
                   break;

                case 3:
                   break;

                default:
                   printf("\ninvalid option.\n");
            }
            if(option==3)
            break;
        }
        printf("Enter 1 to print original array\n");
        scanf("%d",&original);
        if(original==1)
        {
            printf("original \n");
        }
    }
    printf("\n\n\n");
    return 0;
}

int traverse(int a[], int n)      
{
    for(int i=0;i<n;i++)
    {
        printf("%d ",a[i]);
    }
}
void bestcase(int a[],int n)      
{  
    int i=0;
    int k=rand()%100;
    for(; i<n; i++)
    {
       a[i]=k;
       k++;
    }
}
void averagecase(int a[],int n)
{  
    int i=0;
    for(;i<n;i++){
        int k=rand()%100;
        a[i]=k;
    }
}
void worstcase(int a[],int n)
{  
   int i=0;
   int k=rand()%100;
   for(;i<n;i++)
   {
     a[i]=k;
     k--;
   }
}
void copy(int a[],int b[], int n)
{
    for(int i=0;i<n;i++)
    {
        b[i]=a[i];
    }
}
void mergesort(int a[], int low, int high)
{
    if(low<high)
    {
        int mid=(low+high)/2;
        mergesort(a,low,mid);
        mergesort(a,mid+1,high);
        merge(a,low,mid,high);
    }
}
void merge(int a[], int low, int mid, int high)
{
    int i,j,k;
    int *b;
    b=(int*)calloc(MAX,sizeof(int));
    i=low;
    j=mid+1;
    k=low;
    while(i<=mid && j<=high)
    {
        if(a[i]>a[j])
        {
            b[k]=a[j];
            j++;
            k++;
        }
        else
        {
            b[k]=a[i];
            i++;
            k++;
        }
    }
    while(i<=mid)
    {
        b[k]=a[i];
        i++;
        k++;
    }
    while(j<=high)
    {
        b[k]=a[j];
        j++;
        k++;
    }
    for(int k=low;k<=high;k++)
    {
        a[k]=b[k];
    }
}
void quicksort_worst(int a[], int low, int high)
{
    int partitionindex;
    if(low<high)
    {   
        partitionindex=partition_worst(a,low,high);
        quicksort_worst(a,low,partitionindex-1);
        quicksort_worst(a,partitionindex+1,high);
    }
}
int partition_worst(int a[], int low, int high)
{
    int pivot=a[low];
    int i,j;
    i=low+1;
    j=high;
    int temp;
    while(i<j)
    {
        while(a[i]<=pivot)
        {i++;}
        while(a[j]>=pivot)
        {j--;}
        if(i<j)
        {
            temp=a[i];
            a[i]=a[j];
            a[j]=temp;
        }
    }
    temp=a[low];
    a[low]=a[j];
    a[j]=temp;
    return j;

}
void quicksort_best(int a[], int low, int high)
{
    int partitionindex;
    if(low<high)
    {
        partitionindex=partition_best(a,low,high);
        quicksort_best(a,low,partitionindex-1);
        quicksort_best(a,partitionindex+1,high);
    }
}
int partition_best(int a[],int low, int high)
{
    int mid=(low+high)/2;
    int pivot=a[mid];
    int i=low;
    int j=high;
    int temp;
    while(i<j)
    {
        while(a[i]<=pivot)
        {
            i++;
        }
        while(a[j]>pivot)
        {
            j--;
        }
        if(i<j)
        {
            temp=a[i];
            a[i]=a[j];
            a[j]=temp;
        }
    }
    temp=a[mid];
    a[mid]=a[j];
    a[j]=temp;
    return mid;
}
