#include<stdio.h> 
#include<stdlib.h>

void push_stack(int a[], int *top,int n);
void pop_stack(int *top);
void display_stack(int a[], int *top);
void Top_val(int a[],int *top);
int is_empty_stack(int *top);
int is_full_stack(int *top,int n);

void push_queue(int a[],int *rear,int *front,int n);
void pop_queue(int *rear,int *front);
int is_empty_queue(int *rear,int *front);
int is_full_queue(int *rear,int n);
//void front_val(int a[],int *rear,int *front);
void rear_val(int a[],int *rear,int *front);
void display_queue(int a[],int *rear,int *front );

void push_circular_queue(int a[],int *front,int *rear,int n);
void pop_circular_queue(int a[],int *front,int *rear,int n);
void display_circular_queue(int a[],int *rear,int *front,int n );
int is_empty_circular_queue(int *rear,int *front);
int is_full_circular_queue(int *rear,int *front,int n);
void rear_val_cir(int a[],int *rear,int *front,int n);

int main()
{
     int option1,option2,n;
     printf("enter size of Data structure:\n");
     scanf("%d",&n);
     int* a=(int*)calloc(n,sizeof(int));		//memory allocation
     
     while(1)
     {
     	  printf("\nSelect given numbers to select Data structure:\n1.Stack\n2.Queue\n3.Circular Queue\n4.exit\n");
     	  scanf("%d",&option1);
     	  int rear=-1,front=-1,top=-1;
     	  switch(option1)
     	  {
     	  	case 1:			//case 1 for stack
     	  		while(1)
     	  		{
     	  			printf("\n\n");
     	  			printf("select operations you want to perform:\n1.Push\n2.Pop\n3.Top_val\n4.Is Empty\n5.Is full\n6.Display\n7.exit\n");
     	  			scanf("%d",&option2);
     	  			
     	  			switch(option2)
     	  			{
     	  				case 1:
     	  					push_stack(a,&top,n);
     	  					break;
     	  				case 2:
     	  					pop_stack(&top);
     	  					break;
     	  				case 3:
     	  					Top_val(a,&top);
     	  					break;
     	  				case 4:
     	  					if(is_empty_stack(&top)==1)
     	  						printf("Stack is empty.\n");
     	  					else
     	  						printf("Stack is not empty.\n");
     	  					break;
     	  				case 5: 
     	  					if(is_full_stack(&top,n)==1)
     	  						printf("Stack is full.\n");
     	  					else
     	  					     	printf("Stack is not full.\n");
     	  					break;
     	  				case 6:
     	  					display_stack(a,&top);
     	  					break;
     	  				case 7:
     	  					break; 
     	  				    	  					
     	  			}
     	  			if(option2==7)
     	  			break;
     	  		}
     	  		break;
     	  	case 2:			//case 2 for queue
     	  		while(1)
     	  		{
     	  			printf("\n\n");
     	  			printf("select operations you want to perform:\n1.Push\n2.Pop\n3.rear_val\n4.Is Empty\n5.Is full\n6.Display\n7.exit\n");
     	  			scanf("%d",&option2);
     	  			
     	  			switch(option2)
     	  			{
     	  				case 1:
     	  					push_queue(a,&rear,&front,n);
     	  					break;
     	  				case 2:
     	  					pop_queue(&rear,&front);
     	  					break;
     	  				case 3:
     	  					rear_val(a,&rear,&front);
     	  					break;
     	  				case 4:
     	  					is_empty_queue(&rear,&front);
     	  					break;
     	  				case 5: 
     	  					is_full_queue(&rear,n);
     	  					break;
     	  				case 6:
     	  					display_queue(a,&rear,&front );
     	  					break; 	  					
     	  				case 7:
     	  					break;
     	  			}
     	  			if(option2==7)
     	  			break;
     	  		}
     	  		break;
     	  	case 3:			//case 3 for circular queue
     	  		while(1)
     	  		{
     	  			printf("\n\n");
     	  			printf("select operations you want to perform:\n1.Push\n2.Pop\n3.rear_val\n4.Is Empty\n5.Is full\n6.Display\n7.exit\n");
     	  			scanf("%d",&option2);
     	  			
     	  			switch(option2)
     	  			{
     	  				case 1:
     	  					push_circular_queue(a,&front,&rear,n);
     	  					break;
     	  				case 2:
     	  					pop_circular_queue(a,&front,&rear,n);
     	  					break;
     	  				case 3:
     	  					rear_val_cir(a,&rear,&front,n);
     	  					break;
     	  				case 4:
     	  					is_empty_circular_queue(&rear,&front);
     	  					break;
     	  				case 5: 
     	  					is_full_circular_queue(&rear,&front,n);
     	  					break;
     	  				case 6:
     	  					display_circular_queue(a,&rear,&front,n);
     	  					break;
     	  				case 7:
     	  					break;
     	  			}
     	  			if(option2==7)
     	  			break;
     	  		}
     	  		break;
     	  	case 4:
     	  		exit(0);
     	  }
     	  printf("\n\n");
     }
}	  		    	  			
     
     
//STACK OPERATION FUNCTIONS

void push_stack(int a[], int *top,int n)
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

void pop_stack(int *top)
{
	if(is_empty_stack(top)==0)
	{
		*top=*top-1;
	}
	else
	{
		printf("stack is empty.\n");
	}
}

void display_stack(int a[], int *top )
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

void Top_val(int a[],int *top)
{
	if(is_empty_stack(top)==1)
	{
		printf("Stack is empty.\n");
	}
	else
	{
		printf("value of top is: %d\n",*(top)+1);
	}
}

int is_empty_stack(int *top)
{
	if(*top==-1)
	return 1;
	else
	return 0;
}

int is_full_stack(int *top,int n)
{
	if(*top==n-1)
	return 1;
	else
	return 0;     
}

//QUEUE OPERATION FUNCTIONS.

void push_queue(int a[],int *rear,int *front,int n)
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
	*(rear)=*(rear)+1;      
	a[*(rear)]=item1;    
	}
}
void pop_queue(int *rear,int *front)
{
	
	if(*front==*rear)
	printf("Queue is Empty\n");
	else    
	{
        *(front)=*(front)+1;            
        }
}

int is_empty_queue(int *rear,int *front)
{
	if(*rear==*front)
		printf("Queue is empty.\n");
	else
		printf("Queue is not empty.\n");
}

int is_full_queue(int *rear,int n)
{
	if(*rear==n-1)
		printf("Queue is full.\n");
	else
		printf("Queue is not full.\n");
}



void rear_val(int a[],int *rear,int *front)
{
	if(*front!=*rear)
		printf("element at rear pointer is: %d\n",a[*rear]);	
	else
		printf("Queue is empty.\n");	
}

void display_queue(int a[],int *rear,int *front )
{
	int i;
	printf("Queue: ");
	for(i=*(front)+1; i<=*rear ;i++)
		printf("%d ",a[i]);
	printf("\n");
}

//CIRCULAR QUEUE OPERATION FUNCTION.

void push_circular_queue(int a[],int *front,int *rear,int n)
{
	int item1;
	printf("Enter the value to be inserted:\n");
	scanf("%d",&item1);
	
	if((*rear+1)%n==*front)
		printf("Circular Queue is Full.\n");		
	else    						
	{   	
		if(*rear==-1)
		{
			*(front)=*(front)+1  ;
		}   
		*(rear)=(*(rear)+1)%n;  
		a[*rear]=item1;      
	}
}

void pop_circular_queue(int a[],int *front,int *rear,int n)
{
	if(*rear==*front)
		printf("Circular Queue is empty.\n");
	else
	{
		*front=(*front+1)%n;
	}
}

void display_circular_queue(int a[],int *rear,int *front,int n )
{
	int i=*front%n;
	do    
	{
	printf("%d ",a[i]);
	i=(i+1)%n;    
	}while(i!=(*rear+1)%n);
	printf("\n");
}

int is_empty_circular_queue(int *rear,int *front)
{
	if(*rear==*front)
		printf("Circular Queue is empty.\n");
	else
		printf("Circular Queue is not empty.\n");
}

int is_full_circular_queue(int *rear,int *front,int n)
{
	if((*(rear)+1)%n==*front)
		printf("Circular Queue is full.\n");
	else
		printf("Circular Queue is not full.\n");
}

void rear_val_cir(int a[],int *rear,int *front,int n)
{
	if(*front!=*rear)
		printf("element at rear pointer is: %d\n",a[((*rear))%n]);	
	else
		printf("Queue is empty.\n");	
}
