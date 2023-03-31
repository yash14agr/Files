#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
    struct node *prev;
}*head=NULL;


void creation(struct node *p)
{
    int x;

        struct node *t;
        t=(struct node *)malloc(sizeof(struct node));

        printf("\nEnter a value: ");
        scanf(" %d",&x);

        t->data=x;
        t->prev=NULL;
        t->next=NULL;
        head=t;
}


void insertion_beg(struct node *p)
{
    int pos=1,x;
    struct node *t;
    t=(struct node *)malloc(sizeof(struct node));

    printf("\nEnter the value: ");
    scanf("%d",&x);

    t->data=x;
    t->prev=NULL;
    t->next=p;
    p->prev=t;
    head=t;
}

void insertion_mid(struct node *p)
{
    int pos,i,x;
    printf("\nEnter the position: ");
    scanf("%d",&pos);
    int n=node_count(head);

    if(pos>n || pos<=1)
    {
        printf("Invalid position");
    }
    else
    {
            printf("Enter the value: ");
            scanf("%d",&x);
            struct node *t;
            t=(struct node *)malloc(sizeof(struct node));

            for(i=1;i<pos-1;i++)
            {
                p=p->next;
            }

            t->data=x;
            t->next=p->next;
            t->prev=p;

            if(p->next!=NULL)
            {
                p->next->prev=t;
            }
            p->next=t;
    }
}


void insertion_end(struct node *p)
{
    int n=node_count(head);
    int pos=n+1,x,i;
        printf("\nEnter the value: ");
        scanf("%d",&x);

        struct node *t;
        t=(struct node *)malloc(sizeof(struct node));

        for(i=1;i<pos-1;i++)
        {
            p=p->next;
        }

        t->data=x;
        t->next=p->next;
        t->prev=p;
        p->next=t;
}
/*
void insertion(struct node *p)
{
    int n=node_count(head);

    if(n==0)
    {
        printf("\nLinked list not created.");
    }
    else
    {
        int pos,x,i;
        printf("\n\nEnter the position: ");
        scanf("%d",&pos);

        if(pos==1)
        {
            struct node *t;
            t=(struct node *)malloc(sizeof(struct node));

            printf("Enter the value: ");
            scanf("%d",&x);

            t->data=x;
            t->prev=NULL;
            t->next=p;
            p->prev=t;
            head=t;

        }
        else
        {
            printf("Enter the value: ");
            scanf("%d",&x);

            struct node *t;
            t=(struct node *)malloc(sizeof(struct node));

            for(i=1;i<pos-1;i++)
            {
                p=p->next;
            }

            t->data=x;
            t->next=p->next;
            t->prev=p;

            if(p->next!=NULL)
            {
                p->next->prev=t;
            }
            p->next=t;

        }
    }
}
*/


void deletion(struct node *p)
{
    int pos;
    int n=node_count(head);
    if(n==0)
    {
        printf("\nLinked list is not created");
    }

    else
    {
        printf("\nEnter the position you want to delete: ");
        scanf("%d",&pos);

        struct node *t;
        t=head;

        if(n==1)
        {
            head=NULL;
        }
        else
        {

            if(pos==1)
            {
                t->next->prev=NULL;
                head=t->next;
            }
            else if(pos==n)
            {
                for(int i=0;i<pos-1;i++)
                {
                    t=t->next;
                }
                t->prev->next=NULL;
            }
            else
            {
                for(int i=0;i<pos-1;i++)
                {
                    t=t->next;
                }
                int previous,next;
                previous=t->prev;
                next=t->next;

                t->next->prev=previous;
                t->prev->next=next;
            }
        }
    }
}


void reverse(struct node *p)
{
    int n=node_count(head);

    if(n==0)
    {
        printf("\nLinked list is not created");
    }
    else
    {
        struct node *temp=NULL;
        struct node *t=head;

        while(t!=NULL)
        {
            t=t->next;
            temp = p->next;
            p->next = p->prev;
            p->prev = temp;
            p=t;

            if(t!=NULL && t->next==NULL)
            {
                head = t;
            }
        }
    }
}

int search(struct node *p)
{
    int x,n=node_count(head);
    if(n==0)
    {
        printf("\nLiked list not created");
        return -1;
    }
    else
    {
        printf("\nEnter the value: ");
        scanf("%d",&x);
        int count=1;
        while(p)
        {
            if(p->data==x)
            {
                printf("\n%d is present at address %d and %d node",x,p,count);
                return 1;
            }
            p=p->next;
            count++;
        }
        return 0;
    }

}


void sort(struct node *p)
{
    int n=node_count(head);

    if(n==0)
    {
        printf("\nLinked list is not created");
    }
    else
    {
        struct node *t;
        int temp;

        while(p)
        {
            t=p->next;
            while(t!=NULL)
            {
                if(t->data < p->data)
                {
                    temp=p->data;
                    p->data=t->data;
                    t->data=temp;
                }
                t=t->next;
            }
            p=p->next;
        }
    }
}


void sort_node(struct node *p)
{
    int n=node_count(head),temp;

    if(n==0)
    {
        printf("\nLinked list is not created");
    }
    else
    {
        struct node *t;

        for(int i=1;i<n;i++)
        {
            t=head;
            for(int j=0;j<=n-1;j++)
            {
                struct node *before,*after;
                if(t->data > t->next->data)
                {
                    before=t->prev;
                    after=t->next;
                    if(before!=NULL)
                    {
                        before->next=after;
                    }
                    t->next=after->next;

                    t->prev=after;
                    after->next=t;
                    after->prev=before;
                }
                temp=t;
                t=t->next;

                }
            }
        }
}

int node_count(struct node *p)
{
    int count=0;
    while(p!=NULL)
    {
        count ++;
        p=p->next;
    }
    return count;
}


void traversal(struct node *p)
{
    printf("\nLinked list: ");
    while(p!=NULL)
    {
        printf("\t%d--%d--%d",p->prev,p->data,p->next);
        p=p->next;
    }
}


//**************************************
//***************STACK********************

void insertion(struct node *p)
{
    struct node *t;
    t=(struct node *)malloc(sizeof(struct node));
    int x;
    printf("\nEnter a value: ");
    scanf(" %d",&x);

    if(p==NULL)
    {
        t->data=x;
        t->next=NULL;
        t->prev=NULL;
    }
    else
    {
        t->data=x;
        t->next=p;
        t->prev=NULL;
        p->prev=t;
    }
}

void traversal_stack(struct node *p)
{
    printf("\nLinked list: ");
    while(p!=NULL)
    {
        printf("\t%d--%d--%d",p->prev,p->data,p->next);
        p=p->next;
    }
}

int main()
{
    int x,y,n,s,a,b;


        printf("Select your choice:\n 1.Doubly Linked List\n 2.Doubly Linked Stack\n 3.Doubly Linked Queue\n");
        scanf("%d",&a);

        switch(a)
        {

            case 1:
                while(1)
                {
                    printf("Choose the operation to perform :\n 1.Creation\n 2.Insertion\n 3.Deletion\n 4.Reverse\n 5.Search\n 6.Sort\n");
                    scanf(" %d",&x);

                switch(x)
                {
                    case 1:
                        creation(head);
                        traversal(head);
                        break;

                    case 2:
                        y=0;
                        n=node_count(head);
                        if(n==0)
                        {
                            printf("Linked list not created");
                        }
                        else
                        {
                        while(y!=4)
                        {
                            printf("\n\nEnter your choose: \n 1.Insertion at begining\n 2.Insertion in middle\n 3.Insertion at end\n 4.Exit\n");
                            scanf("%d",&y);
                            switch(y)
                            {

                            case 1:
                                insertion_beg(head);
                                traversal(head);
                                break;

                            case 2:
                                insertion_mid(head);
                                traversal(head);
                                break;

                            case 3:
                                insertion_end(head);
                                traversal(head);
                                break;

                            }
                        }
                        }
                        break;

                    case 3:
                        deletion(head);
                        traversal(head);
                        break;

                    case 4:
                        reverse(head);
                        traversal(head);
                        break;

                    case 5:
                        s=search(head);
                        if(s==0)
                        {
                            printf("\nThe given value is not present in the list");
                        }
                        break;

                    case 6:
                        sort(head);
                        traversal(head);
                        break;

                    }
                    printf("\n----------------------------------------------------------------------------------------------\n\n");
                }
                break;

        case 2:
            while(1)
            {
                printf("\nChoose the operation to perform:\n 1.Insertion\n 2.Deletion\n 3.Top value\n 			4.Search\n");
                scanf(" &d",&x);
		
                switch(x)
                {
                case 1:
                    insertion(head);
                    break;
                case 2:
                	break;
                }

                printf("\n----------------------------------------------------------------------------------------------\n\n");
            }
    }
    return 0;
}
