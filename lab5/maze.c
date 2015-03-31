#include <stdio.h>
#include <stdlib.h>
#include "Maze.h"

int main(int argc, int *argv[])
{	
	int l,i,j,k;
	Maze m;
	l = createMaze(&m,argv[1]);
	for(i=0;i<l;i++)
	{
		printf("\n");
		for(j=0;j<l;j++)
			printf("%d ",m[i][j]);
	}
	
	char path[100];

	findCheese(m, 0, 0,path , 0, 0);
	printf("\n%s\n",path);
	return 1;
}
