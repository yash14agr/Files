#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>

int main(){
	pid_t pid;
	int i,array[100];
 	int fd[2],n;
	printf("Enter number of elements:");
 	scanf("%d",&n);
 	
 	if(pipe(fd) == -1){
  		printf("pipe creation FAILED");
  		return 1;
 	}
 	pid=fork(); 
 	
 	if(pid <0)
 	{
 		printf("Fork failed\n");
 		return 1;
 	}
 	else if(pid == 0)
 	{
 		 //printf("\n..........................\n");
 		printf("\nChild process running!\n");
 		printf("..........................\n");
  		close(fd[0]);
  		
 		array[0] = 0;
 		array[1] = 1; 
 		for( i = 2;i < n; i++)
 		{
  	 		array[i]=array[i-1]+array[i-2];
 		}
 		printf("\nFibonacci series:\n");
 		
 		for(i = 0;i <n; i++){
  			printf("%d ",array[i]);
 		}
 		write(fd[1],array,10*sizeof(int));
 		printf("\nchild process terminates!\n");
 		printf("..........................\n");
 	}
 	else if (pid > 0)
 	{
 		
  		close(fd[1]);
  		wait(NULL);
  		//printf("\n..........................\n");
  		printf("\n\nParent process running!\n");
  		printf("..........................\n");
  		read(fd[0], array, 10*sizeof(int));
  		printf("\nPrinting Even Numbers:\n");
  		for(int i = 0;i < n; i++){
 	   		if((array[i]%2)==0)
      			printf("%d ",array[i]);
 		}
 		printf("\nPrinting Odd Numbers:\n");
 		for(int i = 0;i<n; i++){
   			if((array[i]%2)!=0)
		      	printf("%d ",array[i]);
		}
		printf("\nParent process terminates!\n");
		printf("\n..........................\n");
 	}
 	
 	return 0;
}

