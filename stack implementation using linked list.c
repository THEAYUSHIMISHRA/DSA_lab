#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<malloc.h>
struct stack 
{
	int data;
	struct stack *next;
};

struct stack *top=NULL;
struct stack *push(struct stack *,int);
struct stack *pop(struct stack *);
struct stack *display(struct stack *);
int peep(struct stack *);

struct stack *push(struct stack *top,int val)
{
	struct stack *newnode;
	newnode=(struct stack*)malloc(sizeof(struct stack));
	newnode->data=val;
	if(top==NULL)
	{
		newnode->next=NULL;
		top=newnode;
	}
	else
	{
		newnode->next=top;
		top=newnode;
	}
	return top;
}

struct stack *pop(struct stack *top)
{
	struct stack *newnode;
	newnode=top;
	if(top==NULL)
		printf("\nSTACK UNDERFLOW!");
	else
	{
		top=top->next;
		printf("\nDELETED VALUE IS:%d",newnode->data);
		free(newnode);
	}
	return top;
}

struct stack *display(struct stack *top)
{
	struct stack *newnode;
	newnode=top;
	if(top==NULL)
		printf("\nSTACK IS EMPTY!!");
	else
	{
		while(newnode!=NULL)
		{
			printf("\n%d",newnode->data);
			newnode=newnode->next;
		}
	}
	return top;
}

int peep(struct stack *top)
{
	if(top==NULL)
		return -1;
	else
		return (top->data);
}

int main(int ,char)
{
	int val,choice;
	do
	{
		printf("\n******MAIN MENU******");
		printf("\n 1. PUSH");
		printf("\n 2. POP");
		printf("\n 3. PEEP");
		printf("\n 4. DISPLAY");
		printf("\n 5. EXIT");
		printf("\n ENTER YOUR CHOICE: ");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1: printf("\n ENTER NUMBER TO BE PUSHED ON STACK: ");
					scanf("%d",&val);
					top=push(top,val);
					break;
			case 2: top=pop(top);
					break;
			case 3: val=peep(top);
					if(val!=-1)
						printf("\nVALUE AT THE TOP OF STACK IS: %d",val);
					else
						printf("\nSTACK IS EMPTY");
					break;
			case 4: top=display(top);
					break;
		}
	}
	while(choice>=1 && choice<=4);
	return 0;
}
