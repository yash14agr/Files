//preemptive Priority

#include<stdio.h>

int max_priority(int a[],int n ,int b[], int c[]) ;
int sum(int a[], int n);

int main()
{
	int n,i,z=0,arrived_index,counter=0;
	int previously_arrived_index=10000;

	
	printf("Enter number of processes:");
	scanf("%d",&n);
	
	int turn_around_time[n];
	for(int i=0;i<n;i++)
		turn_around_time[i]=0;
	int priority[n];
	int t_arrival[n];
	int t_burst[n];
	int t_burst1[n];
	int maximum_of_priority[n];
	int index_maximum_of_priority[n];
	
	printf("Enter priority of %d processes:\n",n);
	for (i=0;i<n;i++){
		scanf("%d",&priority[i]);
	}
	
	printf("Enter Arrival time of %d processes:\n",n);
	for (i=0;i<n;i++){
		scanf("%d",&t_arrival[i]);
	}
	printf("Enter burst time of %d processes:\n",n);
	for (i=0;i<n;i++){
		scanf("%d",&t_burst[i]);
		t_burst1[i]=t_burst[i];
	}
	printf("Gantt-Chart For Preemptive Priority:\n");
	int j=0;
	while(sum(t_burst,n)!=0)
	{
		
		j=0;
		for(i=0;i<n;i++)
		{
			if(t_arrival[i]<=counter && t_burst[i]!=0 )
			{
				maximum_of_priority[j]=priority[i];
				index_maximum_of_priority[j]=i;
				j++;	
			}
		}
		
		arrived_index=max_priority(maximum_of_priority, j ,index_maximum_of_priority,t_burst);
		if(previously_arrived_index != arrived_index)
			printf("|%d-p%d ",counter,(arrived_index+1));
		previously_arrived_index=arrived_index;
		counter++;
		t_burst[arrived_index]-=1;
		
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

/*
int max_priority(int a[],int n ,int b[], int c[]) 	//when 0 is lowest priority.	

{
	int maximum=a[0],i,index=0;
	
	for(i=1;i<n;i++)
	{
		if(a[i]>maximum || (a[i]==maximum && c[i]<c[index]) )
		{
			index=i;
			maximum=a[i];
		}
		

	}
	return b[index];		//index of smallest burst time.
}
*/
int max_priority(int a[],int n ,int b[], int c[]) 	//when 0 is highest priority 
{
	int minimum=a[0],i,index=0;
	
	for(i=1;i<n;i++)
	{
		if(a[i]<minimum || (a[i]==minimum && c[i]<c[index]) )
		{
			index=i;
			minimum=a[i];
		}
	}
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


