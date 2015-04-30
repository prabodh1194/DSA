#ifndef __LIST_H
#define __LIST_H

struct node
{
	int v;
	struct node * next;
};

typedef struct node node;

node **arr;

void addEdge(node ***arr, int u, int v);
void printList(node **arr,int n);

#endif
