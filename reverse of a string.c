#include<stdio.h>
#include<conio.h>
#include<string.h>

char stack[20];
int top=-1;

void push(char);
char pop();

int main()
{
	char str[20],ch;
	int l,i;
	printf("enter string: ");
	gets(str);
	l=strlen(str);
	for(i=0;i<l;i++)
		push(str[i]);
	printf("\Reversed string: ");
	for(i=0;i<l;i++)
	{
		ch=pop();
		printf("%c",ch);
	}
	return 0;
}

void push(char c)
{
	top++;
	stack[top]=c;
}

char pop()
{
	char c;
	c=stack[top];
	top--;
	return c;
}
