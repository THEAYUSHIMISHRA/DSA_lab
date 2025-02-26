#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
#include<process.h>
struct node
{
	struct node *prev;
	struct node *next;
	int data;	
};
struct node *head=NULL;
struct node *create(struct node *);
void display(struct node *);
struct node *addbeg(struct node *);
struct node *addend(struct node *);
struct node *deletebeg(struct node *);
struct node *deleteend(struct node *);
struct node *deletenode(struct node *);
void deletelist(struct node *);

void main()
{
	int ch;
	do
	{
		printf("\n****MAIN MENU****");
		printf("\n 1:CREATE THE LIST");
		printf("\n 2:DISPLAY THE LIST");
		printf("\n 3:ADD A NODE AT THE BEGINNING");
		printf("\n 4:ADD A NODE AT THE LAST");
		printf("\n 5:DELETE A NODE FROM THE BEGINNING");
		printf("\n 6:DELETE A NODE FROM THE LAST");
		printf("\n 7:DELETE A GIVEN NODE");
		printf("\n 8:DELETE THE ENTIRE LIST");
		printf("\n 9:EXIT");
		printf("\nENTER YOUR CHOICE: ");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1: head=create(head);
					printf("\nCIRCULAR DOUBLY LINKED LIST CREATED");
					break;
			case 2: display(head);
					break;
			case 3: head=addbeg(head);
					break;
			case 4: head=addend(head);
					break;
			case 5: head=deletebeg(head);
					break;
			case 6: deleteend(head);
					break;
			case 7: head=deletenode(head);
					break;
			case 8: deletelist(head);
					printf("\nCIRCULAR DOUBLY LINKED LIST DELETED");
					break;
		}
	}while(ch>=1 && ch<=8);
}

struct node *create(struct node *head)
{
	struct node *newnode,*cur;
	int num;
	printf("\nENTER -1 to end");
	printf("\n ENTER THE DATA");
	scanf("%d",&num);
	while(num!=-1)
	{
		if(head==NULL)
		{
			newnode=(struct node*)malloc(sizeof(struct node));
			newnode->prev=NULL;
			newnode->data=num;
			head=newnode;
			newnode->next=head;
		}
		else
		{
			newnode=(struct node*)malloc(sizeof(struct node));
			newnode->data=num;
			cur=head;
			while(cur->next!=head)
				cur=cur->next;
			newnode->prev=cur;
			cur->next=newnode;
			newnode->next=head;
			head->prev=newnode;
		}
		printf("\nENTER THE DATA: ");
		scanf("%d",&num);
	}
	return head;
}

void display(struct node *head)
{
    struct node *cur;
    if(head==NULL)
        printf("list is empty\n");
    else
    {
        cur=head;
        do
        {
            printf("\t%d", cur->data);
            cur=cur->next;
        } while(cur!=head); // loop until we reach the head again
    }
}


struct node *addbeg(struct node *head)
{
	struct node *newnode,*cur;
	int num;
	printf("\nENTER THE DATA: ");
	scanf("%d",&num);
	newnode=(struct node *)malloc(sizeof(struct node));
	newnode->data=num;
	cur=head;
	while(cur->next!=head)
		cur=cur->next;
	newnode->prev=cur;
	cur->next=newnode;
	newnode->next=head;
	head->prev=newnode;
	head=newnode;
	return head;
}

struct node *addend(struct node *head)
{
	struct node *cur,*newnode;
	int num;
	printf("\nENTER THE DATA: ");
	scanf("%d",&num);
	newnode=(struct node *)malloc(sizeof(struct node));;
	newnode->data=num;
	cur=head;
	while(cur->next!=head)
		cur=cur->next;
	cur->next=newnode;
	newnode->prev=newnode;
	newnode->next=head;
	head->prev=newnode;
	return head;
}

struct node *deletebeg(struct node *head)
{
	struct node *cur,*temp;
	cur=head;
	while(cur->next!=head)
		cur=cur->next;
	cur->next=head->next;
	temp=head;
	head=head->next;
	head->prev=cur;
	free(temp);
	return head;
}
struct node *deleteend(struct node *head)
{
    if (head == NULL) {
        return NULL; // If the list is empty, return NULL
    }

    struct node *cur = head;

    if (cur->next == head) 
	{ // Only one node in the list
        head = NULL;
        free(cur);
    } 
	else 
	{
        while (cur->next != head) 
		{ // Traverse to the last node
            cur = cur->next;
        }

        cur->prev->next = head; // Adjust the pointers
        head->prev = cur->prev;
        cur->prev = NULL;
        cur->next = NULL;
        free(cur); // Free the last node
    }

    return head; // Return the updated head
}




struct node *deletenode(struct node *head)
{
	struct node *cur;
	int num;
	printf("\nENTER THE VALUE OF THE NODE WHICH HAS TO BE DELETED: ");
	scanf("%d",&num);
	cur=head;
	if(cur->data==num)
	{
		head=deletebeg(head);
		return head;
	}
	else
	{
		while(cur->data!=num)
			cur=cur->next;
		cur->prev->next=cur->next;
		cur->next->prev=cur->prev;
		cur->prev=NULL;
		cur->next=NULL;
		free(cur);
		return head;
	}
}

void deletelist(struct node *head)
{
    struct node *cur;
    cur = head;
    while (cur->next != head) 
	{
        head = deleteend(head); // Delete the last node and update the head
    }
    head = deleteend(head); // Delete the last node
}














