#include <stdio.h>
#include <stdlib.h>
#include "list.h"

int main(int argc, char *argv[])
{

	int u,v,i,n;
	FILE *fp;
	fp=fopen(argv[1],"r");

	fscanf(fp,"%d",&n);
	arr = (node **)malloc(sizeof(node *)*n);
	for(i=0;i<n;i++)
		arr[i]=NULL;

	while(!feof(fp))
	{
		fscanf(fp,"%d,%d",&u,&v);
		addEdge(&arr,u,v);
	}
	printList(arr,n);

	return 1;
}
