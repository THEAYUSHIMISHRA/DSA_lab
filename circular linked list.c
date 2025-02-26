#include<stdio.h>
#include<stdlib.h>
#include<process.h>
struct node
{
	int data;
	struct node *next;
}*head;
typedef struct node cnode;

void addbeg(int num)
{
	cnode *newnode,*cur;
	newnode=(cnode*)malloc(sizeof(cnode));
	newnode->data=num;
	newnode->next=NULL;
	if(head==NULL)
	{
		head=newnode;
		head->next=head;
		return;
	}
	newnode->next=head;
	cur=head;
	while(cur->next!=NULL)
		cur=cur->next;
	cur->next=newnode;
	head=newnode;	
}
void addbef(int num)
{
	int n;
	cnode *newnode,*cur,*prv;
	newnode=(cnode*)malloc(sizeof(cnode));
	newnode->data=num;
	cur=head;
	if(head==NULL)
	{
		head=newnode;
		head->next=head;
		return;
	}
	else
	{
		printf("\nENTER THE NODE BEFORE WHICH YOU WANT TO INSERT: ");
		scanf("%d",&n);
		if(cur->data==n)
		{
			printf("\ncur-data=%d",cur->data);
			newnode->next=head;
			while(cur->next!=head)
				cur=cur->next;
			cur->next=newnode;
			head=newnode;
			return;
		}
		while(cur->next!=head)
		{
			prv=cur;
			cur=cur->next;
			if(cur->data==n)
			{
				prv->next=newnode;
				newnode->next=cur;
				return;
			}
		}
	}
	printf("\nMATCH NOT FOUND!!!");
}
void addafter(int num)
{
	int n,flag=0;
	cnode *cur=head,*newnode,*prv;
	newnode=(cnode*)malloc(sizeof(cnode));
	newnode->data=num;
	if(head==NULL)
	{
		head=newnode;
		head->next=head;
		return;
	}
	else
	{
		printf("\nENTER NODE AFTER WHICH YOU WANT TO INSERT: ");
		scanf("%d",&n);
		while(cur->next!=head)
		{
			if(cur->data==n)
			{
				newnode->next=cur->next;
				cur->next=newnode;
				flag=1;
			}
			cur=cur->next;
		}
		if(flag==0&&cur->data==n)
		{
			cur->next=newnode;
			newnode->next=head;
			flag=1;
		}
		if(flag==0)
			printf("\nNO.MATCH FOUND!!!");
	}
}

void display()
{
	cnode *cur;
	cur=head;
	printf("\nhead %d\t",head->data);
	while(cur->next!=head)
	{
		printf("%d\t",cur->data);
		cur=cur->next;
	}
	printf("%d\t",cur->data);
}

int count()
{
	cnode *cur;
	int c=0;
	if(head!=NULL)
	{
		cur=head;
		while(cur->next!=head)
		{
			c++;
			cur=cur->next;
		}
		c++;
	}
	return;
}

void delnode(int num)
{
	int t;
	cnode *cur,*prv,*del;
	cur=head;
	if(cur->data==num)
	{
		if(cur->next==head)
		{
			free(cur);
			head=NULL;
			return;
		}
		while(cur->next!=head)
			cur=cur->next;
		del=head;
		cur->next=head->next;
		head=head->next;
		t=del->data;
		free(del);
		printf("\nNODE WITH %d data is DELETED",t);
		return;
	}
	while(cur->next!=head)
	{
		prv=cur;
		cur=cur->next;
		if(cur->data==num)
		{
			prv->next=cur->next;
			free(cur);
			return;
		}
	}
	printf("\nELEMENT %d NOT FOUND",num);
}

void reverse()
{
	cnode *left,*right,*cur;
	cur=head;
	right=NULL;
	while(cur->next!=head)
	{
		left=right;
		right=cur;
		cur=cur->next;
		right->next=left;
	}
	left=right;
	right=cur;
	cur=cur->next;
	right->next=left;
	head=right;
	cur->next=right;
}

void search(int num)
{
	cnode *cur=head;
	int flag=0;
	if(head==NULL)
	{
		printf("\nLINKED LIST IS EMPTY!!!");
		return;
	}
	while(cur->next!=head)
	{
		if(cur->next!=head)
		{
			printf("NUMBER %d FOUND!!!",num);
			flag=1;
		}
		cur=cur->next;
	} 
	if(cur->data==num)
	{
		printf("NUMBER %d FOUND",num);
		flag=1;
	}
		if(flag==0)
			printf("%d NOT FOUND",num);
}

void main()
{
	int ch,k,num;
	head=NULL;
	cnode *n;
	while(1)
	{
		printf("\n1.INSERT AT BEGINNING:");
		printf("\n2.INSERT BEFORE ANY NODE:");
		printf("\n3.INSERT BEFORE ANY NODE:");
		printf("\n4.PRINT THE ELEMENTS IN THE LIST:");
		printf("\n5.COUNT THE NO. OF ELEMENTS IN THE LIST:");
		printf("\n6.DELETE A NODE:");
		printf("\n7.REVERSE A LINKED LIST:");
		printf("\n8.SEARCH A NODE IN LINKED LIST:");
		printf("\nENTER YOUR CHOICE:");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1: printf("\nENTER THE NO. TO INSERT IN THE LIST: ");
					scanf("%d",&num);
					addbeg(num);
					break;
			case 2: printf("\nENTER THE NO. TO INSERT BEFORE A NODE: ");
					scanf("%d",&num);
					addbef(num);
					break;
			case 3: printf("\nENTER THE NO. TO INSERT AFTER A NODE: ");
					scanf("%d",&num);
					addafter(num);
					break;
			case 4: if(head==NULL)
						printf("\nLINKED LIST IS EMPTY!!!");
					else
						display();
					break;
			case 5: k=count();
					printf("\nTHE NO. OF NODES IN THE LINKED LIST IS:%d",k);
					break;
			case 6: printf("\nENTER THE DATA WHICH YOU WANT TO DELETE: ");
					scanf("%d",&num);
					delnode(num);
					break;
			case 7: reverse();
					printf("\nTHE LINKED LIST IS REVERSED!!!");
					break;
			case 8: if(head==NULL)
						printf("LINKED LIST IS EMPTY!!!");
					printf("\nENTER THE NO. TO SEARCH: ");
					scanf("%d",&num);
					search(num);
					break;
			case 9: exit(0);
			default:
				printf("\nINVALID CHOICE!!!");
		}
		
	}
}
