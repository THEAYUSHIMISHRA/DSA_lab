#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<process.h>
#define size 20
struct stack
{
	int arr[size];
	int top;
}s;
int pop();
void push(int item);
int digit(char c);
int evaluate(char postfix[]);
int pop()
{
	int ret;
	if(s.top==-1)
	{
		printf("\nstack empty");
		return -111;
	}
	else
	{
		ret=s.arr[s.top];
		--s.top;
		return ret;
	}
}
void push(int item)
{
	if(s.top==(size-1))
		printf("\nstack full");
	else
	{
		s.top=s.top+1;
		s.arr[s.top]=item;
	}
}
int digit(char c)
{
	if((c>='0')&&(c<='9'))
		return 1;
	else
		return 0;
}
int isoperator(char symbol)
{
	switch(symbol)
	{
		case '%':
		case '+':
		case '-':
		case '*':
		case '/':return 1;
		default: return 0;
		
	}
}
int evaluate(char postfix[])
{
	int i,op1,op2,result;
	char symbol;
	for(i=0;i<strlen(postfix);i++)
	{
		symbol=postfix[i];
		while((symbol==' ')||(symbol=='\t'))
			i++;
		if(digit(symbol))
			push(symbol- 48);
		else if(isoperator(symbol))
		{
			op1=pop();
			op2=pop();
			switch(symbol)
			{
				case '+':result=op2+op1;
						break;
				case '-':result=op2-op1;
						break;
				case '/':result=op2/op1;
						break;
				case '*':result=op2*op1;
						break;
				case '%':result=op1%op2;
						break;
			}
			push(result);
	    }
	    else
	    {
	    	printf("\n invalid operator");
	    	exit(0);
		}
	}
		result=pop();
		return result;
}
int main()
{
	int data;
	char postfix[20];
	printf("enter valid postfix string:\n");
	gets(postfix);
	data=evaluate(postfix);
	printf("answer=%d",data);
}




































