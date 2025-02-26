#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<process.h>
#define size 20
struct stack
{
	int arr[size];
	int top;
};
typedef struct stack stack;
void push(stack *,int);
int pop(stack *);
int peep(stack);
void display(stack);
int overflow(stack);
int underflow(stack);

int overflow(stack stk)
{
	if(stk.top==size-1)
		return 1;
	else
		return 0;
}
int underflow(stack stk)
{
	if(stk.top==-1)
		return 1;
	else
		return 0;
}
void push(stack *ps,int data)
{
		ps->top=ps->top+1;
		ps->arr[ps->top]=data;
}
int pop(stack *ps)
{
	int data;
	data=ps->arr[ps->top];
	ps->top=ps->top-1;
	return data;
}
int peep (stack stk)
{
	int data;
	data=stk.arr[stk.top];
	return data;
}
void display(stack stk)
{
	int i;
	for(i=stk.top;i>=0;i--)
	{
		printf("\n%d\n",stk.arr[i]);
	}
}

void main()
{
	int data;
	int ch;
	stack stk;
	stk.top=-1;
	do
	{
		
		printf("enter choice:\n1.push\n2.pop\n3.peep\n4.display");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1: if(overflow(stk)==1)
						printf("\noverflow can't be inserted");
					else
					{
						printf("\nenter data");
						scanf("%d",&data);
						push(&stk,data);
					}
					break;
			case 2: if(underflow(stk)==1)
						printf("\nunderflow can't be popped");
					else
					{
						data=pop(&stk);
						printf("data popped=%d",data);
					}
			case 3: if(underflow(stk)==1)
						printf("\nunderflow ");
					else
					{
						data=peep(stk);
			       		printf("\n%d is at the top of the stack\n",data);
			       	}
			       break;
			case 4:display(stk);
					break;
			default:printf("wrong choice\n");
		}
					
	}while(ch>=1 && ch<=4);
}




































