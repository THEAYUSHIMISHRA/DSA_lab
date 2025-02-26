#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<process.h>
#define size 3
void push(int *,int *,int);
int pop(int *,int*);
int peep(int *,int);
void display(int *,int);
int main()
{
	int arr[size],top,ch,data;
	top=-1;
	do
	{
		printf("enter choice");
		printf("\n1.push\n2.pop\n3.peep\n4.display\n");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1: if(top==size-1)
					{
						printf("\nstack overflow exception\n");
					}
					else
					{
				   printf("\nenter data to push:\n");
			       scanf("%d",&data);
			       push(arr,&top,data);
			        }
			       break;
			case 2: if(top==-1)
					{
						printf("\nstack underlow exception!\n");
					}
					else
					{
					data=pop(arr,&top);
			        printf("\ndata popped=%d\n",data);
			        }
			        break;
			case 3: if(top==-1)
					{
						printf("\n stack underflow exception!\n");	
					}
					else
					{
					data=peep(arr,top);
			       printf("\n%d is at the top of the stack\n",data);
			        }
			       break;
			case 4:display(arr,top);
					break;
			default:printf("wrong choice\n");
		}
	}while(ch>=1 && ch<=4);
}

void push(int arr[],int *ptop,int data)
{
		*ptop=*ptop+1;
		arr[*ptop]=data;
}
int pop(int arr[],int*ptop)
{
	int data;
	data=arr[*ptop];
	*ptop=*ptop-1;
	return data;
}
int peep (int arr[],int top)
{
	int data;
	data=arr[top];
	return data;
}
void display(int arr[],int top)
{
	int i;
	if(top==-1)
	{
		printf("\n stack underflow");
	}
	else
	{
		for(i=top;i>=0;i--)
		{
			printf("\n%d\n",arr[i]);
		}
	}
}




















