#include<stdio.h>
#include<stdlib.h>

struct node
{
	int data;
	struct node *next;
};
typedef struct node list; 

list* create(); 
list* insertatbeg(list *head,int data);
list* insertatend(list *head,int data);
list* insertatpos(list* head,int data);
list* insertordered(list* head,int data);
list* deletionatbeg(list* head);
list* deletionatpos(list* head,int data);
list* deletionatend(list* head);
void traverse(	struct node *p);
list* reverse(list* head);
int length(list* head);
void searching(list* head,int val);
void copy(list* head);
list* sort(list* head);
list* concatenate(list* head,list* head1);

int main()
{
	int option,choice,choice1,choice2,data,count=0;
	list* head1=create();
	list* head=create();
	//head->data=-99;
	//head->next=NULL;
	head=NULL;
	printf("Address of node: %p\n",head);
	
	while(1)
	{
		printf("1.insert\n2.delete\n3.traverse\n4.length\n5.reverse\n6.searching\n7.copy\n8.sort \n9.concatinate\n10.linked-stack\n11linked-queue.\n12.exit\n");
		scanf("%d",&option);
		switch(option)
		{
			case 1:

				printf("enter 1 for inserting element at beginning.\nenter 2 for inserting at a particular  position.\nenter 3 for inserting element at end.\nenter 4 for inserting element in ordered way.\n");
				scanf("%d",&choice);
				printf("Enter the data you want to insert:\n");
				scanf("%d",&data);
				
				if(choice==1)
					head=insertatbeg(head,data);				
				else if(choice==2)
					head=insertatpos(head,data);				
				else if(choice==3)
					head=insertatend(head,data);	
				else if(choice==4)
					head=insertordered(head,data);			
				else
				printf("Invalid option.\n");
				
				break;
			case 2:
				printf("enter 1 for deleting element at beginning.\nenter 2 for deleting a particular element.\nenter 3 for deleting element at end.\n");
				scanf("%d",&choice1);
				
				
				if(choice1==1)
				{
					head=deletionatbeg(head);				
				}
				else if(choice1==2)
				{
					printf("Enter the element you want to delete:\n");
					scanf("%d",&data);
					head=deletionatpos(head,data);				
				}
				else if(choice1==3)
				{
					deletionatend(head);				
				}
				else
					printf("Invalid option.\n");
				break;
			case 3:
				traverse(head);
				break;
			case 4: 
				count=length(head);
				printf("number of nodes in linked list is: %d\n",count);	
				break;
			case 5:
				head=reverse(head);
				break;
			case 6:
				printf("Enter the element you want to search:\n");
				scanf("%d",&data);
				searching(head,data);
				break;
			case 7:
				copy(head);
				break;
			case 8:
				head=sort(head);
				break;
			case 9:
				printf("Please Create a new linked-list.\n");
				head1=NULL;
				while(1)
				{
					printf("enter 1 for inserting element at beginning.\nenter 2 for inserting at a  particular position.\nenter 3 for inserting element at end.\nenter 4 for inserting element in ordered way.\nenter 5 to stop inserting.\n");
				scanf("%d",&choice);
				if(choice==5)
					break;
				printf("Enter the data you want to insert:\n");
				scanf("%d",&data);
				
				if(choice==1)
					head1=insertatbeg(head1,data);				
				else if(choice==2)
					head1=insertatpos(head1,data);				
				else if(choice==3)
					head1=insertatend(head1,data);	
				else if(choice==4)
					head1=insertordered(head1,data);
				else
					printf("Invalid option.\n");
				
				//traverse(head1);
				}
				head=concatenate(head,head1);
				break;
			case 10:
				printf("We are Implementing linked-stack.\n");
				while(1)
				{
					printf("1.Insertion\n2.Deletion\n3.traverse\n4.top value\n5.stop implementation of linked-stack.\n");
					scanf("%d",&choice2);
					
					switch(choice2)
					{
						case 1:
							printf("Enter the data you want to insert:\n");
							scanf("%d",&data);
							head=insertatbeg(head,data);
							break;
						case 2:
							head=deletionatbeg(head);
							break;
						case 3:
							traverse(head);
							break;
						case 4:
							
							//printf("Top Value:\n");	
							printf("The top value is: %d\n", head -> data); 
							break;

						case 5:
							break;
						default:
							printf("Invalid input.\n");
					}
					if(choice2==5)
					break;
				}
				break;
			case 11:
				printf("We are Implementing linked-queue.\n");
				while(1)
				{
					printf("1.Insertion\n2.Deletion\n3.traverse\n4.top value\n5.stop implementation of linked-queue.\n");
					scanf("%d",&choice2);
					
					switch(choice2)
					{
						case 1:
							printf("Enter the data you want to insert:\n");
							scanf("%d",&data);
							head=insertatbeg(head,data);
							break;
						case 2:
							head=deletionatend(head);
							break;
						case 3:
							traverse(head);
							break;
						case 4:
							//printf("Top Value:\n");
							printf("The top value is: %d\n", head -> data); 
							break;

						case 5:
							break;
						default:
							printf("Invalid input.\n");
					}
					if(choice2==5)
					break;
				}
				break;
			case 12:
				exit(0);
			default:
				printf("Invalid option.\n");
		}
		printf("\n\n");
	}
}



list* create()
{
	
	list* q;
	q=(list*)malloc(sizeof(list));
	if (q==NULL)
	{
		printf("Node is not created.");
	}
	else
	{
		//printf("Node is created.");
		return q;
	}
	
	
	
}

void traverse(list *p)
{
	if(p==NULL)
	{
		printf("list is empty.\n");
	}
	while(p != NULL)
	{
		printf("%d|%p   ",p->data,p->next);		//%lu can be used instead of %p and 									//[p->next] will change to [(unsigned 								//long)p->next]
		p=p->next;
	}
	printf("\n");
}

list* insertatbeg(list *head,int data)
{
	
	list* temp;
	temp=create();
	temp->data=data;
	temp->next=head;
	return temp;
}

list* insertordered(list* head,int data)
{
	list* new_node=create();
	new_node->data=data;
	if(head==NULL)
	{
		return new_node;
	}
	if(head->data>= new_node->data)
	{
		new_node->next=head;
		return new_node;
	}
	list* temp=head;
	temp=temp->next;
	while(temp!= NULL && temp->next->data<=new_node->data)
	{
		temp=temp->next;
	}
	new_node->next=temp->next;
	temp->next=new_node;
	return head;
}

list* insertatend(list *head,int data)
{
	list*temp;
	list*temp1=head;
	temp=create();
	temp->data=data;
	temp->next=NULL;
	if(head==NULL)
	{
		head=temp;
		return head;
	}
	while(temp1->next!=NULL)
	{
		temp1=temp1->next;
	}
	temp1->next=temp;
	return head;	
}

list* insertatpos(list* head,int data)
{
	list* temp=head;
	int k=0,pos;
	printf("Enter position at which you want to insert element:\n");
	scanf("%d",&pos);
	if(head==NULL)
	{
		head=insertatbeg(head,data);
		return head;
	}
	while(k < pos-1)
	{
		temp=temp->next;
		if(temp==NULL)
		{
			printf("Node in the list is less than position.\n");
			return head;
		}
		k++;
	}
	
	list* tempnew=create();
	tempnew->data=data;
	tempnew->next=temp->next;
	temp->next=tempnew;
	return head;
}

list* deletionatbeg(list* head)
{
	if(head==NULL)
	{
		printf("list is empty.\ndeletion not possible.\n");
		return head;
	}
	if(head->next==NULL)
	{
		printf("deleting element %d\n",head->data);
		free(head);
		return NULL;
	}
	list* temp=head;
	printf("deleting element %d\n",head->data);
	head=head->next;
	free(temp);
	return head;	
}


list* deletionatpos(list* head,int ele)
{
	list* temp=head;
	list* prev;
	
	if(head==NULL)
	{
		printf("list is empty.\ndeletion not possible.\n");
		return head;
	}
	else
	{
		
		if(temp->data==ele)
		{
			head=temp->next;
			free(temp);
			return head;
		}
	
		while(temp!= NULL && temp->data!=ele)
		{
			prev=temp;
			temp=temp->next;
		}
		
		if(temp==NULL)
		{
			printf("Element not found in list.\n");
			return head;
		}
		
		prev->next=temp->next;
		free(temp);
		return head;
		
	}
}

list* deletionatend(list* head)		
{
	
	if(head==NULL)
	{
		printf("list is empty.\ndeletion not possible.\n");
		return head;
	}
	if(head->next==NULL)
	{
		printf("deleting element %d\n",head->data);
		free(head);
		return NULL;
	}
	list* temp=head;
	list* prev;
	while(temp->next !=NULL)
	{
		prev=temp;
		temp=temp->next;
	}
	prev->next=NULL;
	free(temp);
	return head;
	
}

list* reverse(list* head)
{
	list* current,*prev,*next;
	current=head;
	prev=NULL;
	while(current!=NULL)
	{
		next=current->next;
		current->next=prev;
		prev=current;
		current=next;
		
	}
	head=prev;
	return head;
}
int length(list* head)		
{
	list* temp=head;
	int count=0;
	while(temp!=NULL)
	{
		count++;
		temp=temp->next;
	}
	return count;
}

void searching(list* head,int val)
{
	list* temp=head;
	int k=0;
	while(temp!=NULL)
	{
		if(temp->data==val)			
		{
			printf("element %d is found at %d position.\n",val,k);
			break;
		}
		temp=temp->next;
		k++;
	}
	if(temp==NULL)
	{
		printf("element %d is not found.\n",val);
	}
}


void copy(list* head)
{
	list *temp=head;	
	list *copy=create();
	copy=NULL;
	while(temp!=NULL)		
	{				
		copy=insertatend(copy,temp->data);
		temp=temp->next;
	}
	printf("Copied linked list is: ");
	traverse(copy);
	
}		

list* sort(list* head)
{
	int count=length(head),k;
	list* temp=head;
	for(int i=0;i<count-1;i++)
	{
		temp=head;
		while(temp->next!=NULL)
		{
			if(temp->data > temp->next->data)
			{
				k=temp->data;
				temp->data=temp->next->data;
				temp->next->data=k;
			}
			temp=temp->next;
		}
		
	}
	return head;
}

list* concatenate(list* head,list* head1)
{
	
	
	if( head != NULL && head1!= NULL )		
    	{						
        	if (head->next == NULL)
            		head->next = head1;
        	else
            		concatenate(head->next,head1);
        	return head;
    	}
    	else
    	{
        	printf("Either 1st linked list or 2 linked list is NULL\n");
        	return head;
    	}
	
}


