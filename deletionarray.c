#include<stdio.h>
int main()
{
	int arr[20],i,n,pos,ele;
	printf("enter the size of array");
	scanf("%d",&n);
	printf("enter the elements");
	for(i=0;i<n;i++)
		scanf("%d",&arr[i]);
	printf("enter the position and element to be deleted");
	scanf("%d%d",&pos,&ele);
	for(i=pos-1;i<n-1;i++)
		arr[i]=arr[i+1];
	n=n-1;
	printf("elements are:");
	for(i=0;i<n;i++)
		printf("%d\t",arr[i]);
}