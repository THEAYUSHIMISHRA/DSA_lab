#include<stdio.h>
void selection(int *,int);
void main()
{
	int a[10],n,i;
	printf("enter the size of elements\n");
	scanf("%d",&n);
	printf("enter number of elements\n");
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	selection(a,n);
	printf("sorted array is:\n");
	for(i=0;i<n;i++)
		printf("%d\t",a[i]);
}
void selection(int a[],int n)
{
	int i,j,temp,min;
	for(i=0;i<n-1;i++)
	{
		min=i;
		for(j=i+1;j<n;j++)
			if(a[j]<a[min])
				min=j;
		temp=a[i];
		a[i]=a[min];
		a[min]=temp;
	}
}















































