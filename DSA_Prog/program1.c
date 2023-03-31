#include<stdio.h>
#include<stdlib.h>


int length_of_array(int a[]);       	
void create (int a[], int max, int n) ;
void print_array(int a[]);
void selection_sort (int a[]);
void bubble_sort (int a[]);
void linear_searching (int a[]);
void binary_searching (int a[]);
void insertion_sort(int a[],int max);
void delete_element(int a[]);
int is_full(int a[],int max);
int is_empty(int a[],int max);
void copy(int a[],int max);
void mergeNoSort(int a[],int max) ;
void mergeWithSort(int a[],int max);
void insertInArray(int val, int pos, int arr[],int max);

int main ()
{
  
  int i, j, n, x,max,z,y;
  int m, Choice;
  int sorted=0;
  int *a; 							//array a
  printf("enter array size:\n");
  scanf("%d",&max);                      			//max=array size
  printf ("enter number of elements in array:\n");
  scanf ("%d", &n); 						//n=no. of element
  a = (int *) calloc (max, sizeof (int));
  
  create (a, max, n);						
  
  
  
  while(1)
  {
  	printf ("enter 1 for sorting an array: \n");
  	printf ("enter 2 for searching an element in array:\n");
  	printf ("enter 3 for inserting an element in array:\n");
  	printf ("enter 4 to find length of array:\n");
  	printf ("enter 5 to deleted an element:\n");
  	printf ("enter 6 to check if array is empty:\n");
  	printf ("enter 7 to check if array is full:\n");
  	printf ("enter 8 to copy array to other array:\n");
  	printf ("enter 9 to merge 2 array:\n");
  	printf ("enter 10 to exit:\n");
  	scanf ("%d", &x);

  	switch (x)                                    //main switch case
  	{
    	case 1:
            	printf("enter 3 for sorting by selection sort and 4 for sorting by bubble sort\n");
            	scanf("%d",&y);
            	switch(y)
            	{
            	case 3:
               	selection_sort (a);
               	sorted=1;
               	break;
            	case 4:
                    	bubble_sort (a);
                    	sorted=1;
                    	break;
            	}
            	break;
    	case 2:
            	printf("enter 5 for searching by linear search and 6 for searching by binary search\n");
            	scanf("%d",&z);
            	switch(z)
            	{
            	case 5:
                    	linear_searching (a);
                    	break;
            	case 6:
                    	binary_searching (a);
                    	break;
            	}
            	break;
       case 3:
               insertion_sort(a,max);
               break;
       case 4:
               printf("length of array is:%d\n",length_of_array(a));
               break;
       case 5:
               delete_element(a);
               break;        
       
       case 6:
               if(is_empty(a,max)==1)
               {
                    printf("array is empty\n");
               }
               else
               {
                    printf("array is not empty\n");
               }
               break;
       case 7:   
               if(is_full(a,max)==1)
               {
                    printf("array is full\n");
               }
                else
               {
                    printf("array is not full\n");
               }
               break;
       case 8:
               copy(a,max);
               break;
       case 9:
                printf("Enter 0 to merge without sort and 1 to merge with sort.\n");
                scanf("%d", &Choice);
                switch(Choice) {
                    case 0: 
                        mergeNoSort(a,max);
                        break;
                    case 1:
                        if(sorted == 1) mergeWithSort(a,max);
                        else printf("Please sort the 1st array first.\n");
                        break;
                    default:
                        printf("Invalid Choice.\n");
                }

                break;
        
       case 10:                          //exit case
           	exit(0);
    
  	} 
  	printf("\n\n\n\n\n");
  }
  
  
}



int length_of_array(int a[])       	//length of array
{
    int count=0;
    int*p=a;
     while(*p != -99)
     {
         count++;
         p++;
     }
    return count;
}







void create (int a[], int max, int n)        //creation of array
{
  int i;
  a[0]=-99;
  if(n>=max)
    {
      printf("array element exceeds array size.");
    }
  else
  {
     printf ("enter %d elements", n);
     for (i = 0; i < n; i++)
      	{
      	    a[i+1]=a[i];
      	    scanf ("%d", &a[i]);
    	}
  }
  n+=1;
  //print_array(a);
}



void print_array(int a[])            //printing of array
{
    int i;
    int n=length_of_array(a);
    printf("element of array are:\n");
    for(i=0;i<n;i++)
    {
        //printf("%p\n",a);
        printf("%d ",*a);
        a++;
    }
    printf("\n");
    
}




void selection_sort (int a[])     //selection sort            
{
  int i, k, j, temp;
  int n=length_of_array(a);

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
      temp = a[i];
      a[i] = a[k];
      a[k] = temp;

    }
    //printf("");
    print_array(a);
}


void bubble_sort (int a[])        //bubble sort
{
    int i,j,temp;
    int n=length_of_array(a);
    for(i=0;i<n-1;i++)
    {                                     
        for(j=0;j<n-i-1;j++)
        {
            if(a[j]>a[j+1])
            {
                temp = a[j];
                a[j] = a[j+1];
                a[j+1] = temp;
            }
        }
    }
    print_array(a);
}


void linear_searching (int a[])		//linear searching
{
    int i,j,ele,flag=0;
    int n=length_of_array(a);
    printf("enter the element you want to search:\n");
    scanf("%d",&ele);
    
    for(i=0;i<n;i++)
    {
        if(a[i]==ele)
        {
            printf("%d is found at %dth index\n",ele,i);
            flag=1;
            break;
        }
    }
    if(flag==0)
    {
        printf("%d is not found in given array\n",ele);
    }

}


void binary_searching (int a[])		//binary searching
{
    int i,j,flag=0,num;
    int n=length_of_array(a);
    printf("enter the element you want to search:\n");
    scanf("%d",&num);
    selection_sort (a);
    int l=0,u,mid;
    u=n-1;
    
    while(l<=u)
    {
        mid=(l+u)/2;
        if(a[mid]==num)
        {
            printf("%d is found at %dth index\n",num,mid);
            flag=1;
            break;
        }
        if(a[mid]>num)
        {
            u=mid-1;
        }
        if(a[mid]<num)
        {
            l=mid+1;
        }
    }
    if(flag==0)
    printf("%d is not found in the given array\n",num);
  
}



void insertion_sort(int a[],int max)		//insertion
{
    int back,val,pos;
    int n=length_of_array(a);
    back=n;
    printf("enter the element you want to insert and its index\n");
    scanf("%d%d",&val,&pos);
    
    if(pos>=n || n>max-1)
      {
          printf("insertion not possible\n");
      }
    else
      {
           while(back>=pos)
           {
              a[back+1]=a[back];
              back--;
           }
           a[pos]=val;
           n+=1;
      }
      
      print_array(a);

}


void delete_element(int a[])		//deletion
{
   int pos;
   int n=length_of_array(a);
   printf("enter the position of element you want to delete\n");
   scanf("%d",&pos);
   int back=pos;
   if(pos>n-1 || n==0)
   {
       printf("deletion not possible\n");
    
   }
   else
   {
       while(back<n)
       {
           a[back]=a[back+1];
           back++;
       }
   }
   print_array(a);
}



int is_full(int a[],int max)			//is full
{
    int check=length_of_array(a);
    if(check==max-1)
        return 1;
    else
        return 0;
}


int is_empty(int a[],int max)			//is empty
{
    int check=length_of_array(a);
    if(check==0)
        return 1;
    else
        return 0;
}




void copy(int a[],int max)			//copy
{
    int*b;            
    int i; 
    int n=length_of_array(a);       			
    b = (int *) calloc (max, sizeof (int));
    for(i=0;i<n;i++)
    {
        b[i]=a[i];
    }
    printf("copied array:\n");
    for(i=0;i<n;i++)
    {
        printf("%d ",b[i]);
    }
    
}




void mergeNoSort(int a[],int max)		//merging without sorting
{
    int n = length_of_array(a), m;
    printf("Enter the number of elements in the array: ");
    scanf("%d",&m);
    if(m+n> max) {
        printf("number of elements exceeds array size.\n");
        return;
    }
    int* b;
    b = (int *) calloc (m,sizeof(int));
    create (b,max, m);
    for(int i = 0; i < m; i++) {
        a[n+i+1] = a[n+i];
        a[n+i] = b[i];
    }
    print_array(a);
}


void mergeWithSort(int a[],int max) 		//merging with sorting
{
    int n = length_of_array(a), m;
    printf("Enter the number of elements in the array: ");
    scanf("%d",&m);
    if(m+n> max) {
        printf("number of elements exceeds array size.\n");
        return;
    }
    int* b;
    b = (int *) calloc (m,sizeof(int));
    create (b,max, m);
    int i,j;
    for(i=0; i<m; i++) {
        n = length_of_array(a);
        for(j=0; j <= n; j++) 
        {
            if(b[i]<a[j]) 
               {
                insertInArray(b[i], j, a, max);
                break;
               }
            if(j == n) 
            	{
                a[j+1] = a[j];
                a[j] = b[i];
           	}
        }
    }
    print_array(a);
}



void insertInArray(int val, int pos, int arr[],int max)		//insertion
 {
    int n = length_of_array(arr);
	if(pos>n || is_full(arr,max) == 1)
		printf("Not possible to insert\n");
	else {
		int back = n;
		while (back >= pos) {
			arr[back+1] = arr[back];
			back--;
		}
		arr[pos] = val;
	}
}

