#include<stdio.h>
#include<stdlib.h>

struct tree
{
int data;
int balance;
struct tree *left;
struct tree *right;
};
typedef struct tree tree;

tree* insertion(tree* rootnode,int data);
tree* rightrotate(tree* rootnode);
tree* leftrotate(tree* rootnode);
void preorder(tree* rootnode);
void postorder(tree* rootnode);
int height(tree* rootnode);
tree* create();
int cal_bal(tree* rootnode);

int main()
{
	
	tree* rootnode=NULL;
	int a[10]={1,2,3,10,5,6,7,8,9,4}

	for(int i=0;i<n;i++)
	{
		rootnode=insertion(rootnode,a[i]);
	}
	printf("\ntraversing using preorder:");
	preorder(rootnode);
	print("\ntraversing using postorder: ");
	postorder(rootnode);
	
	
	
	
}

tree* create()
{
	tree* temp;
	temp=(tree*)malloc(sizeof(tree));
	temp->left=NULL;
	temp->right=NULL;
	return temp;
}


tree* insertion(tree* rootnode,int data)
{
	
	if(rootnode==NULL)
	{
		rootnode=create();
		rootnode->data=data;
		rootnode->balance=0;
	}
	else if(data<rootnode->data)
	{
	rootnode->left=insertion(rootnode->left,data);
	rootnode->balance= cal_bal(rootnode);
	}
	else if(data>rootnode->data)
	{
	rootnode->right=insertion(rootnode ->right,data);	
	rootnode->balance= cal_bal(rootnode); 	
	}
	
	int balance_temp = height(rootnode->left) - height(rootnode->right);	
	if(balance_temp>1 && data<rootnode->left->data)
	{
		printf("As the BSL is unbalanced\nWe are performing Right Rotation\n");
		return rightrotate(rootnode);
	}
	if(balance_temp<-1 && data>rootnode->right->data)
	{
		printf("As the BSL is unbalanced\nWe are performing left Rotation\n");
		return leftrotate(rootnode);
	}
	if(balance_temp<-1 && data<rootnode->right->data)
	{
		printf("As the BSL is unbalanced\nWe are performing Right left Rotation\n");
		rootnode->right=rightrotate(rootnode->right);
		return leftrotate(rootnode);
	}
	if(balance_temp>1 && data>rootnode->left->data)
	{
		printf("As the BSL is unbalanced\nWe are performing left Right Rotation\n");
		rootnode->left=leftrotate(rootnode->left);
		return rightrotate(rootnode);
	}
	
	return rootnode;
}

tree* rightrotate(tree* rootnode)
{
	tree* temp= rootnode->left;
	tree* temp1=temp->right;
	temp->right=rootnode;
	rootnode->left=temp1;
	rootnode->balance=cal_bal(rootnode);
	temp->balance=cal_bal(temp);
	return temp;	
}

tree* leftrotate(tree* rootnode)
{
	tree* temp=rootnode->right;
	tree* temp1=temp->left;
	temp->left=rootnode;
	rootnode->right=temp1;
	rootnode->balance=cal_bal(rootnode);
	temp->balance=cal_bal(temp);
	return temp;
}

void preorder(tree* rootnode)
{
	if(rootnode!=NULL)
	{
		printf("%d(%d)-> ",rootnode->data,rootnode->balance);
		preorder(rootnode->left);
		preorder(rootnode->right);
	}
}

void postorder(tree* rootnode)
{
	if(rootnode!=NULL)
	{
		postorder(rootnode->left);
		postorder(rootnode->right);
		printf("%d(%d)-> ",rootnode->data,rootnode->balance);
	}
}



int cal_bal(tree* rootnode)
{
	if(rootnode==NULL)
	return -1;
	else
	return height(rootnode->left) - height(rootnode->right);
}

