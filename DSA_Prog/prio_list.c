#include<stdio.h>
#include<stdlib.h>

struct node
{
	int data;
	int priority;
	struct node *next;
};
typedef struct node list; 
list* create();
list* insert(list* head,int data,int prio);
list *delete(list *head);
void traverse(list *p);

int main()
{
	list*head=NULL;
	int choice,data,prio;
	while(1)
	{
		printf("Enter 1 to insert\nEnter 2 to delete\nEnter 3 to display\nEnter 4 to exit\n");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
				printf("Enter data to be inserted and its priority:\n");
				scanf("%d %d",&data,&prio);
				head=insert(head,data,prio);
				break;
			case 2:
				head= delete(head);
				break;
			case 3:
				traverse(head);
				break;
			case 4:
				break;
			
		}
		if (choice==4)
		break;	
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

list* insert(list* head,int data,int prio)
{
	list*newnode=create();
	newnode->data=data;
	newnode->priority=prio;
	if(head==NULL || prio < head->priority)
	{
		newnode->next=head;
		head=newnode;
	}
	else
	{
		list* temp=head;
		while(temp->next != NULL && temp->next->priority <= prio)
			temp=temp->next;
		newnode->next=temp->next;
		temp->next=newnode;
	}
	return head;
	
}

list *delete(list* head)
{
	if(head==NULL)
	{
		printf("List is empty.\n");
		return head;
	}	
	else
	{
		list* temp=head;
		head=head->next;
		free(temp);	
	}
	return head;
}

void traverse(list *p)
{
	if(p==NULL)
	{
		printf("list is empty.\n");
	}
	while(p != NULL)
	{
		printf("%d|%d|%p   ",p->data,p->priority,p->next);
		p=p->next;
	}
	printf("\n");
}
