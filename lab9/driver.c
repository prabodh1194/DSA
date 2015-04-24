#include <stdio.h>
#include "btree.h"

void treetraverse(btree b);

int main(int argc, char *argv[])
{
	int key;
	t = atoi(argv[2]);
	FILE *fp;
	fp = fopen(argv[1],"r");
	btree *b;
	b = (btree *)malloc(sizeof(btree));
	allocate(b);
	while(!feof(fp))
	{
		fscanf(fp,"%d",&key);
		btreeInsert(b,key);
	}
	
	treetraverse(*b);

	return 0;
}

void treetraverse(btree b)
{
	int k,i,j;
	k=b.n;
	for(i=0;i<k;i++)
	{
		printf("%d ",b.keys[i]);
	}
	if(!b.leaf)
	{
		for(i=0;i<=k;i++)
		{
			treetraverse(*(b.c[i]));
		}
	}
}
