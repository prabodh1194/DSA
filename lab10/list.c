#include "list.h"
#include <stdio.h>
#include <stdlib.h>

void addEdge(node ***arr, int u, int v)
{
	node *newnode;
	newnode = (node *)malloc(sizeof(node));
	newnode->v = v;
	newnode->next=(*arr)[u-1];
	(*arr)[u-1]=newnode;
}

void printList(node **arr, int n)
{
	int i;
	node * tra;

	for(i=0;i<n;i++)
	{
		tra = arr[i];
		while(tra!=NULL)
		{
			printf("%d ",tra->v);
			tra=tra->next;
		}
		printf("\n");
	}
}
