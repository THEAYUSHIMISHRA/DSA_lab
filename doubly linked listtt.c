#include<stdio.h>
#include<stdlib.h>
#include<process.h>
struct node
{
	struct node *prev;
	int data;
	struct node *next;
}*head;
typedef struct node node;

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

void addbeg(int num)
{
	node *newnode;
	newnode=(node*)malloc(sizeof(node));
	newnode->data=num;
	newnode->next=NULL;
	newnode->prev=NULL;
	if(head==NULL)
	{
		head=newnode;
		return;
	}
	newnode->next=head;
	head->prev=newnode;
	head=newnode;
}

void append(int num)
{
	node *newnode,*cur=head;
	newnode=(node*)malloc(sizeof(node));
	newnode->data=num;
	newnode->next=NULL;
	newnode->prev=NULL;
	if(head==NULL)
	{
		head=newnode;
		head->next=NULL;
		return;
	}
	while(cur->next!=NULL)
		cur=cur->next;
	cur->next=newnode;
	newnode->prev=cur;
}

void addloc(int loc,int num)
{
	int i;
	node *newnode,*cur=head,*prv;
	newnode=(node*)malloc(sizeof(node));
	newnode->data=num;
	newnode->next=NULL;
	newnode->prev=NULL;
	if(loc>count()+1||loc<=0)
	{
		printf("\nINSERTION NOT POSSIBLE!!");
		return;
	}
	if(loc==1)
	{
		addbeg(num);
		return;
	}
	else
	{
		for(i=1;i<loc;i++)
			cur=cur->next;
		cur->prev->next=newnode;
		newnode->prev=cur->prev;
		newnode->next=cur;
		cur->prev=newnode;
	}
}

void display()
{
	node *cur=head;
	if(cur==NULL)
	{
		printf("\nNO ELEMENT IS PRESENT IN THE LIST!!!");
		return;
	}
	printf("\nFORWARD TRAVERSAL:\t");
	while(cur->next!=NULL)
	{
		printf("%d->\t",cur->data);
		cur=cur->next;
	}
	printf("%d",cur->data);
	printf("\nBACKWARD TRAVERSAL:\t");
	while(cur!=head)
	{
		printf("%d<-\t",cur->data);
		cur=cur->prev;
	}
	printf("%d",cur->data);
}

void delnode(int num)
{
	node *cur=head,*prv;
	while(cur!=NULL)
	{
		if(cur->data==num)
		{
			if(cur==head)
			{
				if(cur->next==NULL)
				{
					free(cur);
					head=NULL;
					printf("\nYOU DELETED THE ONLY NODE LEFT IN THE LIST!!!");
					return;
				}
				head=head->next;
				head->prev=NULL;
				free(cur);
				return;
			}
			else if(cur->next==NULL)
			{
				cur->prev->next=NULL;
				free(cur);
				return;
			}
			else
				{
					cur->prev->next=cur->next;
					cur->next->prev=cur->prev;
					free(cur);
					return;
				}
			}
		else
			cur=cur->next;
	}
	printf("\nELEMENT %d not found",num);
}

void reverse()
{
	node *left,*right=NULL,*cur=head;
	while(cur!=NULL)
	{
		left=right;
		right=cur;
		cur=cur->next;
		right->next=left;
		right->prev=cur;
	}
	head=right;
}

void delloc(int loc)
{
	int i;
	node *cur=head,*prv;
	if(loc>count()||loc<=0||head==NULL)
	{
		printf("\nDELETION IS NOT POSSIBLE!!!");
		return;
	}
	if(loc==1)
	{
		if(cur->next==NULL)
		{
			free(cur);
			head=NULL;
			printf("\nFIRST NODE IS DELETED!!");
		}
		head=head->next;
		head->prev=NULL;
		free(cur);
		return;
	}
	else
	{
		for(i=1;i<loc;i++)
			cur=cur->next;
		if(loc==count())
		{
			cur->prev->next=NULL;
			free(cur);
			return;
		}
		cur->prev->next=cur->next;
		cur->next->prev=cur->prev;
		free(cur);
		return;
	}
}

void search()
{
	int num;
	node *cur=head;
	if(head==NULL)
	{
		printf("\nLINKED LIST IS EMPTY!!");
		return;
	}
	printf("\nENTER THE NO. TO BE SEARCHED: ");
	scanf("%d",&num);
	while(cur!=NULL)
	{
		if(cur->data==num)
		{
			printf("\nNUMBER %d FOUND ",num);
			return;
		}
		cur=cur->next;
	}
	printf("NUMBER %d IS NOT FOUND!",num);
}

void main()
{
	int ch,loc,k,num;
	node *head=NULL;
	do
	{
		printf("\n1.INSERT AT BEGINNING\n2.INSERT AT LAST\n3.INSERT AT PARTICULAR LOCATION");
		printf("\n4.PRINT THE ELEMENTS IN THE LIST\n5.COUNT THE NO. OF ELEMENTS\n6.DELETE A NODE");
		printf("\n7.REVERESE A LINKED LIST\n8.DELETE BY LOCATION\n9.SEARCH A NODE");
		printf("\nGET OUT OF THE LINKED LIST!!");
		printf("\nENTER YOUR CHOICE: ");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1: printf("\nENTER THE NO. TO BE INSERTED IN THE LIST: ");
					scanf("%d",&num);
					addbeg(num);
					break;
			case 2: printf("\nENTER THE NO. TO BE INSERTED AT THE LAST: ");
					scanf("%d",&num);
					append(num);
					break;
			case 3: printf("ENTER THE LOCATION AT WHICH U WANT TO INSERT THE ELEMNT: ");
					scanf("%d",&loc);
					if(loc<=1||loc>count()+1)
						printf("\nINVALID LOCATION!");
					else
					{
						printf("\nENTER THE NUMBER TO INSERT : ");
						scanf("%d",&num);
						if(loc==1)
							addbeg(num);
						else if(loc==count()+1)
								append(num);
							else
								addloc(loc,num);
					}
					break;
			case 4: display();
					break;
			case 5: k=count();
					printf("\nTHE NUMBER OF NODES IN THE LIST IS:%d",k);
					break;
			case 6: printf("\nENTER THE DATA WHICH YOU WANT TO DELETE: ");
					scanf("%d",&num);
					delnode(num);
					break;
			case 7: reverse();
					printf("\nTHE LINKED LIST IS REVERSED!!");
					break;
			case 8: printf("\nENTER THE LOCATION WHICH YOU WANT TO DELETE: ");
					scanf("%d",&loc);
					delloc(loc);
					break;
			case 9: search();
					break;
			default: 
				printf("\nINVALID CHOICE!!");	
		}
	}while(ch>=1 && ch<=9);
}











