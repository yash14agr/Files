#include<stdio.h>
#include<stdlib.h>
struct Node
{
    int data;
    struct Node* next; 
};

struct Node* create_node()
{
    struct Node* head=(struct Node*)malloc(sizeof(struct Node));
    if(head==NULL)
    {
        printf("Node NOt created");
    }
    else{
        printf("Node created\n");
        return head;
    }

}
struct Node* insertAtBeg(struct Node * head, int val)
{
    struct Node* ptr= create_node();
    ptr->data=val;
    ptr->next=head;
    head=ptr;
    return head;
}

void insertAtEnd(struct Node ** head, int val)
{
    struct Node* ptr= create_node();
    ptr->data=val;
    ptr->next=NULL;
    
    struct Node* q= *head;
    if(*head==NULL)
    {
        *head=ptr;
        return;
    }
    
    while(q->next!=NULL)
    {
        q=q->next;
    }
    q->next=ptr;
    

}
void deleteNode(struct Node** head_ref, int key)
{
    struct Node *temp = *head_ref;
    struct Node *prev;

    if(temp==NULL)
    {
        printf("List already empty\n");
        return;
    }
    if (temp != NULL && temp->data == key) {
        *head_ref = temp->next; 
        free(temp);
        return;
    }
   
    while (temp != NULL && temp->data != key) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL)
        return;
        
    prev->next = temp->next;
    free(temp); 
}

void traversal(struct Node* head)
{
    if(head==NULL)
    {
        printf("List is empty\n");
        return;
    }
    printf("printing list--> ");
    while(head!=NULL)
    {
        printf("%d  address-> %p  ",head->data, head->next);
        head=head->next;
    }
    printf("\n");
}
int main()
{
    int key,l=1,val;
    struct Node* head=create_node();

    if(head!=NULL)
    {
    
    head=NULL;

    while(l)
    {
        printf("Enter 1 to insert element at beginning of linked-list\n");
        printf("Enter 2 to insert element at end of linked-list\n");
        printf("Enter 3 to delete element in linked-list\n");
        printf("Enter 4 to Exit Function\n");

        scanf("%d",&key);

        switch(key)
        {
            case 1: printf("Enter a number to be inserted at beginning in the linked-list\n");
                    scanf("%d",&val);
                    head=insertAtBeg(head,val);
                    traversal(head);
                    break;
            case 2: printf("Enter a number to be inserted at beginning in the linked-list\n");
                    scanf("%d",&val);
                    insertAtEnd(&head,val);
                    traversal(head);
                    break;
            case 3: printf("Enter a element to be deleted from linked-list\n");
                    scanf("%d",&val);
                    deleteNode(&head,val);
                    traversal(head);
                    break;
            case 4: l=0; break;
        }

    
    }
    }//if end
    

}

