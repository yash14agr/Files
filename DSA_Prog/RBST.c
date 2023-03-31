#include<stdio.h>
#include<stdlib.h>

struct node
{
int keyVal;
struct node *leftNode;
struct node *rightNode;
};
typedef struct node list;
//
list *getNode(int data);
list *insert(list *rootNode, int data);
void inorder(list* rootNode) ;
void preorder(list* rootNode);
void postorder(list* rootNode);
//list* createNode(value);
//list* insertLeftNode(list* rootNode, int data);
//list* insertRightNode(list* rootNode, int data);
list* searchElement(list* tree, int value);
list* delete(list *tree,int value);
list* findLargestElement(list *tree);

//
list *getNode(int data)
{
	list* newNode =(list*)malloc(sizeof(list));
	newNode->keyVal = data;
	newNode->leftNode = NULL;
	newNode->rightNode = NULL;
	return newNode;
}

//
list *insert(list *rootNode, int data)
{
	if(rootNode == NULL)
	return getNode(data);

	if(rootNode->keyVal < data)
	{
		rootNode->rightNode = insert(rootNode->rightNode,data);
	}
	else if(rootNode->keyVal > data)
		rootNode->leftNode = insert(rootNode->leftNode,data);
	return rootNode;
}

//
void inorder(list* rootNode)
{
	if (rootNode == NULL) 
		return;
	inorder(rootNode->leftNode);
	printf("%d ->", rootNode->keyVal);
	inorder(rootNode->rightNode);
}
//
void preorder(list* rootNode)
{
	if (rootNode == NULL) 
		return;

	printf("%d ->", rootNode->keyVal);
	preorder(rootNode->leftNode);
	preorder(rootNode->rightNode);
}
//
void postorder(list* rootNode)
{
	if (rootNode == NULL) 
		return;
	postorder(rootNode->leftNode);
	postorder(rootNode->rightNode);
	printf("%d ->", rootNode->keyVal);
}
//
/*
list* createNode()
{
	list* newNode =(list*)malloc(sizeof(list));
	newNode->leftNode = NULL;
	newNode->rightNode = NULL;
	return newNode;
}


list* insertLeftNode(list* rootNode, int data)
{
rootNode->leftNode = createNode(data);
return rootNode->leftNode;
}
//
list* insertRightNode(list* rootNode, int data)
{
rootNode->rightNode = createNode(data);
return rootNode->rightNode;
}
*/
//
list* searchElement(list* tree, int value)
{
    if((tree->keyVal==value)||tree==NULL)
     return tree;
    else
    {
        if(value<tree->keyVal)
        return searchElement(tree->leftNode,value);
        else
        return searchElement(tree->rightNode,value);
    }
}
list* findLargestElement(list *tree)
{
	if( (tree == NULL) || (tree->rightNode == NULL))
		return tree;
	else
		return findLargestElement(tree->rightNode);
}

list* delete(list *tree,int value)
{
 	if(tree==NULL)
 		printf("\nValue not found in the tree");
 	else if (value<tree->keyVal)
 		delete(tree->leftNode,value);
 	else if (value>tree->keyVal)
  		delete(tree->rightNode,value);
  	else if (tree->leftNode && tree->rightNode)
  	{
      		list* temp=findLargestElement(tree->leftNode);
      		tree->keyVal=temp->keyVal;
      		delete(tree->leftNode,temp->keyVal);
     
  	}
  	else
  	{
  		list* temp=tree;
  		if (tree->leftNode==NULL && tree->rightNode==NULL)
  		{
  			tree==NULL;
  		}
  		else if (tree->leftNode!=NULL)
  		{
  			tree=tree->leftNode;
  		}
  		else
  		{
  			tree=tree->rightNode;
  		}
  		free(temp);
  	}
}

//
int main()
{
	int option,data;
	list* tree=NULL;

//list* head=create();
//list* head1=NULL;
//head=NULL;
//printf("Address of node: %p\n",head);

while(1)
{   
	printf("\nwhich operation u want to perform on binary search tree(bst)?\n");
	printf("1.insert a node in BST\n2.delete a node from BST\n3.inorder walk\n4.preorder walk\n5.postorder walk\n6.height\n7.count\n8.search\n9.exit\n");
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
                	printf("Enter the data you want to delete:\n");
			scanf("%d",&data);
                	delete(tree,data);
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
			printf("u selected height\n");

			break;
		case 7:
   			printf("u selected count\n");

			break;
		case 8:
   			printf("Enter the element you want to search:\n");
			scanf("%d",&data);

			break;
		case 9:
			exit(0);
		default:
			printf("Invalid option.\n");
	}
}
}
