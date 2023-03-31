#include<stdio.h> 
#include<stdlib.h>
#include<time.h>
int max = 1000000;

/* User-Defined Function Declaration*/
int ascending_list(int *a,int n);
void descending_list(int a[],int n); 
void average(int *,int n);
void almost_sorted(int *,int n);
void traverse(int a[],int n);
void copy(int a[],int b[],int n);
void merge_sort(int arr[], int l, int r);
void merge(int arr[], int l, int m, int r);
void swap(int* a, int* b) ;
void quickSortBest(int A[], int lb, int ub);
void quickSortWorst(int A[], int lb, int ub);
int partitionBest(int a[], int lb, int ub);
int partitionWorst(int a[], int lb, int ub);

//  Main
int main()
{ 
int key,option1,option2,min,y,n; 
time_t t1,t2; 
int *a = (int *) calloc (max, sizeof (int));
int *b = (int *) calloc (max, sizeof (int));
srand(time(NULL));
do
{
        printf("enter array length in multiple of 10:\n");
        scanf("%d",&n);
        if(n%10!=0)
        printf("Invalid length.\n");
}while(n%10 != 0);
int l=0,r=n-1,z=0;
double time_spent=0.0;
clock_t begin;
clock_t end;
while(1)			//1st while loop
{ 
int original=0;
	printf("Select List : 1.best\n 2.worst\n 3.average \n 4.almost_sorted\n5.exit\n"); 
        scanf("%d",&option1); 

        switch (option1)		//switch case for input
        	{ 
            	case 1:    
            		ascending_list(a,n);       //for best case
            		z=1;
            		break;
            
            	case 2: 
            		descending_list(a,n);     //for worst case
            		break;
            
            	case 3: 
            		average(a,n);            //average case
            		break;
            
            	case 4:
            		almost_sorted(a,n);      // increasing  order  with the  Nth  element out of order
            		break;

            	case 5:
            		exit(0);
            	default:
                       printf("\ninvalid option.\n");
        	}

	copy(a,b,n);			//coping original array

	while(1)			//2nd while loop
   	{
       	printf("Which sorting operation u want to perform on the array?\n1-merge sort\n2-quick sort\n3-exit\n");
    	 	scanf("%d",&option2);
               switch(option2)		//switch case for sorting
               {   
                  
                   case 1:

   			  begin = clock();
                   	  
                   	  merge_sort(a,l,r);
                   	  
                   	  end = clock();
   		          time_spent = (double)(end - begin) / CLOCKS_PER_SEC;   	
    			   printf("\nThe elapsed time for merge sort is %f seconds\n", time_spent);

                   	   //traverse(a,r+1);
                   	   break;                   	   
                   case 2:
                   	   //double time_spent=0.0;
                   	   if(z==1)
                   	   {
   			   begin = clock();
   			   
                   	   quickSortBest(a,l,r);
                   	   
                   	   end = clock();
   		           time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
    			   printf("\nThe elapsed time for quick sort is %f seconds\n", time_spent);
                   	   }
                   	   else
                   	   {
                   	   begin = clock();
   			   
                   	   quickSortWorst(a,l,r);
                   	   
                   	   end = clock();
   		           time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
    			   printf("\nThe elapsed time for quick sort is %f seconds\n", time_spent);
                   	   }
                   	   //traverse(a,r+1);
                          break;
                   case 3:
                          break;
                   default:
                      printf("\ninvalid option.\n");
                }
                if(option2==3)
                break;
        }
	printf("press 1 to print orignal array.\n");
	scanf("%d",&original);
	if(original==1)
	{
	printf("original ");
	traverse(b,n);
	}
  }
  
  printf("\n\n\n");
return 0;
}
    
    
    
 //individual function calling begins

   

void traverse(int a[],int n)              //traverse
 {
     int i;
     printf("array: ");
     for(i=0; i<n;i++)
     {
         printf("%d ",a[i]);
     }
     printf("\n\n\n");
 }
 
void copy(int a[],int b[],int n)	    //copy
{
    int i; 
    for(i=0;i<n;i++)
    {
        b[i]=a[i];
    }
   
    
}


void merge(int arr[], int l, int m, int r)		//merge
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;
  
    int L[n1], R[n2];
    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];
  

    i = 0; 
    j = 0;
    k = l; 
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        }
        else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
  
    
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }
  
    
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}
  

void merge_sort(int arr[], int l, int r)		//merge sort
{	
    	

    if (l < r)
    {
    
        int m = (r + l) / 2;
        merge_sort(arr, l, m);
        merge_sort(arr, m + 1, r);
  
        merge(arr, l, m, r);
	
    }
    
}

/*void quick_sort(int arr[], int low, int high)		//quick sort
{
	if (low < high) 
    { 
        int pi = partition(arr, low, high); 
        quick_sort(arr, low, pi - 1); 
        quick_sort(arr, pi + 1, high); 
    }
}
	

int partition (int arr[], int low, int high) 		//partitioning
{ 
    int pivot = arr[high];  
    int i = (low - 1); 
  
    for (int j = low; j <= high - 1; j++) 
    { 

        if (arr[j] < pivot) 
        { 
            i++; 
            swap(&arr[i], &arr[j]); 
            
        } 
    } 
    swap(&arr[i + 1], &arr[high]); 
    return (i + 1); 
} */

void swap(int* a, int* b) 		//swap
{ 
    int t = *a; 
    *a = *b; 
    *b = t; 
} 


void quickSortWorst(int A[], int lb, int ub)
{
	int loc;
	if (lb < ub)
	{
		loc = partitionWorst(A, lb, ub);
		quickSortWorst(A, lb, loc-1);
	quickSortWorst(A, loc+1, ub);
	}
}
int partitionWorst(int a[], int lb, int ub)
{
	int pivot = a[lb];
	int start = lb;
	int end = ub;
	int temp;
	while (start < end)
	{
		while (a[start] <= pivot)
		{
			start++;
		}
		while (a[end] > pivot)
		{
			end--;
		}
		if(start < end)
		{
	temp = a[start];
	a[start] = a[end];
	a[end] = temp;
	}
}
	temp = a[lb];
	a[lb] = a[end];
	a[end] = temp;
return end;
}
void quickSortBest(int A[], int lb, int ub)
{
	int loc;
	if (lb < ub)
	{
		loc = partitionBest(A, lb, ub);
		quickSortBest(A, lb, loc-1);
		quickSortBest(A, loc+1, ub);
	}
}
int partitionBest(int a[], int lb, int ub)
{
	int mid = (lb+ub)/2;
	int pivot = a[mid];
	int start = lb;
	int end = ub;
	int temp;
	while (start < end)
	{
		while (a[start] <= pivot)
		{
			start++;
		}
		while (a[end] > pivot)
		{
			end--;
		}
		if(start < end)
		{
			temp = a[start];
			a[start] = a[end];
			a[end] = temp;
		}
	}
	temp = a[mid];
	a[mid] = a[end];
	a[end] = temp;
return mid;
}



int ascending_list(int a[],int n)       //for best case
{
    int i=0;
    int k=rand()%100;
    for(; i<n; i++)
    {
        a[i]=k;
        k++;
    }
    //traverse(a,n);
}


void descending_list(int a[],int n)      //for worst case
{    
    int i=0;
    int k=rand()%100;
    for(; i<n; i++)
    {
        a[i]=k;
        k--;
    }
        //traverse(a,n);
}

void average(int a[],int n)                //average case
{
     int i=0;
     int k;
     for(; i<n; i++)
     {
         k=rand()%100;
         a[i]=k;
     }
         //traverse(a,n);
}

void almost_sorted(int a[],int n)          // increasing  order  with the  Nth  element out of order
{
      int i=0, l=0;
      int k= rand()%100;
      int gap= n/5;
      for (; i<n; i++)
      {
          a[i]= k; 
          k++;
      }
      k=rand()%100;
      while(l<n)
      {
          a[l]= k;
          l=l+gap;
      }
          //traverse(a,n);
}


