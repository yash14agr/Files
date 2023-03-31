//we want to find how many times given element occurs in array using shared_memory concept.

#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>
#include<sys/wait.h>
#include<sys/stat.h>
#include<sys/shm.h>
int main() 
{
	int pid;
	int segment_id;
	int status;
	int *shared_memory;			//pointer
	int element;
	const int size=4096;
	
	int arr[20]={1,2,5,4,5,2,7,8,9,2,6,5,13,14,17,2,16,4,3};
	int n=20;
	
	printf("Elements of Array are:\n");
	for(int i=0;i<n;i++)
	{
		printf("%d ",arr[i]);
	}
	
	printf("\nEnter the element you want to search:\n");
	scanf("%d",&element);
	
	segment_id=shmget(IPC_PRIVATE,size,S_IRUSR | S_IWUSR);			//creating a shared_memory
	
	shared_memory= (int *) shmat(segment_id, NULL, 0);			//attaching shared_memory to processor (here attaching it to NULL) 
	
	pid=fork();
	if(pid == 0)								//child
	{
		for(int i=n/2 ; i<n ; i++)					//child will search for next half of array
		{
			if(arr[i] == element)
			(*shared_memory)++;
		}
	}	
	else					//parent
	{
		for(int i=0 ; i<n/2 ; i++)					//parent will search for 1st half of array
		{
			if(arr[i] == element)
			(*shared_memory)++;
		}
		wait(&status);
		printf("Element %d is present exactly %d times in array: ",element,*shared_memory);
	}
	
	shmdt(shared_memory);
	shmctl(segment_id, IPC_RMID, NULL);
	
}
