#include<stdio.h>
#include<conio.h>
# define max 10 

int stack [max];
int topA=-1;
int topB=max;

void pushA(int);
void pushB(int);
int popA();
int popB();
void display_stackA();
void display_stackB();

void pushA (int val)
{
	if(topA==topB-1)
		printf("overflow");
	else
	{
		topA++;
		stack[topA]=val;
	}
}

int popA ()
{
	int val;
	if(topA==-1)
	{
		printf("underflow");
		val= -111;
	}
	else
	{
		val=stack[topA];
		topA--;
	}
}

void display_stackA()
{
	int i;
	if(topA==-1)
		printf("empty");
	else
	{
		for(i=topA;i>=0;i--)
			printf("\t%d",stack[i]);
	}
}

void pushB (int val)
{
	if(topB-1==topA)
		printf("overflow");
	else
	{
		topB--;
		stack[topB]=val;
	}
}

int popB ()
{
	int val;
	if(topA==max)
	{
		printf("underflow");
		val= -111;
	}
	else
	{
		val=stack[topB];
		topB++;
	}
}



void display_stackB ()
{
	int i;
	if(topB==max)
		printf("empty");
	else
	{
		for(i=topB;i<max;i++)
			printf("\t%d",stack[i]);
	}
}

int main()
{
	int option,val;
	do
	{
		printf("\n ***MENU***");
		printf("\n1. push in stack A");
		printf("\n2. push in stack B");	
		printf("\n3. pop from stack A");	
		printf("\n4. pop from stack B");
		printf("\n5. display stack A");		
		printf("\n6. display stack B");	
		printf("\n7. exit");
		printf("\n enter option: ");
		scanf("%d",&option);
		switch(option)
		{
			case 1: printf("enter value to push in A: ");
					scanf("%d",&val);
					pushA(val);
					break;
			case 2: printf("enter value to push in B: ");
					scanf("%d",&val);
					pushB(val);
					break;
			case 3: val=popA();
					if(val!=-111);
						printf("value popped from A:%d",val);
					break;
			case 4: val=popB();
					if(val!=-111);
						printf("value popped from B:%d",val);
					break;
			case 5: printf(" stack A elemnets are: \n ");
					display_stackA();
					break;
			case 6: printf(" stack B elemnets are: \n ");
					display_stackB();
					break;	
		}
	}while(option!=7);
	return 0;
	getch();
}
