#include "traverse.h"

void dfs(int i, int **g, int *visited, int n, int *sum)
{
	int j;
	printf("%d\n",i);
	for(j=0;j<n;j++)
	{
		if(visited[j]!=1 && g[i][j]!=0)
		{
			(*sum)+=g[i][j];
			dfs(j,g,visited,n,sum);
		}
	}
	visited[i]=1;
}
