#include<stdio.h>
#define max 3
int rear[max];
int front[max];
int data[max][max];
void enqueue();
void dequeue();
void display();
void enqueue()
{
	int p,index,r,item;
	printf("enter the priority of the element: ");
	scanf("%d",&p);
	index=p-1;
	if(rear[index]==max-1)
	{
		printf("queue overflow\n");
	}
	else
	{
		printf("enter data to enqueue: ");
			scanf("%d",&item);
		if(front[index]==-1)
			front[index]=0;
		rear[index]++;
		r=rear[index];
		data[index][r]=item;
		printf("rear=%d front=%d\n",rear[index],front[index]);
	}
}
void dequeue()
{
	int temp=-111,flag=0,i,f;
	for(i=0;i<max-1;i++)
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
		printf("all queue are underflow!\n");
	else
		printf("element dequeue=%d\n",temp);
}
void display()
{
	int i,j;
	printf("rear array= ");
	for(i=0;i<max;i++)
		printf("%d\t",rear[i]);
	printf("\nfront array= ");
	for(i=0;i<max;i++)
		printf("%d\t",front[i]);
	printf("\nthe priority queue is:\n");
	for(i=0;i<max;i++)
	{
		if(front[i]==-1)
			printf("priority queue with priority %d is empty",i+1);
		else
		{
			for(j=front[i];j<rear[i];j++)
			printf("%d\t",data[i][j]);
		}
		printf("\n");
	}
	printf("2d array\n");	
	for(i=0;i<max;i++)
	{
		for(j=0;j<max;j++)
			printf("%d\t",data[i][j]);
		printf("\n");
	}
	printf("\n");	
}
void main()
{
	int i,ch,val;
	for(i=0;i<max;i++)
	{
		rear[i]=front[i]=-1;
	}
	do
	{
		printf("1.enqueue\t2.dequeue\t3.display\n");
		printf("enter choice: ");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1: enqueue();
					break;
			case 2: dequeue();
					break;
			case 3: display();
					break;
			default: printf("wrong choice\n");
		}
	}while(ch>=1 && ch<=3);
}