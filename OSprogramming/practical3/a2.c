#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>

int main()
{
	int pid,i,j;
	pid=fork();
	if(pid == 0)
	{
		for(i=0;i<100;i++)
		printf("Hello from Child\n");
	}
	else
	{
		for(j=0;j<100;j++)
		printf("Hello from Parent\n");
	}
}
