#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>
int main()
{
	int pid,i,j;
	pid=fork();
	if(pid==0){
		printf("Process ID of Child is %d\n",getpid());
		printf("Process ID of parent of this Child is %d\n",getppid());
			
	}	
	else
	{
		printf("Process ID of Parent is %d\n",getpid());
		printf("Process ID of parent of this Parent is %d\n",getppid());
	}
}
