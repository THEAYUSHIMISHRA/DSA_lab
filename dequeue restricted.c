#include<stdio.h>
#include<conio.h>
#define max 10
int deque[max];
int left=-1,right=-1;

void inputdeque();
void outputdeque();
void inleft();
void inright();
void deleft();
void deright();
void display();

int main()
{
	int ch;
	printf("***MAIN MENU***");
	printf("\n1.INPUT RESTRICTED DEQUE: ");
	printf("\n2.OUTPUT RESTRICTED DEQUE: ");
	printf("\n ENTER YOUR CHOICE: ");
	scanf("%d",&ch);
	switch(ch)
	{
		case 1: inputdeque();
				break;
		case 2: outputdeque();
				break;
	}	
	return 0;
}

void inputdeque()
{
	int ch;
	do
	{
		printf("\n INPUT RESTRICTED DEQUE");
		printf("\n1. INSERT AT RIGHT");
		printf("\n2. DELETE FROM LEFT");
		printf("\n3. DELETE FROM RIGHT");
		printf("\n4.DISPLAY");
		printf("\n5. QUIT");
		printf("\nENTER YOUR CHOICE: ");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1: inright();
					break;
			case 2: deleft();
					break;
			case 3: deright();
					break;
			case 4: display();
					break;
		}
		
	} while(ch>=1 && ch<=4);
}

void outputdeque()
{
	int ch;
	do
	{
		printf("\n OUTPUT RESTRICTED DEQUE");
		printf("\n1. INSERT AT RIGHT");
		printf("\n2. INSERT AT LEFT");
		printf("\n3. DELETE FROM LEFT");
		printf("\n4.DISPLAY");
		printf("\n5. QUIT");
		printf("\nENTER YOUR CHOICE: ");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1: inright();
					break;
			case 2: inleft();
					break;
			case 3: deleft();
					break;
			case 4: display();
					break;
		}
		
	} while(ch>=1 && ch<=4);
}

void inright()
{
	int data;
	printf("\nEnter value to be added: ");
	scanf("%d",&data);
	if((left==0 && right==max-1)||(left==right+1))
	{
		printf("\nOVERFLOW!");
		return;
	}
	if(left==-1)
	{
		left=0;
		right=0;
	}
	else
	{
		if(right==max-1)
			right=0;
		else
			right=right+1;
	}
	deque[right]=data;
}

void inleft()
{
	int data;
	printf("\nEnter value to be added: ");
	scanf("%d",&data);
	if((left==0 && right==max-1)||(left==right+1))
	{
		printf("\nOVERFLOW!");
		return;
	}
	if(left==-1)
	{
		left=0;
		right=0;
	}
	else
	{
		if(left==0)
			left=max-1;
		else
			left=left-1;
	}
	deque[left]=data;
}

void deleft()
{
	if(left==-1)
	{
		printf("UNDERFLOW!");
		return;
	}
	printf("\nDELETED ELEMENT IS: %d",deque[left]);
	if(left==right)
	{
		left=right=-1;
	}
	else
	{
		if(left==max-1)
			left=0;
		else
			left=left+1;
	}
}

void deright()
{
	if(left==-1)
	{
		printf("\nUNDERFLOW");
		return;
	}
	printf("\nELEMENT DELETED IS:%d",deque[right]);
	if(left==right)
	{
		left=right=-1;
	}
	else
	{
		if(right==0)
			right=max-1;
		else
			right=right-1;
	}
}

void display()
{
	int front=left,rear=right;
	if(front==-1)
	{
		printf("\nQUEUE IS EMPTY!");
		return;
	}
	printf("\n the elements of the queue are: ");
	if(front<=rear)
	{
		while(front<=rear)
		{
			printf("%d",deque[front]);
			front++;
		}
	}
	else
	{
		while(front<=max-1)
		{
			printf("%d",deque[front]);
			front++;
		}
		front=0;
		while(front<=rear)
		{
			printf("%d",deque[front]);
			front++;
		}
	}
	printf("\n");
}
