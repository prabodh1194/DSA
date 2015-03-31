#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "MazeOps.h"

int createMaze(Maze *pm,char *mazefilename)
{
	FILE *fp;
	int l,i,j,k;
	char a[1000000];
	fp = fopen(mazefilename, "r");
	fscanf(fp,"%s",a);
	l = strlen(a);
	*pm = malloc(sizeof(int *)*10);
	for(i=0;i<10;i++)
		(*pm)[i]=malloc(sizeof(int)*10);	
	for(i=0;i<l;i++)
	{
		for(j=0;j<l;j++)
		{
			(*pm)[i][j]=a[j]-48; 
		}
		fscanf(fp,"%s",a);
	}
	return l;
}
