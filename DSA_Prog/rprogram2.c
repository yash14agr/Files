#include<stdio.h>
#include<stdlib.h>
#include<time.h>
void best_case (int *, int);
void worst_case (int *, int);
void average_case (int *, int);
void almost_sorted (int *, int);
int *copy (int *, int);
void selection_sort (int *, int);
void insertion_sort (int *, int);
void bubble_sort (int *, int);
void shell_sort (int *, int);
void counting_sort (int *, int);

int main ()
{
  int key, choice1, choice2, *a, n, *arr_copy;
  printf ("how many elements u want in array?");
  scanf ("%d",&n);
  a = (int *) calloc (n, sizeof (int));

  while (1)
    {
      printf("Select List : 1.Best\n 2.Worst\n 3.Almost Sorted\n 4.Random(average)\n5.exit\n ");
      scanf ("%d", &choice1);
      switch (choice1)
	{
	case 1:
	  best_case (arr_copy, n);	//for best case
	  break;

	case 2:
	  worst_case (arr_copy, n);	//for worst case
	  break;

	case 3:
	  almost_sorted (arr_copy, n);	//average case
	  break;

	case 4:
	  average_case (arr_copy, n);	// increasing  order  with the  Nth  element out of order
	  break;

	case 5:
	  exit (0);
	  break;
	}
    
    
  while (1)
    {
      printf("Which sorting operation u want to be performed on the array?\n6-selection sort\n7-insertion sort\n8-shell sort\n9-counting sort\n10-bubble sort");
      scanf ("%d", &choice2);
      switch (choice2)
	{ 
	    arr_copy = copy (a, n);
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
	  bubble_sort(arr_copy,n);
	  break;
	default:
	  printf ("\nPlease Select only 6-10 option \n");
	}
    }
  return 0;
}
}
//individual function definition begins

void selection_sort (int *arr_copy, int n)	//selection sort
{
  {
    int i, j, min_idx, temp;
    clock_t t1, t2;
    float cpu_time_used = 0;
    t1 = clock ();
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
      /*for(int i=0;i<n;i++)
{
printf("%d ",arr_copy[i]);
}*/
    t2 = clock ();
    cpu_time_used = (double) (t2 - t1) / CLOCKS_PER_SEC;
    printf ("%f", cpu_time_used);
  }
}

void insertion_sort(int *arr_copy, int n)	//insertion sort
{
  int i, key, j;
  clock_t t1, t2;
  float cpu_time_used = 0;
  t1 = clock ();
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
  printf ("%f", cpu_time_used);
}

int * copy (int *arr_copy, int n)	    //copy
{
  int *b;
  b = (int *) calloc (n, sizeof (int));
  for (int i = 0; i < n; i++)
    {
      b[i] = arr_copy[i];
    }
  return b;
}


void bubble_sort (int *arr_copy, int n)
{
  int i, j;
  clock_t t1, t2;
  float cpu_time_used = 0;
  t1 = clock ();
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
  printf ("%f", cpu_time_used);
}

void shell_sort (int *arr_copy, int n)

{   
  int j,temp,i,gap;
  clock_t t1, t2;
  float cpu_time_used = 0;
  t1 = clock ();
  for ( gap = n / 2; gap > 0; gap /= 2)
    {
      for ( i = gap; i < n; i += 1)
	    {
            temp = arr_copy[i];
	    }
	
	           
            for (j = i; j >= gap && arr_copy[j - gap] > temp; j -= gap)
               {
                   arr_copy[j] = arr_copy[j - gap];
                   arr_copy[j] = temp;
                }
    }
    t2 = clock ();
  cpu_time_used = (double) (t2 - t1) / CLOCKS_PER_SEC;
  printf ("%f", cpu_time_used);
   
}
 
void counting_sort (int *arr_copy, int n)
{   
  int output[n];
  int max = arr_copy[0];
  clock_t t1, t2;
  float cpu_time_used = 0;
  t1 = clock ();
  for (int i = 1; i < n; i++) 
  {
    if (arr_copy[i] > max)
      max = arr_copy[i];
  }
  int count[n];
  for (int i = 0; i <= max; ++i) 
  {
    count[i] = 0;
  }
  for (int i = 0; i < n; i++)
  {
    count[arr_copy[i]]++;
  }
  for (int i = 1; i <= max; i++) 
  {
    count[i] += count[i - 1];
  }
  for (int i = n - 1; i >= 0; i--)
  {
    output[count[arr_copy[i]] - 1] = arr_copy[i];
    count[arr_copy[i]]--;
  }
 for (int i = 0; i < n; i++)
  {
    arr_copy[i] = output[i];
  }
  t2 = clock ();
  cpu_time_used = (double) (t2 - t1) / CLOCKS_PER_SEC;
  printf ("%f", cpu_time_used);
}


void best_case (int *arr_copy, int n)
{   
   for(int i = 0; i<n; i++)
       {
           arr_copy[i]=i+1;
       }
}

void worst_case (int *arr_copy, int n)
{for(int i = 0; i>n; i--)
        {
           arr_copy[i]=i--;
       }
}

void average_case (int *arr_copy, int n)
{   for(int i = 0; i<n; i++)
        printf(" %d ", rand());
}
void almost_sorted (int *arr_copy, int n)
{
    
    for(int i = 0; i<n; i++)
     {
         arr_copy[i]=rand()%10000;  
           //printf(" %d ", rand());
}

}
