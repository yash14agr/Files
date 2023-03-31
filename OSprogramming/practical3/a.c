/*#include<stdio.h>
//#include<stdlib.h>
//#include<fcntl.h>
//#include<errno.h>
#include<sys/types.h>
#include<unistd.h>
//#include<string.h>

void forkexample()
{
	if(fork() == 0)
	printf("Hello From Child!\n");
	else
	printf("Hello From Parent\n");
	
}


int main()
{
	//while(1);
	//write(2,"Hi Yash!\n",strlen("Hi Yash!\n"));	
	
	//fork();
	//fork();
	//fork();
	//printf("Hello\n");
	
	forkexample();
	
	return 0;
}	
*/

/*#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>

int main()
{
	int pid,i,j;
	pid=fork();
	if(pid == 0)
	{
		for(i=0;i<1000;i++)
		printf("Hello from Child\n");
	}
	else
	{
		for(i=0;i<1000;i++)
		printf("Hello from Parent\n");
	}
}*/


/*#include<stdio.h>
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
}*/
/*
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
	if(pid==0)
	{
		for(i=0;i<5;i++)
		sum=sum+a[i];	
		printf("sum in child: %d\n",sum);
	}	
	else
	{
		wait(&status);
		for(i=5;i<10;i++)
		sum=sum+a[i];
		printf("sum in parent: %d\n",sum);
		
	}
	
	
	
}*/

/*
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
	if(pid==0)
	{
		waitpid(-1,&status,0);
		for(i=0;i<5;i++)
		sum=sum+a[i];	
		printf("sum in child: %d\n",sum);
	}	
	else
	{
		waitpid(-1,&status,0);
		for(i=5;i<10;i++)
		sum=sum+a[i];
		printf("sum in parent: %d\n",sum);	
	}
}
*/
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

