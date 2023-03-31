#include<stdio.h>
#include<stdlib.h>

struct node
{
int data;
struct node *next;
struct node *prev;
};
typedef struct node list;

list* create();
list* insertatbeg(list *head,int data);
list* insertatend(list *head,int data);
list* insertatpos(list* head,int data);
list* deletionfrombeg(list* head);
list* deletionfrompos(list* head,int data);
list* deletionfromend(list* head);
void traverse( struct node *p);
list* reverse(list* head);
int length(list* head);
void searching(list* head,int val);
list* copy(list* head);
void sortlist(list* head);
list* concatenate(list* head,list* head1);
list* insert_ordered(list *head,int data);

int main()
{
int option,choice,choice1,choice2,choice3,data,data1,data2,count=0;

list* head=create();
list* head1=NULL;
head=NULL;
printf("Address of node: %p\n",head);

while(1)
{   printf("which operation u want to perform on doubly linked list?\n");
printf("1.insert\n2.delete\n3.traverse\n4.length\n5.reverse\n6.searching\n7.copy\n8.Sorting\n9.concatenation\n10.linked-stack\n11.linked-queue\n12.exit\n");
scanf("%d",&option);
switch(option)
{
case 1:
                while(1)
                {printf("u selected INSERTION!!\n");
printf("enter 1 for inserting element at beginning.\nenter 2 for inserting at a particular position.\nenter 3 for inserting element at end.\nenter 4 for insert ordered\n5.enter 5 for exit\n");
scanf("%d",&choice);
printf("Enter the data you want to insert:\n");
scanf("%d",&data);

                switch(choice)
          {
              case 1:
                    head=insertatbeg(head,data);
                    break;
              case 2:
                   head=insertatpos(head,data);
                   break;
              case 3:
                   head=insertatend(head,data);
                   break;
              case 4:
                   head=insert_ordered(head,data);
                   break;
              case 5:
                   break;
                   
          }
          if(choice==5)
              break;
         
                }
          break;

        case 2:
               while(1)
               {
                   printf("u selected DELETION\n");
                printf("enter 1 for deleting element at beginning.\nenter 2 for deleting element at a particular position.\nenter 3 for deleting element at end.\nenter 4 for exit\n");
scanf("%d",&choice1);
switch(choice1)
          {
              case 1:
                    head=deletionfrombeg(head);
                    break;
              case 2:
                   head=deletionfrompos(head,data);
                   break;
              case 3:
                   deletionfromend(head);
                   break;
              case 4:
                   //deleteordered();
                   break;
          }
          if(choice1==4)
               break;
         
               }
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
head1=copy(head);
break;
case 8:
    sortlist(head);
    break;
case 9:
  head=concatenate(head,head1);
    break;
case 10:
while(1)
                {
            printf("Implementing linked-stack.\n");
                 
                    printf("1.Insertion\n2.Deletion\n3.traverse\n4.stop implementation of linked-stack.\n");
                    scanf("%d",&choice2);

                    switch(choice2)
                    {
                    case 1:
                        printf("Enter the data you want to insert:\n");
                        scanf("%d",&data1);
                        head=insertatbeg(head,data);
                    break;
                    case 2:
                        head=deletionfrombeg(head);
                    break;
                    case 3:
                        traverse(head);
                    break;
                    case 4:
                    break;
                    }
                    if(choice2==4)
                    break;
                    }
                    break;
                    case 11:
                    while(1)
                        {
                        printf("Implementing linked-queue.\n");
                       
                        printf("1.Insertion\n2.Deletion\n3.traverse\n4.stop implementation of linked-queue.\n");
                        scanf("%d",&choice3);

                        switch(choice3)
                        {
                        case 1:
                                printf("Enter the data you want to insert:\n");
                                scanf("%d",&data2);
                                head=insertatbeg(head,data);
                        break;
                        case 2:
                                head=deletionfromend(head);
                        break;
                        case 3:
                            traverse(head);
                        break;
                        case 4:
                        break;
                        }
                        if(choice2==4)
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

while(p != NULL)
{
printf("%d|%p   ",p->data,p->next);
p=p->next;
}
printf("\n");
}


list* insertatbeg(list *head,int data)
{list* temp=create();
   temp->data = data;
   if(head==NULL)
   {
       temp->prev = NULL;
       temp->next = NULL;
       head=temp;
   }
   else
   {head->prev = NULL;
   temp->next = head;
   head->prev=temp;
   head = temp;
   return head;
   }
}

list* insertatend(list *head,int data)
{
list* temp = create();
list* temp1=head;

temp->data=data;
temp->next=NULL;
if(head==NULL)
{
temp->next=NULL;
temp->prev=NULL;
head=temp;
}
else{
   temp1=head;
while(temp1->next!=NULL)
{
temp1=temp1->next;
}
temp1->next=temp;
temp->prev=temp1;
return head;

} //printf("temp->next=%p\n address of temp=%p\n,head->next=%p\n",temp->next,temp,head->next);

}

list* insertatpos(list* head,int data)
{
list* temp=head;
int i=0,pos;
printf("Enter position at which you want to insert element:\n");
scanf("%d",&pos);
while((i < pos-1) && (temp!=NULL))
{
temp=temp->next;
i=i+1;
}
if((temp!=NULL) && (i=pos-1))
{   list* temp1 = create();
temp1->data = data;
temp1->next = temp->next;
temp1->prev = temp;
(temp->next)->prev = temp1;
temp->next = temp1;
}
else{
   
printf("position not found.\n");
return head;
}
}

list* deletionfrombeg(list* head)
{
if(head==NULL)
{
printf("list is empty.\ndeletion not possible.\n");
return head;
}
if(head->next==NULL)
{   //key=head->data;
printf("deleting element %d\n",head->data);
free(head);
return NULL;
}
list* temp=head;
//key=temp->data;
printf("deleting element %d\n",temp->data);
head=head->next;
head->prev=NULL;
free(temp);
return head;
}


list* deletionfrompos(list* head,int pos)
{
list* temp=head;
list* hold;
int k=0;
printf("enter position at which u want to delete the element");
scanf("%d",&pos);
if(temp==NULL)
{
printf("list is empty.\ndeletion not possible.\n");
return NULL;
}

while(k <(pos-1))
{
    temp=temp->next;
    if(temp==NULL)
      {printf("Node in the list less than the position");
 break;}
k++;
}
hold=temp->next->next;
int key=temp->next->data;
free(temp->next);
temp->next=hold;
hold->prev=temp;
printf("deleted key is %d", key);
return head;
}

list* deletionfromend(list* head)
{

if(head==NULL)
{
printf("list is empty.\ndeletion not possible.\n");
return head;
}
if(head->next==NULL)
{   //key=head->data;
printf("deleting element %d\n",head->data);
free(head);
return NULL;
}
list* temp=head;
//list* prev;
while(temp->next !=NULL)
{
//prev=temp;
temp=temp->next;
}
//prev->next=NULL;
temp->prev->next=NULL;
list* copy(list* head)
{
list *temp=head;
list *copy=create();
copy=NULL;
while(temp!=NULL) //1|123123 2|14141 3|14215132 4|NULL
{ //1|NULL 2|
copy=insertatend(copy,temp->data);
temp=temp->next;
}
printf("Copied linked list is: ");
traverse(copy);
return copy;
}

void sortlist(list* head)
{
    list* hold= head;
    int count=0;
    int i=0;
    while(hold!=NULL)
    {
        hold=hold->next;
        count++;
    }
    while(i<(count-1))
    {
        list* temp=head;
        while ((temp->next)!=NULL)
        {
            if ((temp->data)>(temp->next->data))
             {
             int k=temp->data;
             temp->data = temp->next->data;
             temp->next->data =k;
             }
             temp=temp->next;
        }
        i++;
    }
}

/* list* concatenate(list* a,list* b) // copied list is used as 2nd linked list. so first we execute copy then //concatinate original and copied list.
{ //eg. original LL: 1|2187 2|91247 3|NULL
    if( a != NULL && b!= NULL ) //use copy. copied list: 1|2187 2|91247 3|NULL
    { //then concatenate to get: 1|2187 2|91247 3|29812 1|2975 2|8275 3|NULL
        if (a->next == NULL)
            a->next = b;
        else
            concatenate(a->next,b);
        return a;
    }
    else
    {
        printf("Either 1st linked list or 2 linked list is NULL\n");
        return a;
    }

}
*/


list* concatenate(list* head,list* head1)
{
/*if(head==NULL || head1 == NULL)
{
printf("either 1st or 2nd linked-list is empty.\n");
return head;
}
else
{
list* temp=head;
while(temp->next!=NULL)
{
temp=temp->next;
}
temp->next=head1;
return temp;
}*/

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



list* insert_ordered(list* head,int data) //not applicable for case when data is greater than every element of list
{ //eg. list: 10|123abd2 20|147bd1 30|17412ab8 40|NULL //want to insert 50, segmentation fault.
    list*tempnew=create();
tempnew->data=data;
if(head==NULL)
{
   return tempnew;
}
if (head->data >= tempnew->data )
{
    tempnew->next=head;
    return tempnew;

    }
    list* temp=head;
// Check for Proper Position.
while( (temp!=NULL) &&(temp->next->data<=tempnew->data))
{
temp=temp->next;
}
tempnew ->next = temp->next;
  temp->next = tempnew;
  return head;
}
