#include<stdio.h>
#include<string.h>
#include<process.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node *next;
}*head;
typedef struct node node;
void search();
void addbeg(int );
void append(int num);
void addbet(int loc,int num);
void display();
int count();
void delnode(int num);
void reverse();
void delloc(int loc);
void addbeg(int num)
{
	node *newnode;
	newnode=(node*)malloc(sizeof(node));
	newnode->data=num;
	newnode->next=NULL;
	if(head==NULL)
	{
		head=newnode;
		return;
	}
	newnode->next=head;
	head=newnode;
}
void append(int num)
{
	node *newnode,*cur;
	newnode=(node*)malloc(sizeof(node));
	newnode->data=num;
	newnode->next =NULL;
	if(head==NULL)
	{
		head=newnode;
		return;
	}
	cur=head;
	while(cur->next!=NULL)
		cur=cur->next;
	cur->next=newnode;
}
void addbet(int loc,int num)
{
	int i;
	node *newnode,*cur=head;
	newnode=(node*)malloc(sizeof(node));
	newnode->data=num;
	newnode->next =NULL;
	for(i=1;i<loc-1;i++)
		cur=cur->next;
	newnode->next=cur->next;
	cur->next=newnode;
}
void display()
{
	node *cur;
	cur=head;
	while(cur!=NULL)
	{
		printf("%d->\t",cur->data);
		cur=cur->next;
	}
}
int count()
{
	node *cur=head;
	int c=0;
	while(cur!=NULL)
	{
		c++;
		cur=cur->next;
	}
	return c;
}
void delnode(int num)
{
	node * cur,*prv;
	cur=head;
	while(cur!=NULL)
	{
		if(cur->data==num)
		{
			if(cur==head)
			{
				head=cur->next;
				free(cur);
				return;
			}
			prv->next=cur->next;
			free(cur);
			return;
		}
		prv=cur;
		cur=cur->next;
	}
	printf("\nelement %d not found");
}
void reverse()
{
	node *left,*right,*cur;
	cur=head;
	right=NULL;
	while(cur!=NULL)
	{
		left=right;
		right=cur;
		cur=cur->next;
		right->next=left;
	}
	head=right;
}
void delloc(int loc)
{
	int i;
	node *prv,*cur;
	cur=head;
	if(loc>count()||loc<=0||head==NULL)
	{
		printf("\n deletion is not possible");
		return;
	}
	if(loc==1)
	{
		head=cur->next;
		printf("\n node with %d data is deleted",&cur->data);
		free(cur);
		return;
	}
	for(i=1;i<loc;i++)
	{
		prv=cur;
		cur=cur->next;
	}
	prv->next=cur->next;
	printf("\nnode with %d data is deleted",cur->data);
	free(cur);
	return;
}
void search()
{
	int num;
	node *cur=head;
	if(head==NULL)
	{
		printf("\nlinked list is empty!");
		return;
	}
	printf("\nenter the number to search");
	scanf("%d",&num);
	while(cur!=NULL)
	{
		if(cur->data==num)
		{
			printf("number %d found",num);
			return;
		}
		cur=cur->next;
	}
	printf("number %d is not found");
}
void main()
{
	int ch,loc,k,num;
	node *head=NULL;
	node *n;
	printf("\n1.Insert no at beginning:");
	printf("\n2.Insert no at last:");
	printf("\n3.Insert at particular location:");
	printf("\n4.Print the elements in the list:");
	printf("\n5.Count the no of elements in the linked list:");
	printf("\n6.Delete a node:");
	printf("\n7.Reverse a linked list:");
	printf("\n8.Delete by location:");
	printf("\n9.Search a node:");
	printf("\n10.Get out of linked list:");
	while(1)
	{
		
		printf("\nEnter your choice:");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1: printf("Enter the no to insert in the list");
					scanf("%d",&num);
					addbeg(num);
					break;
			case 2: printf("\nEnter the no to insert at last:");
					scanf("%d",&num);
					append(num);
					break;
			case 3: printf("\nenter the location at which you want to insert the element");
					scanf("%d",&loc);
					if(loc<1||loc>count()+1)
						printf("\nInvalid location!");
					else
					{
						printf("\nEnter no to insert:");
						scanf("%d",&num);
						if(loc==1)
							addbeg(num);
						else if(loc==count()+1)
							append(num);
						else
							addbet(loc,num);
					}
					break;
			case 4: display();
					break;
			case 5: k=count();
					printf("\nNo of nodes in the linked list=%d",k);
					break;
			case 6: printf("\nenter the data you want to delete");
					scanf("%d",&num);
					delnode(num);
					break;
			case 7: reverse();
					printf("\nlinked list is reversed!");
					break;
			case 8: printf("\nenter the location where you want to delete:");
					scanf("%d",&loc);
					delloc(loc);
					break;
			case 9: search();
					break;
			case 10: exit(0);
			default:printf("\nInvalid choice!");
			
		}
	}
}
