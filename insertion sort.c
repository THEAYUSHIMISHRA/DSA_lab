#include<stdio.h>
#include<conio.h>
#define max 10

void insert(int arr[],int n);
 
int main()
{
	int arr[max],i,n;
	printf("\nno. of elements= ");
	scanf("%d",&n);
	printf("enter elements= ");
	for(i=0;i<n;i++)
		scanf("%d",&arr[i]);
	for(i=0;i<n;i++)
		printf("%d\t",arr[i]);
	insert(arr,n);
	printf("\nsorted array :");
	for(i=0;i<n;i++)
		printf("%d\t",arr[i]);
}
void insert(int arr[10],int n)
{
	int i,j,k;
	for(i=1;i<n;i++)
	{
		j=i;
		k=arr[i];
		while((arr[j-1]>k)&& j>0)
		{
			arr[j]=arr[j-1];
			j=j-1;
		}
		arr[j]=k;	
	}
}
