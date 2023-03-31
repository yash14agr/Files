#include<stdio.h>

// #define n 5;
// #define resource 3;
void print(int allocation[][3], int max_matrix[][3],int available[], int need[][3],int n,int resource );

int main()
{
  int i, j, k;
  int n=5;
  int resource=3;                   
  int allocation[5][3] = {{0, 1, 0},     // Allocation Matrix
                          {2, 0, 0}, 
                          {3, 0, 2}, 
                          {2, 1, 1},  
                          {0, 0, 2}}; 

  int max_matrix[5][3] = {{7, 5, 3},    // MAX Matrix
                          {3, 2, 2},  
                          {9, 0, 2},  
                          {2, 2, 2},  
                          {4, 3, 3}}; 

  int available[3] = {3, 3, 2}; // Available Resources
  

  int final[n], ans[n], ind = 0; // final array
  for (k = 0; k < n; k++)
  {
    final[k] = 0;
  }
  int need[n][resource];           //need Array
  for (i = 0; i < n; i++)
  {
    for (j = 0; j < resource; j++)
      need[i][j] = max_matrix[i][j] - allocation[i][j];
  }
  print(allocation,max_matrix,available,need,n,resource);
  
  
  
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
      printf("\nSystem is not Safe!\n");
      break;
    }
  }

  if (flag == 1)
  {
    printf("\nSystem is Safe!\n");
    for (i = 0; i < n - 1; i++)
      printf(" P%d ->", ans[i]);
    printf(" P%d", ans[n - 1]);
  }
  printf("\n");

  return 0;
}


void print(int allocation[][3], int max_matrix[][3],int available[], int need[][3],int n,int resource )
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
