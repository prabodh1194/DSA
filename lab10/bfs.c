#include "traverse.h"

void bfs(int i, int **g, int n)
{
	int *visited,v,j;
	visited = malloc(sizeof(int)*n);
	Queue q;
	createQueue(q,n);
	
	q.enqueue(&q,i);
	visited[i]=1;
	while(!q.isEmpty())
	{
		v=q.dequeue(&q);
		for(j=0;j<n;j++)
		{
			if(visited[j]==0 && g[i][j]!=0)
			{
				q.enqueue(&q,j);
				visited[j]=1;
			}
		}
	}
}
