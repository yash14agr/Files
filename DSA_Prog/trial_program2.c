
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int max = 1000000;

/* User-Defined Function Declaration*/
void best_case (int *, int);
void worst_case (int *, int);
void average_case (int *, int);
void almost_sorted (int *, int);
void copy (int *,int *, int);
void selection_sort (int *, int);
void insertion_sort (int *, int);
void bubble_sort (int *, int);
void shell_sort (int *, int);
void counting_sort (int *, int);
void traverse(int a[],int n);              
//void display (int *, int);
//void swap (int *, int *);


//  Driver Function
int main ()
{
  int key, choice, y, *a, n, *arr_copy;
  printf ("how many elements u want in array?\n");
  scanf ("%d",&n);
  a = (int *) calloc (n, sizeof (int));
  arr_copy = (int *) calloc (n, sizeof (int));
  srand(time(NULL));
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

      printf("Which sorting operation u want to be performed on the array?\n6-selection sort\n7-insertion sort\n8-shell sort\n9-counting sort\n10-bubble sort\n11-exit\n");
      scanf ("%d", &y);
      switch (y)
	{
	case 6:
	  selection_sort (arr_copy, n);
	  break;
	case 7:
	  insertion_sort (arr_copy, n);
	  break;
	case 8:
	  shell_sort (arr_copy, n);
	  break;
	case 9:
	  counting_sort (arr_copy, n);
	  break;
	  case 10:
	  bubble_sort(arr_copy, n);
	  break;
  	case 11:
  	  flag=1;
  	  break;
  	  
	default:
	  printf ("\nPlease Select only 6-11 option \n");
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

void selection_sort (int *arr_copy, int n)	//selection sort
{
  {

    clock_t t1, t2;
    float cpu_time_used = 0;
    t1 = clock ();
        int i, j, min_idx, temp;		//
    for (i = 0; i < n - 1; i++)
      { min_idx = i;
	for (j = i + 1; j < n; j++)
	  {
	    if (arr_copy[j] < arr_copy[min_idx])
	      {
		min_idx = j;
		temp = arr_copy[min_idx];
		arr_copy[min_idx] = arr_copy[i];
		arr_copy[i] = temp;
	      }
	  }
      }
    t2 = clock ();
    cpu_time_used = (double) (t2 - t1) / CLOCKS_PER_SEC;
    printf ("The elapsed time for selection sort is %f seconds\n", cpu_time_used);
    
  }
}

void insertion_sort(int *arr_copy, int n)	//insertion sort
{

  clock_t t1, t2;
  float cpu_time_used = 0;
  t1 = clock ();
    int i, key, j;
  for (i = 1; i < n; i++)
    {
      key = arr_copy[i];
      j = i - 1;


      while (j >= 0 && arr_copy[j] > key)
	{
	  arr_copy[j + 1] = arr_copy[j];
	  j = j - 1;
	}
      arr_copy[j + 1] = key;
    }
  t2 = clock ();
  cpu_time_used = (double) (t2 - t1) / CLOCKS_PER_SEC;
  printf ("The elapsed time for insertion sort is %f seconds\n", cpu_time_used);
}

void copy (int *arr_copy,int a[], int n)	    //copy
{

  for (int i = 0; i < n; i++)
    {
      a[i] = arr_copy[i];
    }
    
}


void bubble_sort (int *arr_copy, int n)
{

  clock_t t1, t2;
  float cpu_time_used = 0;
  t1 = clock ();
    int i, j;
  for (i = 0; i < n - 1; i++)
    {
      for (j = 0; j < n - i - 1; j++)
	{
	  if (arr_copy[j] > arr_copy[j + 1])
	    {
	      int temp = arr_copy[j];
	      arr_copy[j] = arr_copy[j + 1];
	      arr_copy[j + 1] = temp;
	    }
	}
    }
  t2 = clock ();
  cpu_time_used = (double) (t2 - t1) / CLOCKS_PER_SEC;
  printf ("The elapsed time for bubble sort is %f seconds\n", cpu_time_used);
}

void shell_sort (int *a, int n)

{   
  double t1=0.0;
	clock_t begin=clock(); 
    int i,j,gap,temp;
    for(gap=n/2;gap>=1;gap=gap/2)
    {
        for(j=gap;j<n;j++)
        {
            for(i=j-gap;i>=0;i=i-gap)
            {
                if(a[i+gap]>a[i])
                {
                    break;
                }
                else
                {
                    temp=a[i+gap];
                    a[i+gap]=a[i];
                    a[i]=temp;
                }
            }
        }
    }
    	clock_t end=clock();
    	t1+=(double)(end-begin)/CLOCKS_PER_SEC;
    	printf("\nThe elapsed time for shell sort is %f seconds\n", t1);
}
 
void counting_sort (int *a, int n)
{   


 double t1=0.0;
    clock_t begin=clock(); 
    int i, output[n];
   
  int maximum = a[0];		
  for (i = 1; i < n; i++) 
  {
    if (a[i] > maximum)
      maximum = a[i];
  }  
  int count[max];
  for (i = 0; i <= maximum; i++) 
  {
    count[i] = 0;
  }

  for (i = 0; i < n; i++) 
  {
    count[a[i]]++;
  }

  for (i = 1; i <= maximum; i++) 
  {
    count[i] += count[i - 1];
  }

  for (i = n - 1; i >= 0; i--) {
    output[count[a[i]] - 1] = a[i];
    count[a[i]]--;
  }
  copy(output,a,n);
  clock_t end=clock();
  t1+=(double)(end-begin)/CLOCKS_PER_SEC;
  printf("\nThe elapsed time for count sort is %f seconds\n", t1);
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
