#include<stdio.h>
#include<conio.h>
#include<process.h>
#define max 10
int queue[max];
int front=-1,rear=-1;

void enqueue(void);
int dequeue(void);
void display(void);

int main()
{
	int ch,data;
	do
	{
		printf("\n****MAIN MENU****");
		printf("\nInsert element: ");
		printf("\nDelelte an element:");
		printf("\nDisplay the queue:");
		printf("\nexit");
		printf("\nenter choice: ");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1: enqueue();
						break;
			case 2: data=dequeue();
					if(data!=-1)
						printf("\nNumber deleted is: ",data);
					break;
			case 3: display();
						break;
		}
	}while(ch<4);
	getch();
	return 0;
}


void enqueue()
{
	int data;
	printf("\nenter number to be inserted in the queue: ");
	scanf("%d",&data);
	if(front==0 && rear==max-1)
		printf("\noverflow");
	else if(front==-1 && rear==max-1)
		{
			front=rear=0;
			queue[rear]=data;
		}
	else if(rear=max-1 && front!=0) 
	{
		rear=0;
		queue[rear]=data;
	}
	else
	{
		rear++;
		queue[rear]=data;
	}
}

int dequeue()
{
	int data;
	if(front==-1 && rear==-1)
	{
		printf("\nunderflow!");
		return -1;
	}
	data=queue[front];
	if(front==rear)
		front=rear=-1;
	else
	{
		if(front=max-1)
			front=0;
		else
			front++;
	}
	return data;
}

void display()
{
	int i;
	printf("\n");
	if(front==-1 && rear==-1)
		printf("queue is empty!");
	else
	{
		if(front<rear)
		{
			for(i=front;i<=rear;i++)
				printf("\t %d",queue[i]);
		}
		else
		{
			for(i=front;i<max;i++)
				printf("\t%d",queue[i]);
			for(i=0;i<=rear;i++)
				printf("\t%d",queue[i]);
			
		}
	}
}


