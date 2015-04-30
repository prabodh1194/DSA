#ifndef __DFS_H
#define __DFS_H

typedef struct{
	int *a;
	int head;
	int tail;
	int size;
}Queue;

void createQueue(Queue *q, int n);
void enqueue(Queue *q, int val);
int dequeue(Queue *q);
int isEmpty();

#endif
