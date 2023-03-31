//removing allocation of lowest need process.

#include<stdio.h>

#define n 5
#define resource 3
void print();
void Bankeralgo();
void RemoveLowestNeedProcess ();
int allocation[5][3] = {{0, 1, 0},     // Allocation Matrix
                          {2, 0, 0}, 
                          {3, 0, 2}, 
                          {2, 1, 1},  
                          {0, 0, 2}}; 

  int max_matrix[5][3] = {{7, 5, 3},    // MAX Matrix
                          {3, 2, 4},  
                          {9, 0, 2},  
                          {2, 2, 4},  
                          {4, 3, 3}}; 

  int available[3] = {3, 3, 2}; // Available Resources
  int Backupavailable[3]; 
  int need[n][resource];
  
  
int main()
{
	//need array
  	for (int i = 0; i < n; i++)
	{
	  for (int j = 0; j < resource; j++)
	    need[i][j] = max_matrix[i][j] - allocation[i][j];
	}
  
	print();
	Bankeralgo();

}


void Bankeralgo()
{
  int i, j, k;  
  int ans[n];                
  int ind = 0;
  int final[n];
  for (int k = 0; k < n; k++)
  	{
    	final[k] = 0;
  	}
  for(int i=0;i<resource;i++)
		Backupavailable[i]=available[i];
		
		
  for (k = 0; k < n; k++)
  {
    for (i = 0; i < n; i++)
    {
      if (final[i] == 0)
      {

        int flag = 0;
        for (j = 0; j < resource; j++)
        {
          if (need[i][j] > available[j])
          {
            flag = 1;
            break;
          }
        }

        if (flag == 0)
        {
          ans[ind++] = i;
          for (int y = 0; y < resource; y++)
            available[y] += allocation[i][y];
          final[i] = 1;
          break;
        }
      }
    }
  }

  int flag = 1;

  for (int i = 0; i < n; i++)
  {
    if (final[i] == 0)
    {
      flag = 0;
      printf("\ndeadlock found!\n");
      break;
    }
  }
  if(flag==0)
  {
  	for(i=0;i<resource;i++)
  		available[i]=Backupavailable[i];		//storing original data in available.
  	RemoveLowestNeedProcess();				//deallocating instances from lowest need process.
  	print();
  	Bankeralgo();
  }

  if (flag == 1)
  {
    printf("\nNo deadlock!\n");
    for (i = 0; i < n - 1; i++)
      printf(" P%d ->", ans[i]);
    printf(" P%d", ans[n - 1]);
  }
  printf("\n");
  
  
}

//print function to print everything
void print()
{
  int i,j;
  printf("Process\tAllocation\tMaximum need\tneed\tAvailable\n");
  for( i=0;i<n;i++)
  {
  	printf("P%d\t",i);
  	for( j=0 ; j<resource ; j++ )
  		printf("%d ",allocation[i][j]);
  	printf("\t\t");
  	for(j=0 ; j<resource ; j++)
  		printf("%d ",max_matrix[i][j]);
  	printf("\t\t");
  	for(j=0 ; j<resource ; j++)
  		printf("%d ",need[i][j]);
  	printf("\t");
  	if(i==0)
  	{
  		for(j=0 ; j<resource ; j++)
  			printf("%d ",available[j]);
  	}
  	printf("\n");	
  }
}

//function to remove allocation of lowest need process after getting deadlock.
void RemoveLowestNeedProcess () {
	int min = 0, MinNeed=0;
	for(int i=0;i<resource;i++)
	{
		MinNeed+=need[0][i];
	} 
	
	for(int i = 0; i < n; i++) {
		if( need[i][0]+need[i][1]+need[i][2] < MinNeed) {
			MinNeed = need[i][0]+need[i][1]+need[i][2] ;
			min = i;
		}
	}

	for(int i=0;i<resource;i++)
	{
		available[i]+=allocation[min][i];
		need[min][i]+=allocation[min][i];
		max_matrix[min][i]+=allocation[min][i];
		allocation[min][i]=0;
	}
	
	printf("\nAllocation from P%d is removed!\n\n",min);
}
