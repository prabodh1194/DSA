#include "queue.h"

void createQueue(Queue *q, int n)
{
	q.a = malloc(sizeof(int)*n);
	q->head=0;
	q->tail=0;
	q->size=n;
}
void enqueue(Queue *q, int val)
{
	if(q->head==(q->tail+1)%(q->size))
	{
		printf("\nQueue overflow\n");
	}
	else
	{
		q->tail+=1;
		q->tail%=q->size;
		q->a[tail]=val;
	}
}
int dequeue(Queue *q)
{
	int val = q->a[head];
	q->head+=1;
	q->head%=q->size;
	return val;
}
int isEmpty()
{
	if(q->head==q->tail)
		return 1;
	return 0;
}
