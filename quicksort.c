#include<stdio.h>
#include<process.h>
#include<stdlib.h>
void quicksort(int arr[10],int first,int last)
{
	int i,j,temp,pivot;
	if(first<last)
	{ 
	   pivot=first;
	   i=first;
	   j=last;
	   while(i<j)
	   {
		   	while((arr[i]<=arr[pivot])&& i<last))
		   	      i++;
		   	while(arr[j]>arr[pivot])
				 j--;
		    if(i<j)
			{	
			    temp=arr[i];
			    arr[i]=arr[j];
			    arr[j]=temp;
			}
	   }
	   temp=arr[pivot];
	   arr[pivot]=arr[j];
	   arr[j]=temp;
	   quicksort(arr,0,j-1);
	   quicksort(arr,j+1,last);
	}	
}
int main()
{
	int arr[10];
	int i,n;
	printf("enter the size");
	scanf("%d",&n);
	printf("enter elements");
	for(i=0;i<n;i++)
	{
	  scanf("%d ",&arr[i]);
    }
    quicksort(arr,0,(n-1));
    printf("\nafter sorting\n");
	for(i=0;i<n;i++)
	{
	  printf("%d",&arr[i]);
	}
	return 0;
}