#include<stdio.h>
#include<stdlib.h>
#include<time.h>
void copy(int*,int*,int);
void print(int*,int);
void swap(int*,int,int);
void ascending(int*,int);
void descending(int*,int);
void randomm(int*,int);
void almost_sorted(int*,int);
void selection(int*,int);
void bubble(int*,int);
void insertion(int*,int);
void shell(int*,int);
void count_sort();
void main()
{
    int *a,n,choice1,i,*b,choice2,choice;
    printf("Enter size of array: ");
    scanf("%d",&n);
    a=(int*)calloc(n,sizeof(int));
    b=(int*)calloc(n,sizeof(int));
    jump:
    printf("Enter choice code to select the type of input:\n1.Ascending order.\n2.Descending order.\n3.Random elements.\n4.Almost sorted\t\n");
    scanf("%d",&choice1);
    switch(choice1)
    {
        case 1: ascending(a,n);
        	print(a,n);
                break;
        case 2: descending(a,n);
        	print(a,n);
                break;
        case 3: randomm(a,n);
        	print(a,n);
                break;
        case 4: almost_sorted(a,n);
        	print(a,n);
                break;
        default: printf("**PLEASE ENTER VALID INPUT**\n");

    }
    //before performing function start clock and after calling eg. selection sort then end clock and minus the both start and end time to calculate time required to run the program.
    while(1)
    {
        copy(a,b,n);
        // call copy function here
        printf("Select type of sorting to be performed:\n1.Selection sort.\n2.Bubble sort.\n3.Insertion sort.\n4.Shell sort.\n5.Counting sort.\n6.To change input.\n7.EXIT\t");
        scanf("%d",&choice2);
        //printf("Printing unsorted array...\n");
       // print(b,n);
        switch(choice2)
        {
            case 1:selection(b,n);
                   break;
            case 2:bubble(b,n);
                   //print(b,n);
                   break;
            case 3:insertion(b,n);
                   print(b,n);
                   break;
            case 4:shell(b,n);
                   //print(b,n);
                   break;
            case 5:count_sort();
                   //print(a,n);
                   break;
            case 6:goto jump;
                   break;
            case 7:exit(1);
            default : printf("INVALID INPUT\n");
        }
    }
}
void copy(int*a,int*b,int n)
{
    int i;
    for(i=0;i<n;i++)
    {
        b[i]=a[i];
    }
}
void print(int*b,int n)
{
    int i;
    printf("The array is: ");
    for(i=0;i<n;i++)
    {
        printf("%d\t",b[i]);
    }
    printf("\n");
}
void swap(int *a,int x,int y)
{
    int temp;
    temp=a[x];
    a[x]=a[y];
    a[y]=temp;
}
void ascending(int*a,int n)
{
    int i;
    for(i=0;i<n;i++)
    {
        a[i]=i;

    }
    //print(a,n);
}
void descending(int*a,int n)
{
    int i,j=0;
    for(i=n-1;i>=0;i--)
    {
        a[i]=j;
        j++;
    }
}
void randomm(int*a,int n)
{
    int i;
    for(i=0;i<n;i++)
    {
        a[i]=rand()%100;
    }
}
void almost_sorted(int*a,int n)
{
    int i,g,k=0;
    ascending(a,n);
    printf("Enter gap size: ");
    scanf("%d",&g);
    k=g;
    for(i=1;i<=n;i++)
    {
        a[k-1]=rand()/100;
        k=g*(i+1);
    }
}
void input_count(int*a,int n)
{
    int i,y,z;
    printf("Enter any choice\n 1.Best case\n2.Worst case\t");
    scanf("%d",&y);
    switch(y)
    {
        case 1: printf("Enter one number for best case: ");
                scanf("%d",&z);
                for(i=0;i<n;i++)
                {
                    a[i]=z;
                }
        break;
        case 2: for(i=0;i<n-1;i++)
                {
                    a[i]=i;
                }
                a[n-1]=10000;
        break;
        default: printf("**Invalid choice**");


    }
}
void selection(int *b,int n)
{
    clock_t start,end;
    start = clock();
    int i,j,temp;
    for(i=0;i<n-1;i++)
    {
        for(j=i+1;j<n;j++)
        {
            if(b[j]<b[i])
            {
                temp=b[i];
                b[i]=b[j];
                b[j]=temp;
            }
        }
    }
    end = clock();
    printf("The time taken by selection sort is %f\n",(double)((end-start)/CLOCKS_PER_SEC));
}
void bubble(int *b,int n)
{
    clock_t start,end;
    start = clock();
    int i,j,temp;
    for(i=0;i<n;i++)
    {
        for(j=0;j<n-(i+1);j++)
        {
            if(b[j+1]<b[j])
            {
                temp=b[j+1];
                b[j+1]=b[j];
                b[j]=temp;
            }
        }
    }
    end = clock();
    printf("The time taken by Bubble sort is %f\n",(double)((end-start)/CLOCKS_PER_SEC));
    //print(b,n);
}
void insertion(int*b,int n)
{
    clock_t start,end;
    start = clock();
    int i,j,key;
    for(i=1;i<n;i++)
    {
        j=i-1;
        key=b[i];
                  //here for best case i.e for ascending ordered input the complexity is of order 'n', because for best case input it would not
                  //go into while loop as the condition do not satisfy hence there will be complexity due to first for loop.//

        while(j>=0 && b[j]>key)
        {
            b[j+1]=b[j];
            j--;
        }
        b[j+1]=key;
    }
    end = clock();
    printf("The time taken by Insertion sort is %f\n",(double)((end-start)/CLOCKS_PER_SEC));
    printf("CLOCKS = %ld\n",(end-start));
    //print(b,n);
}
void shell(int *b,int n)
{
    clock_t start,end;
    start = clock();
    int i,j,gap,temp,x;
    printf("Enter gap: ");
    scanf("%d",&x);
    for(gap=n/x;gap>=1;gap=gap/2)
    {
        for(j=gap;j<n;j++)
        {
            for(i=j-gap;i>=0;i=i-gap)
            {
                if(b[i+gap]>b[i])
                {
                    break;
                }
                else
                {
                    swap(b,i+gap,i);
                }
            }
        }
    }
    end = clock();
    printf("The time taken by Shell sort is %f\n",(double)((end-start)/CLOCKS_PER_SEC));
}
void count_sort()
{
    int *array,n,i,x;
    printf("Enter no of elements for sorting: ");
    scanf("%d",&n);
    array=(int*)calloc(n,sizeof(int));
    printf("Choose input:\n1.Best Case\n2.Worst Case:\t");
    scanf("%d",&x);
    switch(x)
    {
        case 1: for(i=0;i<n;i++)
                {
                    array[i]=5;
                }
        break;
        case 2: for(i=0;i<n-1;i++)
                {
                    array[i]=i;
                }
                array[n-1]=1000;
        break;
        default: printf("**INVALID INPUT**");
    }
    //best case is that the when max value of input is less as we need less space for count array like if we have 50 elements of any value between 1-10
    //ex. 5 => it makes count array of size 5 as it requires less memory hence best case.

    //worst case : when one element is much larger than other elements ex. 1,2,1,1,3,7,7,8,5,8,3,9,10000....here it makes count array of size 10000 hence worst case.
    //take another inputs in this function itself.
    clock_t start,end;
    start = clock();
    int *b,*count,max;
    max=array[0];
    for(i=1;i<n;i++)
    {
       if(max<array[i])
       {
           max=array[i];
       }
    }
    b=(int*)calloc(n,sizeof(int));
    count=(int*)calloc((max+1),sizeof(int));
    for(i=0;i<n;i++)
    {
        count[array[i]]=count[array[i]]+1;
    }
    for(i=1;i<=max;i++)
    {
        count[i]=count[i-1]+count[i];
    }
    for(i=n-1;i>=0;i--)
    {
        b[--count[array[i]]]=array[i];
    }
    end = clock();
    printf("The time taken by Count sort is %f\n",(double)((end-start)/CLOCKS_PER_SEC));
    copy(b,array,n);
}
