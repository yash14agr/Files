//           4
 //      2         6
 //   1    3     5    7
 
 //level order: 4->2->6->1->3->5->7->                
 //preorder walk: 4 ->2 ->1 ->3 ->6 ->5 ->7 ->     (root L R)
 //postorder walk: 1 ->3 ->2 ->5 ->7 ->6 ->4 ->  (L R root)
 //inorder walk: 1 ->2 ->3 ->4 ->5 ->6 ->7 ->  (L root R)
 
#include<stdio.h>
#include<stdlib.h>

struct Tnode
{
int keyVal;
struct Tnode *left;
struct Tnode *right;
int height;
};
typedef struct Tnode list;
int max(int a, int b);
list *insert(list *rootNode, int data);
void inorder(list* rootNode) ;
void preorder(list* rootNode);
void postorder(list* rootNode);
int levelorder(list* rootNode);
list* createNode(int value);
list* insertLeftNode(list* rootNode, int data);
list* insertRightNode(list* rootNode, int data);
int searchElement(list* tree, int value,int level);
list*delete(list* rootNode,int value);
list*findLargestNode(list*root);
list*findsmallestelement(list*root);
int height(list*rootNode);
list* nodes_level(list* rootNode,int level);
int internalnodes(list*rootNode);
int externalnodes(list*rootNode);
int totalnodes(list*rootNode);
list*rightrotate(list*rootNode);
list*leftrotate(list*rootNode);
int calculate_bal(list*rootNode);

int main()
{
int option,data,count_choice,value,l,res2,res3,res4,level=0;
list*tree=NULL;
while(1)
{   printf("\nwhich operation u want to perform on binary search tree(bst)?\n");
printf("1.insert a node in BST\n2.delete a node from BST\n3.inorder walk\n4.preorder walk\n5.postorder walk\n6.levelorder\n7.height\n8.count\n9.search\n10.exit\n");
scanf("%d",&option);
switch(option)
{
case 1:
               
printf("u selected INSERTION!!\n");
printf("Enter the data you want to insert:\n");
scanf("%d",&data);
tree=insert(tree,data);
break;

        case 2:
               
                printf("u selected DELETION\n");
                printf("Enter the data you want to dlt:\n");
                scanf("%d",&value);
                tree=delete(tree,value);
                break;
         
        case 3:
                printf("u selected inorder walk\n");
                inorder(tree);
break;
case 4:
printf("u selected preorder walk\n");
preorder(tree);
break;
case 5:
printf("u selected postorder walk\n");
postorder(tree);
break;
case 6:
printf("u selected level order\n");
levelorder(tree);
break;
case 7:
printf("u selected height\n");
int res=height(tree);
printf("\nThe height of your tree is %d",res);
break;
case 8: printf("u selected count\n");
       while(l)
       {
       printf("\n1. enter 1 to count internal/parent nodes\n2. enter 2 to count external/leaf nodes.\n3. enter 3 to count total nodes\n.4 enter 4 for exit.\n ");
       scanf("%d", &count_choice);
       switch(count_choice)
       { case 1:
         res2=internalnodes(tree);
         printf("\nThe total internal nodes of your tree are %d",res2);
         break;
         case 2:
         res3=externalnodes(tree);
         printf("\nThe total external nodes of your tree are %d",res3);
         break;
         case 3:
         res4=totalnodes(tree);
         printf("\nThe total nodes of your tree are %d",res4);
         break;
         case 4: l=0;
         break;
        }
       }
   break;
case 9:
printf("Enter the element you want to search:\n");
scanf("%d",&data);
//temp=search(tree,data,level);
int r=searchElement(tree,data,level);
if(r==0)
{
    printf("Search unsuccessful");
}
else if(r==1)
{
    printf("Search successful. %d is present in bst",data);
    //printf("%d is present at level %d",data,levelorder(data));
}
break;
case 10:
exit(0);
default:
printf("Invalid option.\n");
}
}
}

list*rightrotate(list*rootNode)
{
list*x=rootNode->left;
list*z=x->right;
x->right=rootNode;
rootNode->left=z;
//updating heights
rootNode->height=height(rootNode);
x->height=height(x);
return x;
}

list*leftrotate(list*rootNode)
{

list*x=rootNode->right;
list*z=x->left;
x->left=rootNode;
rootNode->right=z;
rootNode->height=height(rootNode);
x->height=height(x);
return x;
}


list *insert(list *rootNode, int data)
{  
if (rootNode==NULL)
//Allocate memory for TREE
{//list*tree==NULL;
	//rootNode->keyVal==data, rootNode->left==NULL, rootNode->right==NULL;
	rootNode=createNode(data);
	rootNode->height = 0;
}
else if (data<rootNode->keyVal)
{
	rootNode->left = insert(rootNode->left, data);
}
else if( data > rootNode->keyVal)
{
	rootNode->right = insert(rootNode->right, data);
}
 int balance = height(rootNode->left)- height(rootNode->right);
// Left Left Case
if (balance > 1 && data < rootNode->left->keyVal)
{
return rightrotate(rootNode);
}
// Right Right Case
if(balance <-1 && data > rootNode ->right->keyVal)
{
return leftrotate(rootNode);
}
// Left Right Case
if(balance > 1 && data>rootNode->left->keyVal)
{
rootNode->left = leftrotate(rootNode->left);
return rightrotate(rootNode);
}
// Right Left Case

if(balance < -1 && data < rootNode->right->keyVal)
{
rootNode->right=rightrotate(rootNode->right);
return leftrotate(rootNode);
}
 return rootNode;
}

void inorder(list* rootNode)
{
if (rootNode == NULL)
return;
inorder(rootNode->left);
printf("%d ->", rootNode->keyVal);
inorder(rootNode->right);
}

void preorder(list* rootNode)
{
if (rootNode == NULL)
return;
printf("%d ->", rootNode->keyVal);
preorder(rootNode->left);
preorder(rootNode->right);
}

void postorder(list* rootNode)
{
if (rootNode == NULL) return;
postorder(rootNode->left);
postorder(rootNode->right);
printf("%d ->", rootNode->keyVal);
}

list*createNode(int data)
{
list* newNode = malloc(sizeof(list));
newNode->keyVal = data;
newNode->left = NULL;
newNode->right = NULL;
return newNode;
}

list* insertLeftNode(list* rootNode, int data)
{
rootNode->left = createNode(data);
return rootNode->left;
}

list* insertRightNode(list* rootNode, int data)
{
rootNode->right = createNode(data);
return rootNode->right;
}

int searchElement(list* tree,int value,int level)
{
    if(tree==NULL)
     {
         return 0;
     }
     else if(tree->keyVal==value)
     {
         
         printf("%d is present at %d level ",value,level);
         return 1;
     }
   
   
      else if(value<tree->keyVal)
        {
            return searchElement(tree->left,value,level+1);
        }
        else if(tree->keyVal<value)
        {
            return searchElement(tree->right,value,level+1);
        }
   
}

int max(int a, int b)
{
    return (a > b)? a : b;
}

list*delete(list* rootNode,int value)
{
  if (rootNode==NULL)
  {
      printf("\nValue not found in the tree");
      return rootNode;
  }
  else if (value<rootNode->keyVal)
  rootNode->left=delete(rootNode->left,value);
  else if (value>rootNode->keyVal)
  rootNode->right=delete(rootNode->right,value);
  else
  {
  if (rootNode->left == NULL)
        {
            list* temp = rootNode->right;
            free(rootNode);
            return temp;
        }
        else if (rootNode->right == NULL)
        {
            list* temp = rootNode->left;
            free(rootNode);
            return temp;
        }
 
        // node with two children:
        // Get the inorder successor
        // (smallest in the right subtree)
        list* temp = findsmallestelement(rootNode->right);
 
        // Copy the inorder
        // successor's content to this node
        rootNode->keyVal = temp->keyVal;
 
        // Delete the inorder successor
        rootNode->right = delete(rootNode->right, temp->keyVal);
    }
    //return rootNode;

    rootNode->height= max(height(rootNode->left),height(rootNode-> right))+1;
int balance = calculate_bal(rootNode);
 // Left Left Case
if (balance > 1 && calculate_bal(rootNode->left) >= 0)
{
    return rightrotate(rootNode);
}
// Left Right Case
if(balance > 1 && calculate_bal(rootNode->left) < 0)
{
    rootNode->left = leftrotate(rootNode->left);
return rightrotate(rootNode);
}
// Right Right Case
if (balance < -1 && calculate_bal(rootNode->right) <= 0)
{
    return leftrotate(rootNode);
}
// Right Left Case
if (balance < -1 && calculate_bal(rootNode->right) > 0)
{
    rootNode->right = rightrotate(rootNode->right);
return leftrotate(rootNode);
}

//if (balance < -1 && calculate_bal(rootNode->right)>0)
if (balance < -1 && value < rootNode-> right->keyVal)
{
rootNode->right = rightrotate(rootNode->right);
return leftrotate(rootNode);
}
return rootNode;
}

int calculate_bal(list*rootNode)
{
    int balance = height(rootNode->left)- height(rootNode->right);
    return balance;
}

int height(list* rootNode)
{   int leftheight;
    int rightheight;
    if(rootNode==NULL)
    {
        return -1;
    }
    if(rootNode->left==NULL && rootNode->right==NULL)
    {
        return 0;
    }
    leftheight=height(rootNode->left);
    rightheight=height(rootNode->right);
    if(leftheight>rightheight)
    {
        return leftheight+1;
    }
    else
    {
        return rightheight+1;
    }
}


int totalnodes(list*rootNode)
{
    if(rootNode==NULL)
    {
        return 0;
    }
    else
    {
        return(totalnodes(rootNode->left)+totalnodes(rootNode->right)+1);
    }
}

int internalnodes(list*rootNode)   //parent nodes
{
    if(rootNode==NULL)
    {
        return 0;
    }
    if(rootNode->left==NULL && rootNode->right==NULL)
   {
        return 0;
    }
    else
    {
        return (internalnodes(rootNode->left)+internalnodes(rootNode->right)+1);//1 for root node
    }
   
}


int externalnodes(list*rootNode)  //leaf nodes
{
    if(rootNode==NULL)
    {
        return 0;
    }
    if(rootNode->left==NULL && rootNode->right==NULL)
   {
        return 1;
    }
    else
    {
        return (externalnodes(rootNode->left)+externalnodes(rootNode->right));
    }
   
}


list*findLargestNode(list*rootNode)
{
    if(rootNode==NULL)
    return NULL;
    while(rootNode->right!=NULL)
    {
        rootNode=rootNode->right;
    }
    return rootNode;
}

list*findsmallestelement(list*rootNode)
{
    if(rootNode==NULL)
    return NULL;
    while(rootNode->left!=NULL)
    {
        rootNode=rootNode->left;
    }
    return rootNode;
}
int levelorder(list* rootNode)
{
    int level=0;
    int h=height(rootNode);
    while(level<=h)
    {
        nodes_level(rootNode,level);
        level=level+1;
    }
}

list* nodes_level(list* rootNode,int level)
{ //int data;
if(rootNode== NULL)
{
return NULL;
}
if(level==0)
{
    //rootNode->keyVal;
    printf("%d->",rootNode->keyVal);
}
else
{
nodes_level(rootNode->left, level-1);
nodes_level(rootNode->right, level-1);
}
}

