#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<errno.h>
#include<unistd.h>
#include<string.h>
#include<sys/types.h>
int main()
{
	int fd;
	fd=creat("f1.txt",0777);
	//printf("fd=%d"\n,fd);
	close(fd);
	
	fd=open("f1.txt",O_WRONLY,0777);
	sz= 
}
