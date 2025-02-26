//circular linked list basic operations
#include<stdio.h>
#include<stdlib.h>
void create();
void traversal();
void insert_begin();
void insert_end();
void insert_pos();
void del_begin();
void del_end();
void del_pos();
//Defining a node
struct node
{
	int info;
	struct node*next;
	
};
struct node*start=NULL;
void main()
{
	int ch;
	while(1)
	{
		printf("MENU:LINKED LIST OPERATIONS\n");
		printf("1.Create\n");
		printf("2.Traversal\n");
		printf("3.Insert at begin\n");
		printf("4.Insert at end\n");
		printf("5.Insert at position\n");
		printf("6.Delete at begin\n");
		printf("7.Delete at end\n");
		printf("8.Delete at position\n");
		printf("9.Exit\n");
		printf("Enter your choice:");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1: create();
					break;
			case 2: traversal();
					break;
			case 3: insert_begin();
					break;
			case 4: insert_end();
					break;
			case 5: insert_pos();
					break;
			case 6: del_begin();
					break;
			case 7: del_end();
					break;
			case 8: del_pos();
					break;
			case 9:exit(0);
		}
	}
}
//Defining operations
void create()
{
	struct node*temp,*ptr;
	int i,n;
	printf("Enter no. of nodes=");
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		temp=(struct node*)malloc(sizeof(struct node));
		if (temp==NULL)
		{
			printf("List overflow");
			exit(0);
		}
		printf("Data value for node=");
		scanf("%d",&temp->info);
		temp->next=NULL;
		if(start==NULL)
		start=temp;
		else
		{
			ptr=start;
			while(ptr->next!=NULL)
			ptr=ptr->next;
			ptr->next=temp;
		}
	}
}
void traversal()
{
	struct node*ptr=start;
	if(start==NULL)
	printf("List underflow");
	printf("LIst elements are:");
	while(ptr!=NULL)
	{
		printf("%d\t\n",ptr->info);
		ptr=ptr->next;
	}
}
void insert_begin()
{
	struct node*temp=(struct node*)malloc(sizeof(struct node));
	if(temp==NULL)
	{
		printf("List overflow");
		exit(0);
	}
	printf("Enter data value=");
	scanf("%d",&temp->info);
	temp->next=NULL;
	temp->next=start;
	start=temp;
}
void insert_end()
{
	struct node*temp,*ptr;
	temp=(struct node*)malloc(sizeof(struct node));
	if(temp==NULL)
	{
		printf("List overflow");
		exit(0);
	}
	printf("Enter data value=");
	scanf("%d",&temp->info);
	temp->next=NULL;
	ptr=start;
	while(ptr->next!=NULL)
	ptr=ptr->next;
	ptr->next=temp;
}
void insert_pos()
{
	struct node*temp=new_node(),*ptr=start;
	int i,pos;
	printf("Enter position of new node=");
	scanf("%d",&pos);
	if(temp==NULL)
	{
		printf("List overflow");
		exit(0);
	}
	printf("Enter data value=");
	scanf("%d",&temp->info);
	temp->next=temp;
	for(i=1;i<pos;i++)
	ptr=ptr->next;
	temp->next=ptr->next;
	ptr->next=temp;
}
void del_begin()
{
	struct node*temp=start,*ptr=start;
	while(ptr->next!=start)
	ptr=ptr->next;
	ptr->next=start->next;
	start=start->next;
	printf("Deleted elementis=%d",temp->info);
	free(ptr);
}
void del_end()
{
	struct node*temp,*ptr;
	if(start==NULL)
	{
		printf("List underflow");
		exit(0);
	}
	temp=start;
	ptr=start->next;
	while(ptr->next!=NULL)
	{
		temp=temp->next;
		ptr=ptr->next;
	}
	temp->next=NULL;
	printf("Deleted element=%d",ptr->info);
	free(ptr);
}
void del_pos()
{
	struct node*temp,*ptr;
	int i,pos;
	printf("Enter positionof node to be detected=");
	scanf("%d",&pos);
	if(start==NULL)
	{
		printf("List underflow");
		exit(0);
	}
	temp=start;
	ptr=start->next;
	for(i=1;i<pos;i++)
	{
		temp=temp->next;
		ptr=ptr->next;
	}
	temp->next=ptr->next;
	printf("Deleted element=%d",ptr->info);
	free(ptr);
}