//gcc reader_writer.c -lpthread
#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>

void *writer();
void *reader();
pthread_mutex_t mVar=PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t wrt=PTHREAD_MUTEX_INITIALIZER;
int reader_count=0;
int writer_data=0;

int main()
{
	pthread_t tid_writer[20],tid_reader[20];
	int r=0,w=0;
	int i=0;
	printf("\nEnter number of writers:");
	scanf("\n%d",&w);
	printf("\nEnter number of reader:");
	scanf("\n%d",&r);
	
	for(i=0 ; i<w ; i++)
	{
		pthread_create(&tid_writer[i],NULL,writer,NULL);
	}
	for(i=0 ; i<r ; i++)
	{
		pthread_create(&tid_reader[i],NULL,reader,NULL);
	}	
	for(i=0 ; i<w ; i++)
	{
		pthread_join(tid_writer[i],NULL);
	}
	for(i=0 ; i<r ; i++)
	{
		pthread_join(tid_reader[i],NULL);
	}
	pthread_mutex_destroy(&mVar);
	pthread_mutex_destroy(&wrt);
	return 0;
	
}

void *writer()
{
	int i;
	pthread_mutex_lock(&wrt);
	writer_data++;
	
	printf("\nWriter is Writing :%d\n",writer_data);
	
	pthread_mutex_unlock(&wrt);
	
}

void *reader()
{
	pthread_mutex_lock(&mVar);
	reader_count++;
	if(reader_count == 1)
	{
		pthread_mutex_lock(&wrt);
	}	
	
	pthread_mutex_unlock(&mVar);
	printf("\nReader is reading.....%d\n",writer_data);
	//writer_data++;
	pthread_mutex_lock(&mVar);
	reader_count--;
	if(reader_count == 0)
	{
		pthread_mutex_unlock(&wrt);
	}
	pthread_mutex_unlock(&mVar);
}		
