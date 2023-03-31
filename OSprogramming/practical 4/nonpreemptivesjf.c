//Non-preemptive SJF

#include<stdio.h>

int min(int a[],int n ,int b[]);
int sum(int a[], int n);

int main()
{
	int n,i,z=0,arrived_index,counter=0,smallest_burst_index,smallest_burst=1000;

	
	printf("Enter number of processes:");
	scanf("%d",&n);
	
	int turn_around_time[n];
	int t_arrival[n];
	int t_burst[n];
	int t_burst1[n];
	int minimum_of_burst[n];
	int index_minimum_of_burst[n];
	
	printf("Enter Arrival time of %d processes:\n",n);
	for (i=0;i<n;i++){
		scanf("%d",&t_arrival[i]);
	}
	printf("Enter burst time of %d processes:\n",n);
	for (i=0;i<n;i++){
		scanf("%d",&t_burst[i]);
		t_burst1[i]=t_burst[i];
	}
	printf("Gantt-Chart For Non-Preemptive sjf:\n");
	int j=0;
	while(sum(t_burst,n)!=0)
	{
		
		j=0;
		for(i=0;i<n;i++)
		{
			if(t_arrival[i]<=counter && t_burst[i]!=0 )
			{
				
				minimum_of_burst[j]=t_burst[i];
				index_minimum_of_burst[j]=i;
				j++;	
			}
		}
		
		arrived_index=min(minimum_of_burst, j ,index_minimum_of_burst);
		printf("|%d-p%d ",counter,(arrived_index+1));
		counter+=t_burst[arrived_index];
		t_burst[arrived_index]=0;
		
		turn_around_time[arrived_index]=counter-t_arrival[arrived_index];
		z++;
			
	}
	printf("|%d\n\n\n",counter);
	
	int avg_turn_around_time=0,avg_waiting_time=0;
	printf("Turn-around-time\n");
	for(i=0;i<n;i++)
	{
		avg_turn_around_time+=turn_around_time[i];
		printf("P%d : %d \n",i+1,turn_around_time[i]);
	}
	printf("\nwaiting-time\n");
	for(i=0;i<n;i++)
	{
		avg_waiting_time+=turn_around_time[i]-t_burst1[i];
		printf("P%d : %d \n",i+1,turn_around_time[i]-t_burst1[i]);
	}
	printf("\nAverage turn-around-time: %f\nAverage waiting-time: %f\n",((float)avg_turn_around_time/n),((float)avg_waiting_time/n));
		
}


int min(int a[],int n ,int b[])
{
	int minimum=a[0],i,index=0;
	/*for(i=0;i<n;i++){
		printf("%d|%d ",b[i],a[i]);
	}*/
	for(i=1;i<n;i++)
	{
		if(a[i]<minimum)
		{
			index=i;
			minimum=a[i];
		}

	}
			//printf("......index value:%d.....\n",index);
	return b[index];		//index of smallest burst time.
}

int sum(int a[], int n)
{
	int res=0;
	for(int i=0;i<n;i++)
	{
		res+=a[i];
	}
	return res;
}
