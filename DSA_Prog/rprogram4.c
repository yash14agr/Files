#include <stdio.h>
#include<stdlib.h>
//stack 
void push_stack(int a[], int *top,int n);
void pop_stack(int *top);
void top_val_stack(int a[],int *top);
int is_empty_stack(int *top);
int is_full_stack(int *top,int n);
void display_stack(int a[], int *top);
//queue
void insert_queue(int a[],int *rear,int *front,int n);
void delete_queue(int *rear,int *front);
//void front_val_queue(int a[],int *rear,int *front);   
void rear_val_queue(int a[],int *rear,int *front);
void display_queue(int a[],int *rear,int *front);
int is_empty_queue(int *rear,int *front);
int is_full_queue(int *rear,int n);
//circular queue
void insert_cq(int a[],int *front,int *rear,int n );
void delete_cq(int a[],int *front,int *rear,int n);
//void front_val_cq(int a[],int *rear,int *front,int n);  
void rear_val_cq(int a[],int *rear,int *front,int n);
void display_cq(int a[],int *rear,int *front,int n);
int is_empty_cq(int *rear,int *front);
int is_full_cq(int *rear,int *front,int n);





int main()
{  int choice1,choice2,choice3,choice4,item,n;
   int top=-1;
     printf("enter size of Data structure:\n");
     scanf("%d",&n);
     int* a=(int*)calloc(n,sizeof(int));
    while(1)
    {
    printf("which linear data structure?\n1.Stack ADT\n2.Queue ADT\n3.Circular queue ADT\n4.Exit\n");
    scanf("%d",&choice1);
    int rear=-1,front=-1;  
    switch(choice1)
    {
        case 1:
           while(1)
           {printf("\n u selected Stack ADT!");
           printf("\nwhich operations would u like to perform?\nenter corresponding number\n");
           printf("1.Push\n2.Pop\n3.Top_val\n4.IsEmpty\n5.IsFull\n6.Display\n7.Exit\n");
           scanf("%d",&choice2);
           
                switch(choice2)
           {
               case 1:
                  printf("u selected PUSH operation");
                  push_stack(a,&top,n);
                  break;
                  
                case 2:
                  printf("u selected POP operation");
                  pop_stack(&top);
                  break;
                  
                case 3:
                  printf("u selected TOP_VAL operation");
                  top_val_stack(a,&top);
                  break;
                  
                case 4:
                  printf("u selected ISEMPTY operation");
                            if(is_empty_stack(&top)==1)
     	  						printf("Stack is empty.\n");
     	  					else
     	  						printf("Stack is not empty.\n");
     	  					break;
                  
                  
                case 5:
                  printf("u selected ISFULL operation");
                  if(is_full_stack(&top,n)==1)
     	  						printf("Stack is full.\n");
     	  					else
     	  					     	printf("Stack is not full.\n");
     	  					break;
                  
                case 6:
                  printf("u selected DISPLAY operation");
                  display_stack(a,&top);
                  break;
                  
                case 7:
                   //exit (0);
                   break;
                  
           }
     	  			if(choice2==7)
     	  			break;
     	  		}
     	  		break;
         
         case 2:
            while(1)
           {printf("u selected Queue ADT!");
            printf("\nwhich operations would u like to perform?\nenter corresponding number\n");
           printf("1.Insert\n2.Delete\n3.Front_val\n4.Rear_val\n5.IsEmpty\n6.IsFull\n7.Display\n8.Exit\n");
           scanf("%d",&choice3);
           
                switch(choice3)
           {
               case 1:
                  printf("u selected Insert operation");
                  insert_queue(a,&rear,&front,n);
                  break;
                  
                case 2:
                  printf("u selected Delete operation");
                  delete_queue(&rear,&front);
                  break;
                  
                /*case 3:
                  printf("u selected Front_val operation");
                  front_val_queue(a,&rear,&front);
                  break;
                 */ 
                case 4:
                  printf("u selected Rear_val operation");
                  rear_val_queue(a,&rear,&front);
                  break;
                  
                case 5:
                  printf("u selected IsEmpty operation");
                  is_empty_queue(&rear,&front);
                  break;
                  
                case 6:
                  printf("u selected IsFull operation");
                  is_full_queue(&rear,n);
                  break;
                  
                case 7:
                   printf("u selected DISPLAY operation");
                   display_queue(a,&rear,&front);
                   break;
                case 8:
                   //exit (0);
                   break;
                  
           }
     	  			if(choice2==8)
     	  			break;
     	  		}
     	  		break;
            
        case 3:
           while(1)
           {
            printf("u selected Circular Queue ADT!");
           printf("\nwhich operations would u like to perform?\nenter corresponding number\n");
           printf("1.Insert\n2.Delete\n3.Front_val\n4.Rear_val\n5.IsEmpty\n6.IsFull\n7.Display\n8.Exit\n");
           scanf("%d",&choice4);
               switch(choice4)
           {
               case 1:
                  printf("u selected Insert operation");
                  insert_cq(a,&front,&rear,n);
                  break;
                  
                case 2:
                  printf("u selected Delete operation");
                  delete_cq(a,&front,&rear,n);
                  break;
                  
                /*
                case 3:
                  printf("u selected Front_val operation");
                  front_val_cq(a,&rear,&front,n);
                  break;
                  */
                case 4:
                  printf("u selected Rear_val operation");
                  rear_val_cq(a,&rear,&front,n);
                  break;
                  
                case 5:
                  printf("u selected IsEmpty operation");
                  is_empty_cq(&rear,&front);
                  break;
                  
                case 6:
                  printf("u selected IsFull operation");
                  is_full_cq(&rear,&front,n);
                  break;
                  
                case 7:
                   printf("u selected DISPLAY operation");
                   display_cq(a,&rear,&front,n);
                   break;
                case 8:
                   //exit (0);
                   break;
           }
     	  			if(choice2==8)
     	  			break;
     	  		}
     	  		break;
    }

    return 0;
}
}

//stack
void push_stack(int a[], int *top,int n)     //push_stack
{	
	int item;     
	printf("Enter the value to be inserted:\n");
	scanf("%d",&item);
	if(is_full_stack(top,n)==0)
	{
		*top=*top+1;
		a[*top]=item;
	}
	else
	{
		printf("stack is full.\n");
	}
}



void pop_stack(int *top)    //pop_stack
{	if(is_empty_stack(top)==0)
	{
		*top=*top-1;
	}
	else
	{
		printf("stack is empty.\n");
	}
}


void top_val_stack(int a[],int *top)    //top_val_stack
{
    if(is_empty_stack(top)==1)
	{
		printf("Stack is empty.\n");
	}
	else
	{
		printf("value of top is: %d\n",*top);
	}
}

int is_empty_stack(int *top)             //is_empty_stack
{
    if(*top==-1)
	return 1;
	else
	return 0;
}

int is_full_stack(int* top,int n)           //is_full_stack
{
    if(*top==n-1)
	return 1;
	else
	return 0;
}


void display_stack(int a[], int *top )      //display_stack
{
	int i;
	printf("Stack: ");
	if(is_empty_stack(top)==0)
	{
		for(i=0;i<=*top;i++)
		{
		printf("%d ",a[i]);	
		}
	}	
	else
	{
		printf("Stack is empty.\n");
	}
}



//queue
void insert_queue(int a[],int *rear,int *front,int n)     //insert_queue
{
    
	int item1;
	printf("Enter the value to be inserted:\n");
	scanf("%d",&item1);
	//printf("rear=%d",*rear);
	if(*(rear)==n-1)
	{
		printf("Queue is Full.\n");
	}
	else    
	{        
	(rear)=(rear)+1;      
	a[*(rear)]=item1;    
	}
}


void delete_queue(int *rear,int *front)      //delete_queue
{
    if(*front==*rear)
	printf("Queue is Empty\n");
	else    
	{
        *front++;            
        }
}


int is_empty_queue(int *rear,int *front)       //is_empty_queue
{
	if(*rear==*front)
		printf("Queue is empty.\n");
	else
		printf("Queue is not empty.\n");
}

int is_full_queue(int *rear,int n)          //is_full_queue
{
	if(*rear==n-1)
		printf("Queue is full.\n");
	else
		printf("Queue is not full.\n");
}


/*
void front_val_queue(int a[],int *rear,int *front)
{
	if(front!=rear)
		printf("element at front pointer is: %d\n",a[front+1]);	
	else
		printf("Queue is empty.");
}

*/
void rear_val_queue(int a[],int *rear,int *front)        //rear_val_queue
{
	if(*front!=*rear)
		printf("element at rear pointer is: %d\n",a[*rear]);	
	else
		printf("Queue is empty.\n");	
}


void display_queue(int a[],int *rear,int *front )      //display_queue
{
	int i;
	printf("Queue: ");
	for(i=*(front)+1; i<=*rear ;i++)
		printf("%d ",a[i]);
	printf("\n");
}


//circular queue 
void insert_cq(int a[],int *front,int *rear,int n)      //insert_cq
{
    int item1;
	printf("Enter the value to be inserted:\n");
	scanf("%d",&item1);
	
	if((*(rear)+1)%n==*front)
	{
		printf("Circular Queue is full.\n");
		return;
	}
	if(*front==-1 && *rear==-1)
		*front=0;
	
	
	*rear=(*rear+1)%n;
	a[*rear]=item1;
	
}


void delete_cq(int a[],int *front,int *rear,int n)      //delete_cq
{
    if(*rear==*front)
		printf("Circular Queue is empty.\n");
	else
	{
		*front=(*front+1)%n;
	}
}


/*
void front_val_cq()
{
    
}
*/

void rear_val_cq(int a[],int *rear,int *front,int n)     //rear_val_cq
{
    if(*front!=*rear)
		printf("element at rear pointer is: %d\n",a[((*rear))%n]);	
	else
		printf("Queue is empty.\n");
}

int is_full_cq(int *rear,int *front,int n)      //is_full_cq
{
    
	if((*rear+1)%n==*front)
		printf("Circular Queue is full.\n");
	else
		printf("Circular Queue is not full.\n");
}


int is_empty_cq(int *rear,int *front)         //is_empty_cq
{
	if(*rear==*front)
		printf("Circular Queue is empty.\n");
	else
		printf("Circular Queue is not empty.\n");
}


void display_cq(int a[],int *rear,int *front,int n )      //display_cq
{
	int i=*(front);
	if(*rear==*front)
		printf("Circular Queue is empty.\n");
	else
	{
		printf("Circular Queue: ");
	do
	{
		printf("%d ",a[i]);
		i=(i+1)%n;
	}while(i!=(*rear+1)%n);
	}
	printf("\n");
}

