#include<stdio.h> 
#include<stdlib.h>
#include<time.h>
int max = 1000000;

/* User-Defined Function Declaration*/
int ascending_list(int *a,int n);
void descending_list(int a[],int n); 
void average(int *,int n);
void almost_sorted(int *,int n);
void selection_sort (int a[],int n);  
void insertion_sort(int *,int n); 
void shell_sort(int *,int n); 
void count_sort(int *,int n);
int length(int *);   
void traverse(int a[],int n);
void copy(int a[],int b[],int n);
void bubble_sort (int a[],int n);
void best_counting(int a[],int n);
void worst_counting(int a[],int n);

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

while(1)			//1st while loop
{ 
int original=0;
	printf("Select List : 1.Ascending\n 2.Descending\n 3.average \n 4.almost_sorted\n5.best case for counting\n6.worst case for counting\n7.exit\n"); 
        scanf("%d",&option1); 

        switch (option1)		//switch case for input
        	{ 
            	case 1:    
            		ascending_list(a,n);       //for best case
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
		 	best_counting(a,n);
		 	break;
		case 6:
			worst_counting(a,n);
			break;                        
            	case 7:
            		exit(0);

            		
            		
            	default:
                       printf("\ninvalid option.\n");
        	}

	copy(a,b,n);			//coping original array

	while(1)			//2nd while loop
   	{
       	printf("Which sorting operation u want to perform on the array?\n1-selection sort\n2-bubble sort\n3-insertion sort\n4-shell sort\n5-counting sort\n6-exit\n");
    	 	scanf("%d",&option2);
               switch(option2)		//switch case for sorting
               {   
                   case 1:
                          selection_sort(a,n);
                          break;
                          
                   case 2:
                   	   bubble_sort(a,n);
                   	   break;       
                   case 3:
                          insertion_sort(a,n);
                          break;
                   case 4:
                          shell_sort(a,n);
                          break;
                   case 5:
                          count_sort(a,n);
                          break;
                   case 6:
                          break;
                   default:
                      printf("\ninvalid option.\n");
                }
                if(option2==6)
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


void selection_sort (int a[],int n)     //selection sort            
{	
  double time_spent=0.0;
  clock_t begin = clock();						
  int i, k, j, key;	
  for (i = 0; i < n; i++)		
  {
      k = i;									
      for (j = i + 1; j < n; j++)		
     {									
          if (a[k] > a[j])		
          {   								
              k = j;				
          }
     }
 
      key = a[i];							
      a[i] = a[k];			
      a[k] = key;			
					
  }
    clock_t end = clock();
    time_spent += (double)(end - begin) / CLOCKS_PER_SEC;
    printf("\nThe elapsed time for selection sort is %f seconds\n", time_spent);
    //traverse(a,n);
}



void bubble_sort (int a[],int n)        //bubble sort
{	
    double time_spent=0.0;
    clock_t begin = clock();						
    int i,j,key;
    //int n=length(a);
   
    for(i=0;i<n-1;i++)	//i=0,3			
    {                                    		
        for(j=0;j<n-i-1;j++)
        {						
            if(a[j]>a[j+1])				
            {
                key = a[j];
                a[j] = a[j+1];
                a[j+1] = key;
            }
        }
    }
    clock_t end = clock();
    time_spent += (double)(end - begin) / CLOCKS_PER_SEC;
    printf("\nThe elapsed time for bubble sort is %f seconds\n", time_spent);
     //traverse(a,n);
}


   void insertion_sort(int arr[],int n)          //insertion sort
{
    double time_spent=0.0;
    clock_t begin = clock();
    int i, key, j;
    //int n=length(arr);
    for (i = 1; i < n; i++)
     {
        key = arr[i];
        j = i - 1;
 
   
        while (j >= 0 && arr[j] > key)
         {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
    clock_t end = clock();
    time_spent += (double)(end - begin) / CLOCKS_PER_SEC;
    printf("\nThe elapsed time for insertion sort is %f seconds\n", time_spent);
    //traverse(arr,n);
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
 
void copy(int a[],int b[],int n)	    //copy
{
    int i; 
    for(i=0;i<n;i++)
    {
        b[i]=a[i];
    }
   
    
}


void shell_sort(int a[],int n)	     //shell sort
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
        //traverse(a,n);
}

    

void count_sort(int *a,int n)	    //count sort
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
  int count[maximum];
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
  
  //traverse(a,n);
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
   // traverse(a,n);
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
      //  traverse(a,n);
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
      //   traverse(a,n);
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
         // traverse(a,n);
}

void best_counting(int a[],int n)
{
	int i=0;
    int k=rand()%10;
    for(; i<n; i++)
    {
        a[i]=k;
    }
}

void worst_counting(int a[],int n)
{
	int i=0;
    int k=rand()%100;
    for(; i<n; i++)
    {
        a[i]=k;
        k++;
    }
    a[n-1]=rand()%1000000;
    //traverse(a,n);
}

/*
	        Selection	 Bubble	Insertion	 Shell	        Count	    
Ascending	12.430620	12.639288	0.000455	0.004789	0.003654	
Descending	12.599911	21.868769	14.517832	0.008397	0.003050	
Average	12.512500	32.446032	7.408817	0.469641	0.002056
Almost Sorted	12.962236	13.043283	0.002338	0.013345	0.007797


time required for selection is same for every case.
for best case and almost sorted case, insertion sort required less time.
for worst case and average, count sort required less time.
*/
