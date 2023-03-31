#include<stdio.h>
#include<stdlib.h>

struct node
{
	struct node *prev;
	int data;
	struct node *next;
};
typedef struct node list; 

list* create();
void traverse(list *p);
list* insertatbeg(list *head,int data);
list* insertatend(list *head,int data);
list* insertatpos(list *head,int data);
list* deletionatbeg(list*head);
list* deletionatend(list*head);
list* deletionatpos(list*head,int pos);
list* sort(list* head);
void searching(list* head,int val);
int length(list* head);
list* reverse(list* head);
int main()
{
	printf("IMPLEMENTING DOUBLY LINKED LIST\n\n");
	int choice,choice1,data,pos;
	list* head=create();
	head=NULL;
	while(1)
	{
		printf("Enter 1 for insertion.\nEnter 2 for deletion.\nEnter 3 for printing.\nEnter 4 to sort the list.\nenter 5 to search an element\nenter 6 to find length\nenter 7 to reverse\nenter 8 to implement doubly linked stack\nenter 9  to implement doubly linked queue\nenter 10 to exit.\n");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
				printf("Enter 1 for inserting data at beginning.\nEnter 2 for inserting data at end.\nEnter 3 for inserting data at a particular position.\n ");
				scanf("%d",&choice1);
				printf("Enter the data you want to insert:\n");
				scanf("%d",&data);
				
				if(choice1==1)
					head=insertatbeg(head,data);
				else if(choice1==2)
					head=insertatend(head,data);
				else if(choice1==3)
					head=insertatpos(head,data);
				else
					printf("Invalid input.\n");
				break;
			case 2:
				printf("Enter 1 for deleting data at beginning.\nEnter 2 for deleting data at end.\nEnter 3 for deleting data at a particular position.\n ");
				scanf("%d",&choice1);
				
				
				if(choice1==1)
					head=deletionatbeg(head);
				else if(choice1==2)
					head=deletionatend(head);
				else if(choice1==3)
				{	
					printf("Enter position:\n");
					scanf("%d",&pos);
					head=deletionatpos(head,pos);
				}
				else
					printf("Invalid input.\n");
				break;
			case 3:
				traverse(head);
				break;
			case 4:
				head=sort(head);
				break;
			case 5:
				printf("Enter the element you want to search:\n");
				scanf("%d",&data);
				searching(head,data);
				break;
			case 6:
				printf("Length of linked list is %d",length(head));
				break;
			case 7:
				head=reverse(head);
				break;
			case 8:	
				printf("We are Implementing doubly linked-stack.\n");
				while(1)
				{
					printf("1.Insertion\n2.Deletion\n3.traverse\n4.top value\n5.stop implementation of doubly linked-stack.\n");
					scanf("%d",&choice1);
					switch(choice1)
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
					if(choice1==5)
					break;
				}
				break;
			case 9:
				printf("We are Implementing doubly linked-queue.\n");
				while(1)
				{
					printf("1.Insertion\n2.Deletion\n3.traverse\n4.top value\n5.stop implementation of doubly linked-queue.\n");
					scanf("%d",&choice1);
					
					switch(choice1)
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
					if(choice1==5)
					break;
				}
				break;
			case 10:
				exit(0);
			default:
				printf("Invalide input.\n");
		}
	printf("\n\n");
	}
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
		printf("%p|%d|%p   ",p->prev,p->data,p->next);
		p=p->next;
	}
	printf("\n");
}

list* insertatbeg(list *head,int data)
{
	
	list* temp;
	temp=create();
	temp->data=data;		//   NULL | 5 | NULL
	temp->prev=NULL;
	temp->next=head;
	if(head==NULL)
	{
		return temp;
	}
	head->prev=temp;
	return temp;
}

list* insertatend(list* head,int data)
{
	list* temp=head;
	list* new_node=create();
	new_node->data=data;
	new_node->next=NULL;
	if(temp==NULL)
	{
		new_node->prev=NULL;
		return new_node;
	}
	while(temp->next!=NULL)
	{
		temp=temp->next;
	}
	temp->next=new_node;
	new_node->prev=temp;
	return head;
}

list *insertatpos(list *head,int data)
{
	list* temp=head;
	int k=0,pos;
	printf("Enter the position at which you want to insert element:\n");
	scanf("%d",&pos);
	if(head==NULL || pos==0)
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
	
	list* new_node=create();
	new_node->data=data;
	new_node->next=temp->next;
	new_node->prev=temp;
	temp->next=new_node;
	temp->next->prev=new_node;
	return head;
}

list* deletionatbeg(list*head)
{
	int key;
	if(head==NULL)
	{
		printf("List is empty.\n");
		return head;
	}
	if(head->next==NULL)
	{
		key=head->data;
		printf("Deleting %d element from list.\n",key);
		free(head);
		return head;
	}
	list *temp=head;
	key=temp->data;
	head=head->next;
	head->prev=NULL;
	free(temp);
	printf("Deleting %d element from list.\n",key);
	return head;
}	

list* deletionatend(list*head)
{
	int key;
	if(head==NULL)
	{
		printf("List is empty.\n");
		return head;
	}
	if(head->next==NULL)
	{
		key=head->data;
		printf("Deleting %d element from list.\n",key);
		free(head);
		return head;
	}
	list* temp=head;
	while(temp->next!=NULL)
	{
		temp=temp->next;
	}	
	temp->prev->next=NULL;
	free(temp);
	return head;
}

list* deletionatpos(list*head,int pos)
{
	int k=0,key;
	list*temp=head;
	if(head==NULL)
	{
		printf("List is empty.\n");
		return head;
	}
	if(pos==0)
	{	
		key=head->data;
		printf("Deleting %d element from list.\n",key);
		head=deletionatbeg(head);
		return head;
	}
	while(k<pos-1)
	{
		temp=temp->next;
		if(temp==NULL)
		{
			printf("Node in the list less than the position");
			return head;
		}
		k++;
	}
	key=temp->next->data;
	list* hold=temp->next->next;
	free(temp->next);	
	printf("Deleting element=%d from list.\n",key);
	temp->next=hold;
	hold->prev=temp;
	return head;	
}

list* sort(list* head)				//with changing address i.e. swapping values
{
	list*current=NULL,*index=NULL;
	int temp;
	if(head==NULL)
	{
		printf("List is empty.\n");
		return head;
	}
	for(current=head ; current!=NULL ; current=current->next)
	{
		for(index=current->next ; index!=NULL ;index=index->next)
		{
			if(current->data>index->data)
			{
				temp=current->data;
				current->data=index->data;
				index->data=temp;
			}
		}
	}
	return head;
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

list* reverse(list* head)
{
	list*prev=NULL;
	list* temp=head;
	list* temp1=head;
	list* t;
	if(head==NULL)
	{
		printf("List is empty.\n");
		return head;
	}
	while(temp1!=NULL)
	{
		temp1=temp1->next;
		t=temp->next;
		temp->next=temp->prev;
		temp->prev=t;
		prev=temp;
		temp=temp1;
	}
	return prev;
}


