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
   int fd,fd1;
   char filename[100];
   size_t sz;
   
   printf("Enter the filename to open for reading \n");
   scanf("%s",filename);
   
   // Open one file for reading
   fd=open(filename,O_RDONLY|O_CREAT,07777);
   sz=lseek(fd,0,2);
   printf("Size of %s: %ld\n",filename,sz);
   lseek(fd,0,0);
   
   char *c1=(char*)calloc(sz,sizeof(char));
   read(fd,c1,sz);
   c1[sz]='\0';
   printf("Content in %s:\n",filename);
   printf("%s\n",c1);
   
   printf("Enter the filename to open for writing \n");
   scanf("%s", filename);
   
   // Open another file for writing
   fd1=open(filename,O_WRONLY|O_CREAT,07777);
   
   write(fd1,c1,sz);
   printf("\nContents copied to %s...\n", filename);
   close(fd);
   close(fd1);
   
   fd1=open(filename,O_RDONLY,0777);
   sz=lseek(fd,0,2);
   read(fd,c1,sz);
   printf("Contents of %s:\n",filename);
   printf("%s\n",c1);
   close(fd1);
   return 0;
}
