#include<stdio.h>
#include<stdlib.h>



void create (int *a, int n);			//a= 1 2 3 4 5
void print(int *a,int n);
int length(int*);
void selection_sort (int *a);
void bubble_sort (int *a);
void linear_search (int *a);
void binary_search (int *a);
void insertion(int,int,int*);
void deletion(int,int*);
int isEmpty(int a[]);
int isFull(int a[]);
void copy(int *a);
void traverse(int a[]);
void mergeNoSort(int a[]);		
void mergeWithSort(int a[]);	
void insertInArray(int val, int pos, int arr[]);	


#define MAX 8



int main ()
{   int n,x,y,z,key,pos, posi, posd,value,Choice,sorted=0;
    int *a, *b;
    printf ("How many number of elements in array?:\n");
    scanf ("%d", &n);
    //printf("Enter those elements: ");
    //scanf("%s", a);  
    a = (int *) calloc (MAX, sizeof (int));
    //b = (int *) calloc (n, sizeof (int));
    a[0]=-99;
    //b[0]=-99;
    create(a,n);
    
   while(1)
    {
    //choice
    printf("Which operation u want to be performed on the array?\n 1- creation of array\n");
    printf("2- Sorting\n");
    printf("3- Searching\n");
    printf("4- Insertion\n");
    printf("5- Deletion\n");
    printf("9- Finding length of array\n");
    printf("6- Printing\n");
    printf("7- Traversal\n");
    printf("8- Exit\n");
    printf("10-copy\n");
    printf("11-merge\n");
   
    printf("Enter ur choice");
    scanf ("%d", &x);
   
   
   
    switch(x)
    {   
        case 1:
              create(a,n);
              break;
        case 2:               //sorting
               printf("press 9 for selection sort and 10 for bubble sort\n");
               scanf("%d",&y);
               
               switch(y)
               {   case 9:
                          selection_sort(a);
                          sorted=1;
                          break;
                         
                    case 10:
                           bubble_sort(a);
                           sorted=1;
                           break;
               }
               break;
       
        case 3:            //searching
               printf("press 11 for linear search and 12 for binary search\n");
               scanf("%d",&z);
               
               switch(z)
               {   case 11:
                          linear_search(a);
                          break;
                         
                    case 12:
                           binary_search(a);
                          break;
               }
               break;
               
        case 4:                //insertion
                if(isFull(a)==0)
                printf("array is full, insertion not possible\n");
               else
               {   printf("Enter the element to be inserted: \n");
                   scanf("%d", &value);
                   printf("\n enter the position at which u want to insert the element: \n");		
                   scanf("%d", &posi);
                   insertion(value,(posi),a);			
               }
               break;
               
               
        case 5:                //deletion
               if(isEmpty(a)==1)
                  printf("array is empty, deletion not possible");
               else
               {
                   printf("\n enter the position at which u want to delete the element: \n");
                   scanf("%d", &posd);
                   deletion((posd),a);
               }
               break;
        case 7:
               traverse(a);
               break;
               
        case 9:
               
               
               printf("the length of the array is: %d", length(a));
               break;
               
        case 10:                   //copy
               printf("Copied array is:\n");
                copy(a);
               break;
        case 11:                   //merge
                printf("Enter 0 to merge without sort and 1 to merge with sort.\n");
                scanf("%d", &Choice);
                switch(Choice) {
                    case 0: 
                        mergeNoSort(a);
                        break;
                    case 1:
                        if(sorted == 1) mergeWithSort(a);
                        else printf("Please sort the 1st array first.\n");
                        break;
                    default:
                        printf("Invalid Choice.\n");
                }

                break;
        case 8:
               exit(0);
    }                         //end of switch case
   
   
}
}

//individual function calling begins

void create (int a[], int n)        //creation of array
{
  int i;
  if(n>=MAX)
   {
       printf("Too many elements");
       exit(0);
       }
    else
    {
        printf ("enter %d elements", n);
        a[0]=-99;
        for (i = 0; i < n; i++)   //i=1
    {   
      a[i+1]=a[i];						// 1 3 4 2 5 -99
      scanf ("%d", &a[i]);
    }
}
}



void print(int *a,int n)            //printing of array
{
    int i;
    printf(" The elements of sorted array are:\n");
    for(i=0;i<n;i++)
    {
        //printf("%p\n",a);
        printf("%d ",*a);
        a++;
    }
    printf("\n");
   
}



void selection_sort (int a[])     //selection sort            
{							//// 1 3 4 2 5 -99
  int i, k, j, key;	
  int n=length(a);				//n=5
  for (i = 0; i < n; i++)		//n+1
    {
      k = i;					//k=i=1					
      for (j = i + 1; j < n; j++)		//j=i+1=5		//5 3 1 2 4
     {									//i=0...1 3 5 2 4
          if (a[k] > a[j])			//a[k]=1		//i=1...1 2 5 3 4
          {   								//i=2...1 2 3 5 4
              k = j;				//k=2			//i=3...1 2 3 4 5
          }
     }
 
 
 
 
 
      key = a[i];			//key=3 a[1]=3 a[3]=2				
      a[i] = a[k];			//1 3 4 2 5
      a[k] = key;			//1 2 4 3 5 -99
					//1 2 3 4 5 -99
    }
    traverse(a);
}



void bubble_sort (int a[])        //bubble sort
{							// 1 3 4 2 5 -99
    int i,j,key;
    int n=length(a);
   
    for(i=0;i<n-1;i++)	//i=0,3			//1 3 2 4 5 -99
    {                                    		//1 2 3 4 5 -99
        for(j=0;j<n-i-1;j++)
        {						
            if(a[j]>a[j+1])				//5 4 3 2 1  if condition is a[j]<a[j+1]
            {
                key = a[j];
                a[j] = a[j+1];
                a[j+1] = key;
            }
        }
    }
     traverse(a);
}


void linear_search (int a[]) //linear searching
{
    int i,j,num,flag=0;
    int n=length(a);
    printf("enter the element you want to search:\n");
    scanf("%d",&num);		//num=6
   
    for(i=0;i<n;i++)  //n+1			//1 3 4 2 5 -99
    {
        if(a[i]==num)
        {
            printf("%d is found at %dth index\n",num,i);
            flag=1;
            break;
        }
        	
                  
        
    }
    if(flag==0)
    {
        printf("%d is not found in given array\n",num);
    }

}


void binary_search (int a[]) //binary searching
{
    int i,j,flag=0,num;
    int n=length(a);
    printf("enter the element you want to search:\n");		//1 3 4 2 5 -99   num=5 unsorted 
    scanf("%d",&num);
    selection_sort (a);						//1 2 3 4 5 -99   sorted
    int l=0,u,mid;							//l=0,u=4
    u=n-1;
   
    while(l<=u)
    {
        mid=(l+u)/2;							//mid=2
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

int length(int *p)               //length of array
{
    int count=0;			// 1 3 4 2 5 -99
    while(*p!=-99)			//*p=-99
    {
        count++;			//counter=5
        p++;
    }
    return count;
}


int isEmpty(int a[])                  //isEmpty
{
    int check= length(a);
    if(check==0)
      return 1;		//
    else
      return 0;
}



int isFull(int a[])                   //isFull
{
    int check=length(a);    //check=6
    if(check>= MAX-1)       //6==7
       return 0;	     //0=array is full
    else
       return 1;	    //1= array is not full,insetion possible.
}

void insertion(int val, int pos, int a[])          //insertion		a=1 4 3 2 5 -99  val=10  pos=2 l=5 
{
    int back;
    int l=length(a);
    if(pos>=l || l>=MAX)		
       printf("Insertion is not possible");
    else
    {
        back=l;			//back=1
        while(back>=pos)
        {
            a[back+1]=a[back];			//1 4 10 3 2 5 -99
            back--;					
        }						
    a[pos]=val;
    }
    l++;
         traverse(a);
}
       
       

void deletion(int pos , int a[])             //deletion
{
    int l, back;				//a=1 4 3 2 5 -99 
    l=length(a);				//l=5,pos=1
    if(pos>=l-1 || l==0)
       printf("Deletion is not possible");
    else
     {   back=pos;		//back=5
     	while(back<l)		
      	{
          a[back]=a[back+1];		//1 3 2 5 -99 -99 
           back++;
      	}
     }
     l--;
          traverse(a);
}


void traverse(int a[])              //traversal
 {
     int i;
     int n=length(a);
     printf("\n Elements of the array are: \n");
     for(i=0; i<n;i++)
     {
         printf("%d\t",a[i]);
     }
     printf("\n");
 }
 
 void copy(int *a)                    //copy
 {
    
    if(isEmpty(a)==1)
 	printf(" array empty,copy operation not possible");
 	else
 	{
 	int len=length(a);
 	int *b;
 	//printf("11111");
 	b=(int*)calloc(len, sizeof(int));
 	for(int i=0;i<len;i++)
 	{
 		b[i]=a[i];
 	}
 	traverse(b);

 }
}


void mergeNoSort(int a[])		//merging without sorting
{
    int n = length(a), m;
    printf("Enter the number of elements in the array: ");
    scanf("%d",&m);
    if(m+n> MAX) {
        printf("number of elements exceeds array size.\n");
        return;
    }
    int* b;
    b = (int *) calloc (m,sizeof(int));
    create (b, m);
    for(int i = 0; i < m; i++) {
        a[n+i+1] = a[n+i];
        a[n+i] = b[i];
    }
    traverse(a);
}


void mergeWithSort(int a[]) 		//merging with sorting
{
    int n = length(a), m;
    printf("Enter the number of elements in the array: ");
    scanf("%d",&m);
    if(m+n> MAX) {
        printf("number of elements exceeds array size.\n");
        return;
    }
    int* b;
    b = (int *) calloc (m,sizeof(int));
    create (b, m);
    int i,j;
    for(i=0; i<m; i++) {
        n = length(a);
        for(j=0; j <= n; j++) 
        {
            if(b[i]<a[j]) 
               {
                insertInArray(b[i], j, a);
                break;
               }
            if(j == n) 
            	{
                a[j+1] = a[j];
                a[j] = b[i];
           	}
        }
    }
    traverse(a);
}



void insertInArray(int val, int pos, int arr[])		
 {
    int n = length(arr);
	if(pos>n || isFull(arr) == 1)
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

