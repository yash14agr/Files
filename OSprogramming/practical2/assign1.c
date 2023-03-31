#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<errno.h>
#include<unistd.h>
#include<string.h>
#include<sys/types.h>
#include<sys/stat.h>



int main()
{    
	int fd;
	size_t sz;
	fd=creat("file1.txt",07777);
	printf("File 'file1' is created\n");
	write(fd,"start\n",sizeof("start\n"));
	lseek(fd,4096,SEEK_SET);
	write(fd,"\nEnd",sizeof("\nend"));
	sz=lseek(fd,0,2);
	printf("Size of file is :%ld\n",sz);
}
