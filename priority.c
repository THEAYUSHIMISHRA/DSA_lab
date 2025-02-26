#include<stdio.h>
#include<process.h>
#define max 5
int rear=-1;
int front =-1;
int data[max][max];

void main()
{
	int ch;
	do
	{
		printf("enter choice=");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
		}
	}
}
void enqueue()
{
	printf("enter the priority");
	scanf("%d",&p);
	index=p-1;
	if(rear[index]==max-1);
		printf("overflow");
	else
	{
		printf("enter element to be dequeued");
		scanf("%d",&n);
		if(front[index]==-1)
			front[index]=0;
		rear[index]++;
		r=rear[index];
		data[index][r]=item;
		printf("\nrear=%d front=%d",rear[index],front[index]);
	}
}
void dequeue()
{
	int temp=-111,flag=0,i,f;
	for(i=0;i<=max-1;i++)
	{
		if(front[i]!=-1)
		{
			f=front[i];
			temp=data[i][f];
			if(front[i]==rear[i])
				front[i]=rear[i]=-1;
			else
				front[i]++;
			flag=1;
			break;
		}
	}
	if(flag==0)
		printf("\n all queue are underflow");
	else
		printf("\nelement dequeue=%d with priority=%d",temp);
}
void display()
{
	int i,j;
	printf("\n rear array=");
	for(i=0;i<max;i++)
		printf("%d",rear[i]);
}
















