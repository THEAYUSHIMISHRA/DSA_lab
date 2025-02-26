
#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<process.h>
#define size 20
char stack[size];
int top=-1;
char pop();
void push(char item);
int prcd(char symbol);
int isoperand(char symbol);
int isoperator(char symbol);
void convertopost(char infix[],char prefix[]);
char pop()
{
	char a;
	a=stack[top];
	top--;
	return a;
}
void push(char item)
{
	top++;
	stack[top]=item;
}
int isoperand(char symbol)
{
	if((symbol>='a'&& symbol<='z')||(symbol>='A' && symbol<='Z')||(symbol>='0' && symbol<='9'))
		return 1;
	else 
		return 0;
}
int isoperator(char symbol)
{
	switch(symbol)
	{
		case '+':
		case '-':
		case '*':
		case '/':
		case '^':
		case '$':
		case '(':
		case ')': return 1;
		default: return 0;
	}
}
int prcd(char symbol)
{
	switch(symbol)
	{
		case '+':
		case '-': return 2;
		case '*':
		case '/': return 4;
		case '^':
		case '$': return 6;
		case ')':
		case '(': return 1;
	}
}
void convertopost(char infix[],char prefix[])
{
	int i,j=0; char symbol;
	infix=strrev(infix);
	for(i=0;i<strlen(infix);i++)
	{
		symbol=infix[i];
		if(isoperand(symbol)==1)
		{
			prefix[j]=symbol;
			j++;
			
		}
		else if (symbol==')')
		{
			push(symbol);
		}
		else if(symbol=='(')
		{
			while (stack[top]!=')')
			{
				prefix[j]=pop();
				j++;
			}
			pop();
		}
		else if (isoperator(symbol)==1)
		{
			if(prcd(symbol)>prcd(stack[top]))
			{
				push(symbol);
			}
			else
			{
				while((prcd(symbol))<(prcd(stack[top])))
				{
					prefix[j]=pop();
					j++;
				}	
				push(symbol);
			}
		}
		else
		{
			printf("\ninvalid symbol :%c",symbol);
			exit(0);
		}
		
	}
	while(top!=-1)
	{
		prefix[j]=pop();
		j++;
	}
	prefix[j]='\0';
	prefix=strrev(prefix);
}
int main()
{
	char infix[20],prefix[20];
	printf("enter valid infix string:\n");
	gets(infix);
	convertopost(infix,prefix);
	printf("\ncorresponding prefix string is:\n");
	puts(prefix);
}























