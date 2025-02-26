#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<malloc.h>
struct node
{
	int data;
	struct node *next;
};
struct queue
{
	struct node *front;
	struct node *rear;
};

struct queue *q;
void createqueue(struct queue *);
struct queue *insert(struct queue *,int);
struct queue *delete(struct queue *);
struct queue *display(struct queue *);
int peep(struct queue *);

void createqueue(struct queue *q)
{
	q-<rear=NULL;
	q->front=NULL;
}
