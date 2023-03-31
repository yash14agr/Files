#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>
#include<sys/wait.h>
int main()
{
	int pid,i,j;
	int a[10]={1,2,3,4,5,6,7,8,9,10};
	int sum=0;
	int status;
	pid=fork();
	if(pid!=0)
	{
		for(i=0;i<100;i++)
		sum=sum+i;	
		waitpid(-1,&status,0);
		printf("sum: %d\n",sum);
	}	
	else
	{
		for(i=0;i<100;i++)
		printf("Hello!!! ");	
	}
}

