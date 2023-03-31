#include<stdio.h>
#include<stdlib.h>
#include<time.h>
//int max = 1000000;

/* User-Defined Function Declaration*/
void best_case (int *, int);
void worst_case (int *, int);
void average_case (int *, int);
void almost_sorted (int *, int);
void copy (int *,int *, int);
void merge_sort (int *, int, int);
void quick_sort (int *, int, int);
int partition (int arr_copy[],int low, int high) ;
void traverse(int a[],int n);   
void merge(int arr_copy[], int l, int m, int r);
//void display (int *, int);
void swap(int* a, int* b) ;


//  Driver Function
int main ()
{
  int key, choice, y, *a, n, *arr_copy;
  printf ("how many elements u want in array?\n");
  scanf ("%d",&n);
  a = (int *) calloc (n, sizeof (int));
  arr_copy = (int *) calloc (n, sizeof (int));
  srand(time(NULL));
  int l=0,r=n-1;
  while (1)
    {
    int flag=0;
      printf("Select List : 1.Best\n 2.Worst\n 3.Almost Sorted\n 4.Random(average)\n5.exit\n ");
      scanf ("%d", &choice);
      switch (choice)
	{
	case 1:
	  best_case (arr_copy, n);	//for best case
	  break;

	case 2:
	  worst_case (arr_copy, n);	//for worst case
	  break;

	case 3:
	  almost_sorted (arr_copy, n);	
	  break;

	case 4:
	  average_case (arr_copy, n);	// random order
	  break;

	case 5:
	  exit (0);
	  break;
	}
    traverse(arr_copy,n);
    
  while (1)
    {
        copy(arr_copy,a,n);

      printf("Which sorting operation u want to be performed on the array?\n6-merge sort\n7-quick sort\n8-exit");
      scanf ("%d", &y);
      switch (y)
	{
	case 6:
	  merge_sort (arr_copy,l,r);
	  traverse(arr_copy,r+1);
	  break;
	case 7:
	  quick_sort (arr_copy,l,r);
	  	  traverse(arr_copy,r+1);
	  break;
  	case 8:
  	  flag=1;
  	  break;
  	  
	default:
	  printf ("\nPlease Select only 6-8 option \n");
	}
	    //traverse(arr_copy,n);
	    if(flag==1)
	    {
	    break;
	    }
    }

}
  return 0;
}

//individual function definition begins

void merge_sort (int *arr_copy,int l,int r)	//merge sort
{


    clock_t t1, t2;
    float cpu_time_used = 0;
    t1 = clock ();
      
     if (l < r)
     {
        int m = l + (r - l) / 2;
        merge_sort(arr_copy, l, m);
        merge_sort(arr_copy, m + 1, r);
        merge(arr_copy, l, m, r);
    } 
       
    t2 = clock ();
    cpu_time_used = (double) (t2 - t1) / CLOCKS_PER_SEC;
    printf ("The elapsed time for merge sort is %f seconds\n", cpu_time_used);
    
  
}

void swap(int* a, int* b) 
{ 
    int t = *a; 
    *a = *b; 
    *b = t; 
}

void merge(int arr_copy[], int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;
    int L[n1], R[n2];
    
    for (i = 0; i < n1; i++)
        L[i] = arr_copy[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr_copy[m + 1 + j];
  
    i = 0; 
    j = 0; 
    k = l; 
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            arr_copy[k] = L[i];
            i++;
        }
        else {
            arr_copy[k] = R[j];
            j++;
        }
        k++;
    }
    while (i < n1)
    {
        arr_copy[k] = L[i];
        i++;
        k++;
    }
     while (j < n2) 
     {
        arr_copy[k] = R[j];
        j++;
        k++;
    }
}
  

void quick_sort(int *arr_copy, int low, int high)	
{

  clock_t t1, t2;
  float cpu_time_used = 0;
  t1 = clock ();
  
  if (low < high) 
    {
        int pi = partition(arr_copy, low, high); 
        quick_sort(arr_copy, low, pi - 1); 
        quick_sort(arr_copy, pi + 1, high); 
    } 
    
  t2 = clock ();
  cpu_time_used = (double) (t2 - t1) / CLOCKS_PER_SEC;
  printf ("The elapsed time for quick sort is %f seconds\n", cpu_time_used);
}

int partition (int arr_copy[], int low, int high) 
{ 
    int pivot = arr_copy[high]; 
    int i = (low - 1); 
  
    for (int j = low; j <= high - 1; j++) 
    { 
        
        if (arr_copy[j] < pivot) 
        { 
            i++; 
            swap(&arr_copy[i], &arr_copy[j]); 
        } 
    } 
    swap(&arr_copy[i + 1], &arr_copy[high]); 
    return (i + 1); 
} 


void copy (int *arr_copy,int a[], int n)	    //copy
{

  for (int i = 0; i < n; i++)
    {
      a[i] = arr_copy[i];
    }
    
}

void best_case (int *arr_copy, int n)
{  int i=0;
    int k=rand()%100;
    for(; i<n; i++)
    {
        arr_copy[i]=k;
        k++;
    }
}

void worst_case (int *arr_copy, int n)
{
   int i=0;
    int k=rand()%100;
    for(; i<n; i++)
    {
        arr_copy[i]=k;
        k--;
    }
   
}


void average_case (int *arr_copy, int n)
{   int i=0;
     int k;
     for(; i<n; i++)
     {
         k=rand()%100;
         arr_copy[i]=k;
     }
}
void almost_sorted (int *arr_copy, int n)		
{  
      int i=0, l=0;
      int k= rand()%100;		 		
      int gap= n/5;			
      for (; i<n; i++)
      {
          arr_copy[i]= k; 
          k++;
      }
      k=rand()%100;  	
      while(l<n)
      {
          arr_copy[l]= k;
          l=l+gap;
      }
    
}

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
