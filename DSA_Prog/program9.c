#include<stdio.h>
#include<stdlib.h>

/*
struct node
{
	int data;
	struct node *next;
}
*/

void BFS(int graph[][6],int x,int visited[],int n);
void DFS(int graph[][6], int x, int visited[],int n);

int main()
{
	int graph[6][6]={{0,1,1,0,0,0},
 			 {1,0,0,1,1,0},   	
			 {1,0,0,0,1,0},
			 {0,1,0,0,1,1},
			 {0,1,1,1,1,1},
			 {0,0,0,1,1,0}}; 
	int visited[6];
	int option,x=0,n=6;
	printf("Adjance matrix: \n");
	for(int i=0;i<6;i++)
	{
		for(int j=0;j<6;j++)
		{
			printf("%d ",graph[i][j]);
		}
		printf("\n");
	}
	for(int i=0;i<6;i++)
	{
		visited[i]=0;
	}
	while(1)
	{
		printf("1.DFS\n2.BFS\n3.Terminte\n");
		scanf("%d",&option);
		
		switch(option)
		{
			case 1:
				x=0;
				printf("you selected DFS\n");
				printf("The starting element is 0.\n");
				DFS(graph,x,visited,n);
				printf("\n");
				for(int i=0;i<6;i++)
				{
					visited[i]=0;
				}
				break;
			case 2:
				x=0;
				printf("you selected DFS\n");
				printf("The starting element is 0.\n");
				BFS(graph,x,visited,n);
				printf("\n");
				for(int i=0;i<6;i++)
				{
					visited[i]=0;
				}
				break;
			case 3:
				exit(0);
		}
	}
}

void DFS(int graph[][6], int x, int visited[],int n)
{
	int vcount=0;
	visited[x]=1;
	printf("%d ",x);
	
	while(vcount < n)
	{
		if(graph[x][vcount] == 1 && visited[vcount] == 0)
		{
			DFS(graph,vcount,visited,n);		
		}
		vcount++;
	}
}

void BFS(int graph[][6],int x,int visited[],int n)
{
	int front=-1;
	int rear=-1;
	int vcount=0;
	printf("%d ",x);
	visited[x]=1;
	front++;
	rear++;
	int q[n];
	q[rear]=x;
	
	while(front <= rear)
	{

		x=q[front];
		front++;
		vcount=0;
		while(vcount < n)
		{
			if(graph[x][vcount] == 1 && visited[vcount]==0 )
			{
				visited[vcount]=1;
				printf("%d ",vcount);
				rear++;
				q[rear]=vcount;

			}
			vcount++;
		}
	}
	
}
