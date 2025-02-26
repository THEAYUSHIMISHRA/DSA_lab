#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<process.h>
#define size 20
struct queue
{
	int arr[size];
	int front,rear;
};
typedef struct queue queue ;
int isoverflow (queue);
int isunderflow(queue);
void enqueue(queue *,int);
void enqueue(queue *ps,int data)
{
	q.rear
	for(i=)
}
int isunderflow(queue q)
{
	if(q.front==-1)
		return 1;
	else
		return 0;
}
int isoverflow(queue q) 
{
	if(q.rear==size-1)
		return 1;
	else 
		return 0;
}
void main ()
{
	int ch;
	queue q;
	q.front=-1;
	q.rear=-1;
	do
	{
		printf("\n menu");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:if(isoverflow(q)==1)
						printf("overflow");
					else 
					{
						printf("\n enter data to enqueue");
						scanf("%d",&ch);
						enqueue(&q,ch); 		
					}
					break;
			case 2:if(isunderflow(q)==1)
							printf("underflow");
					else
					{
						data=dequeue();
						printf("data dequeued=%d",data);
					}
		}
	}
}