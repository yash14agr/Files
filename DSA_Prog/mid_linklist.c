#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
};
typedef struct node list;
list* create();
int length(list *temp);
void mid(list *head);
void traverse(list *p);

int main()
{
    int flag=1,data;
    list* head=NULL;
    while(flag!=0)
    {
    	printf("Enter the data you want to insert:\n");
    	scanf("%d",&data);
        list* temp=create();
        temp->data=data;
        if(head==NULL)
        {
        	temp->next=NULL;
        	head=temp;	
        }
        else
        {
		temp->next=head;
		head=temp;
        }
        printf("Press 0 to exit:\n");
        scanf("%d",&flag);
    }
    traverse(head);
    mid(head);

    return 0;
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
		return q;
	}
}


int length(list *temp)
{
    int count=0;
    while(temp)
    {
        count ++;
        temp=temp->next;
    }
    return count;
}

void mid(list *head)
{
    int i,n=length(head);
    for(i=0;i<n/2;i++)
    {
        head=head->next;
    }
    printf("\nMiddle value of list is:%d\n",head->data);
}

void traverse(list *p)
{
	printf("Linked list:  ");
	if(p==NULL)
	{
		printf("list is empty.\n");
	}
	while(p != NULL)
	{
		printf("%d|%p   ",p->data,p->next); 							
		p=p->next;
	}
	printf("\n");
}

