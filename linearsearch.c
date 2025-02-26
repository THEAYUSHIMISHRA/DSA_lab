#include<stdio.h>
#include<process.h>
int main()
{
	int arr[20],i,n,flag=0,ele;
	printf("enter the size of array");
	scanf("%d",&n);
	printf("enter the elements");
	for(i=0;i<n;i++)
		scanf("%d",&arr[i]);
	printf("enter the element to be searched");
	scanf("%d",&ele);
	for(i=0;i<n;i++)
	{
		if(arr[i]==ele)
		{
			printf("found at %d",i);
			flag=1;
			break;
		}
	}
	if(flag==0)
		printf("not found");
	printf("elements are:");
	for(i=0;i<n;i++)
		printf("%d\t",arr[i]);
}