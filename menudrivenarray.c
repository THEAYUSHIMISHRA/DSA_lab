#include<stdio.h>
#include<process.h>
int main()
{
	int arr[20],i,n,pos,ele,flag,ch;
	printf("enter the size of array");
	scanf("%d",&n);
	printf("enter the elements");
	for(i=0;i<n;i++)
		scanf("%d",&arr[i]);
	do
	{
		printf("enter the choice :\n1.insert\n2.delete\n3.search\n4.exit\n5.print");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1: printf("enter the position and element to be inserted");
				  scanf("%d%d",&pos,&ele);
				  for(i=n;i>=pos;i--)
						arr[i]=arr[i-1];
				  arr[pos-1]=ele;
				  n=n+1;
				  break;
			case 2:printf("enter the position and element to be deleted");
				  scanf("%d%d",&pos,&ele);
				  for(i=pos-1;i<n-1;i++)
						arr[i]=arr[i+1];
				  n=n-1;
				   break;
			case 3:printf("enter the element to be searched");
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
				  break;
			case 4:exit(0);
			      break;
			case 5:printf("elements are:");
				  for(i=0;i<n;i++)
						printf("%d\t",arr[i]);
				  break;
			default:printf("wrong choice");
       }
	}
	while(1);
}
