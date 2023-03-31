//gcc reader_writer.c -lpthread
//Producer Consumer Problem
#include <semaphore.h>
#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>

sem_t empty;
sem_t full;
void Initialize();
void WriteToBuffer();
void ReadFromBuffer();
void *producer_function();
void *consumer_function();
int counter=0;
#define BufferSize 5
int buffer[BufferSize];
#define MaxItems 5

pthread_mutex_t mVar;

int main()
{
	pthread_t producer[5],consumer[5];
	int j=0;

	Initialize();
	for(int i=0;i<5;i++){
	pthread_create(&producer[i],NULL,producer_function,&j);
	}
	for(int i=0;i<5;i++){
	pthread_create(&consumer[i],NULL,consumer_function,&j);
	}
        
        for(int i=0;i<5;i++)
        {
        pthread_join(producer[i], NULL);
        }
        
        for(int i=0;i<5;i++)
        {
        pthread_join(consumer[i], NULL);
	}
	
	pthread_mutex_destroy(&mVar);
	sem_destroy(&empty);
	sem_destroy(&full);
	return 0;
	
}


void Initialize()
{
        pthread_mutex_init(&mVar, NULL);
	sem_init(&empty,0,BufferSize);
	sem_init(&full,0,0);
	printf("initialization done!");

}

void WriteToBuffer()
{
	static int item=0;
	buffer[counter]=item;
	counter++;
	printf("\nProducer producing Item: %d\n",item);
	item++;
	printf("buffer: |");
	for(int i=0;i<counter;i++)
	{
		printf("%d |",buffer[i]);
	}
}

void ReadFromBuffer()
{

	counter--;
	int item=buffer[counter];

	printf("\nconsumer consuming Item: %d\n",item);
	printf("buffer: |");
	for(int i=0;i<counter;i++)
	{
		printf("%d |",buffer[i]);
	}
	
}

void *producer_function()
{
        sem_wait(&empty);
	pthread_mutex_lock(&mVar);
	
	WriteToBuffer();
       
        pthread_mutex_unlock(&mVar);
        sem_post(&full);
}

void *consumer_function()
{
        sem_wait(&full);
        pthread_mutex_lock(&mVar);
        
    	ReadFromBuffer();
    	
        pthread_mutex_unlock(&mVar);
        sem_post(&empty);
}
