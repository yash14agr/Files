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
	int c=99,fd;
	size_t sz,sz1;
	char *c1=(char*)calloc(100,sizeof(char));
	char c2;
	char *string=(char*)calloc(100,sizeof(char));
	struct stat info;
	while(c !=0 )
	{
	
	printf("\n1.Create file\n2.Open file\n3.open and write file\n4.Open and read file\n5.printing reverse order\n6.searching a pattern\n7.Delete a file\n8.accessing info using stat\n9.accessing info using fstat\n10.exit\n");
	
	scanf("%d",&c);
	switch(c){
 
	 	case 1:	
	 		fd=creat("f1.txt",0777);
	 		printf("fd=%d\n",fd);
	 		close(fd);
 			break;
 		case 2:
 			fd=open("f1.txt",O_RDONLY|O_CREAT,07777);
 			printf("fd=%d\n",fd);
 			close(fd);
 			break;
 		case 3:
 			fd=open("f1.txt",O_WRONLY|O_CREAT,07777);
 			sz=write(fd,"hi yash",strlen("hi yash"));
 			printf("Size of file=%ld\n",sz);
 			close(fd);
 			break;
 		case 4:
 			fd=open("f1.txt",O_RDONLY);
 			sz=read(fd,c1,10);
 			printf("size of file is=%ld\n",sz);
 			printf("fd=%d\n",fd);
 			c1[sz]='\0';
 			printf("%s\n",c1);
 			close(fd);
 			break;
 		case 5:
 			fd=open("f1.txt",O_RDONLY,0777);
 			sz=lseek(fd,0,2);		//lseek(file pointer,0th position,SEEK_END)	sz:contains length of string
 			
 			//sz=lseek(fd,-1,1);		//lseek(fd,goes to -1 position,SEEK_CURRENT)
 			printf("size of %ld\n",sz);
 			printf("Reverse String is :");
 			
 			while(sz!=0)
 			{
 				read(fd,&c2,1);	//(fd,where you want to save char, no. of char)
 				printf("%c",c2);
 				lseek(fd,-2,1);  	//after read fd goes to next char, so use -2 to go to previous char
 				sz--;	
 			}
 			close(fd);
 			printf("\n");
 			break;
 		
 		case 6:
 			fd=open("f1.txt",O_RDONLY,0777);
 			printf("Enter String:\n ");
 			scanf("%s",string);
 			sz1=lseek(fd,0,2);
 			close(fd);
 			
 			fd=open("f1.txt",O_RDONLY,0777);
 			sz=read(fd,c1,sz1);
 			if(strstr(c1,string) != NULL)
 			{
 				printf("String '%s' is present in file!\n",string);
 			}
 			else{
 				printf("String '%s' is not present in file!\n",string);
 			}
 			close(fd);
 			break;
 		case 7:
 			fd=unlink("f1.txt");
 			printf("%d",fd);
 			break;
 		case 8:
			if(stat("/",&info)!=0)
				printf("Error");
			else
			{
				printf("inode: %d\n", (int)info.st_ino);
				printf("dev id: %d\n", (int)info.st_dev);
				printf("links: %ld\n", info.st_nlink);
				printf("uid: %d\n", (int)info.st_uid);
				printf("gid: %d\n", (int)info.st_gid);
				printf("mode: %08x\n", info.st_mode);
			}
			break;
 		case 9:
 			fstat(0,&info);
 			printf("inode: %d\n", (int)info.st_ino);
				printf("dev id: %d\n", (int)info.st_dev);
				printf("links: %ld\n", info.st_nlink);
				printf("uid: %d\n", (int)info.st_uid);
				printf("gid: %d\n", (int)info.st_gid);
				printf("mode: %08x\n", info.st_mode);
				break;
 			
 		case 10:
 			exit(0);
		}
	}
 		 	
}
