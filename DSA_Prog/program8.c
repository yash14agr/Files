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
tree* create();
tree* insertion(tree* rootnode,int data);
void preorder(tree* rootnode);
void postorder(tree* rootnode);
void inorder(tree* rootnode);
int height(tree* rootnode);
void lvlorder(tree* rootnode);
void node_lvl(tree* rootnode,int lvl);
void search(tree* rootnode,int val,int lvl);
tree* largele(tree* rootnode);
tree* smallele(tree* rootnode);
tree* delete(tree* rootnode,int data);
int total_node(tree* rootnode);
int except_leaf(tree* rootnode);
int num_leaf(tree* rootnode);
tree* rightrotate(tree* rootnode); 
tree* leftrotate(tree* rootnode);
int cal_bal(tree* rootnode);

int main()
{
	int choice,data,choice2,lvl=0;
	tree* rootnode=NULL;
	tree*temp=rootnode;
	
	while(1)
	{
		printf("\n1.insertion\n2.display\n3.Height\n4.delete\n5.search\n6.counting nodes\n7.exit\n");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
				printf("Enter the data you want to insert.\n");
				scanf("%d",&data);
				rootnode=insertion(rootnode,data);
				break;
			case 2:
				printf("1.preorder\n2.postorder\n3.inorder\n4.levelorder\n");
				scanf("%d",&choice2);
				
				if(choice2==1)
				{
					printf("Root / left / right\n");
					preorder(rootnode);
				}
				else if(choice2==2)
				{
					printf("left / right / root\n");
					postorder(rootnode);
				}
				else if(choice2==3)
				{
					printf("left / root / right\n");
					inorder(rootnode);
				}
				else if(choice2==4)
				{
					printf("root / lvl\n");
					lvlorder(rootnode);
				}
				break;
			case 3:
				printf("Height of tree :%d\n",height(rootnode));
				break;
			case 4:
				printf("1.delete a node\n2.delete entire tree\n");
				scanf("%d",&choice2);
				if(choice2==1)
				{
					printf("Enter the data you want to delete.\n");
					scanf("%d",&data);
					rootnode=delete(rootnode,data);
				}
				else if(choice2==2)
				{
					rootnode=NULL;
					printf("Tree is deleted.\n");
				}
				else
					printf("Invalid choice.\n");
				break;
			case 5:
				printf("Enter the element you want to search.\n");
				scanf("%d",&data);
				search(rootnode,data,lvl);
				break;
			case 6:
				printf("1.leaf Node\n2.Non-leaf Node\n3.Total node\n");
				scanf("%d",&choice2);
				if(choice2==1)
					printf("total number of leaf node in BST: %d\n",num_leaf(rootnode));
				else if(choice2==2)
					printf("total number of Non-leaf node in BST: %d\n",except_leaf(rootnode));	
				else if(choice2==3)
					printf("total number of node in BST: %d\n",total_node(rootnode));	
				else
					printf("Invalid option.\n");
				break;
			case 7:
				break;
			default:
				printf("Invalid choice.\n");
		}
		if(choice==7)
		break;
	}
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
/*
{
	if(rootnode==NULL)
	{
		rootnode=create();
		rootnode->data=data;
	}
	else
	{
		if(data<rootnode->data)
		{
			rootnode->left=insertion(rootnode->left,data);
		}
		else
		{
			rootnode->right=insertion(rootnode->right,data);		
		}
	}
	return rootnode;
}*/

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

void inorder(tree* rootnode)
{
	if(rootnode!=NULL)
	{
		inorder(rootnode->left);
		printf("%d(%d)-> ",rootnode->data,rootnode->balance);
		inorder(rootnode->right);

	}
}

int height(tree* rootnode)
{
	if(rootnode==NULL)
		return -1;
	if(rootnode->left==NULL && rootnode->right==NULL)
		return 0;
	int lh=height(rootnode->left);
	int rh=height(rootnode->right);
	if(lh>rh)
		return lh+1;
	else
		return rh+1;
	
}
void lvlorder(tree* rootnode)
{
	int lvl=0;
	int h=height(rootnode);
	while(lvl<=h)
	{
		node_lvl(rootnode,lvl);
		lvl++;
	}
}

void node_lvl(tree* rootnode,int lvl)
{
	if(rootnode==NULL)
		return;
	if(lvl==0)
		printf("%d(%d)-> ",rootnode->data,rootnode->balance);
	else
	{
		node_lvl(rootnode->left,lvl-1);
		node_lvl(rootnode->right,lvl-1);
	}
}


void search(tree* rootnode,int val,int lvl)
{
	if(rootnode==NULL)
	{
		printf("%d not found.\n",val);
		return;
	}
	if(rootnode->data==val)
	{
		printf("%d is found at %d level.\n",val,lvl);
		
	}
	else if(val<rootnode->data)
	{
		search(rootnode->left,val,lvl+1);
	}
	else
	{
		search(rootnode->right,val,lvl+1);
	}
	
}

tree* delete(tree* rootnode,int data)		//inorder predecessor
{
	if(rootnode==NULL)
	{
		printf("%d not found in BST.\n",data);
	}
	else if(data < rootnode->data)
	{
		rootnode->left=delete(rootnode->left,data);
		rootnode->balance = cal_bal(rootnode);	
	}
	else if(data > rootnode->data)

	{
		rootnode->right=delete(rootnode->right,data);
		rootnode->balance = cal_bal(rootnode);		
	}
	else
	{
		/*
		 if (rootnode->left == NULL)
        	 {
            		tree* temp = rootnode->right;
            		free(rootnode);
            		return temp;
        	 }
        	 else if (rootnode->right == NULL)
          	 {
            		tree* temp = rootnode->left;
            		free(rootnode);
            		return temp;
        	 }
 
       	 // node with two children:
        	 // Get the inorder successor
        	 // (smallest in the right subtree)
        	 tree* temp = smallele(rootnode->right);
 
   		 // Copy the inorder
        	 // successor's content to this node
         	 rootnode->data = temp->data;
 
        	 // Delete the inorder successor
        	 rootnode->right = delete(rootnode->right, temp->data);
        	 }
     	return rootnode;
        	 */
        	 if(rootnode->left!=NULL && rootnode->right!=NULL)
        	 {
			tree* temp = largele(rootnode->left);
			rootnode->data=temp->data;
			rootnode->left=delete(rootnode->left,temp->data);
		 }
		 else
		{
			tree* temp = rootnode;
			if(rootnode->left==NULL && rootnode->right== NULL)
			{
			rootnode=NULL;
			}
			else if(rootnode->left!= NULL)	
			{	
			rootnode = rootnode->left;
			}
			else
			{
			rootnode = rootnode->right;
			}
			free(temp);
     		}
     	}
     	if(rootnode==NULL)
     	return rootnode;
     	
     	int balance_temp = cal_bal(rootnode);
     	
     	if(balance_temp > 1 && cal_bal(rootnode->left) >= 0)
     		return leftrotate(rootnode);
     		
     	if(balance_temp > 1 && cal_bal(rootnode->left) < 0)
     	{
     		rootnode->left = leftrotate(rootnode->left);
     		return rightrotate(rootnode);
        }  
     	if(balance_temp < -1 && cal_bal(rootnode->right) <= 0)
     		return leftrotate(rootnode);
     		
     	if(balance_temp < -1 && cal_bal(rootnode->right) > 0)
 	{
 		rootnode->right = rightrotate( rootnode->right); 
     		return leftrotate(rootnode);	
     	}
     	return rootnode;
}
int cal_bal(tree* rootnode)
{
	if(rootnode==NULL)
	return -1;
	else
	return height(rootnode->left) - height(rootnode->right);
}
tree* largele(tree* rootnode)
{
	if(rootnode==NULL || rootnode->right==NULL)
	{
		return rootnode;
	}
	else
	{
		return largele(rootnode->right);
	}
}

tree* smallele(tree* rootnode)
{
	if(rootnode==NULL || rootnode->right==NULL)
	{
		return rootnode;
	}
	else
	{
		return smallele(rootnode->left);
	}
}

int num_leaf(tree* rootnode)
{
	if(rootnode==NULL)
	{
		return 0;
	}
	if(rootnode->left==NULL && rootnode->right==NULL)
	{
		return 1;
	}	
	else
	{
		return (num_leaf(rootnode->left) + num_leaf(rootnode->right));
	}
}	

int except_leaf(tree* rootnode)
{
	if(rootnode==NULL)
	{
		return 0;
	}
	if(rootnode->left==NULL && rootnode->right==NULL)
	{
		return 0;
	}	
	else
	{
		return (except_leaf(rootnode->left) + except_leaf(rootnode->right) +1);
	}
}

int total_node(tree* rootnode)
{
	if(rootnode==NULL)
	return 0;
	else
	{
		return (total_node(rootnode->left) + total_node(rootnode->right) + 1 );
	}
}
