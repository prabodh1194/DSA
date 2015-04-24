#include <stdio.h>
#include "btree.h"
#include <stdlib.h>

void allocate(btree *b)
{
	b->keys = malloc(sizeof(int)*(2*t-1));
	b->n=0;
	b->leaf=1;
	b->c = malloc(sizeof(btree *)*(2*t));
}

void btreeInsert(btree *b,int key)
{
	btree r;
	if(b->n == 2*t-1)
	{
		btree *s;
		s = (btree *)malloc(sizeof(btree));
		allocate(s);
		s->leaf = 0;
		s->c[0] = b;
		btreeSplit(s,1);
		btreeInsertNonfull(s,key);
	}
	else
		btreeInsertNonfull(b,key);
}

void btreeSplit(btree *b,int i)
{
	int j;
	btree *z,*y;
	y = b->c[i-1];
	z = (btree *)malloc(sizeof(btree));
	allocate(z);
	z->leaf = y->leaf;
	z->n = t-1;
	for(j=0;j<t-1;j++)
		z->keys[j] = y->keys[j+t];
	if(!y->leaf)
	{
		for(j=0;j<t;j++)
			z->c[j]=y->c[j+t];
	}
	y->n=t-1;
	b->c[i]=z;
	for(j=b->n;j>=i;j--)
		b->c[j+1] = b->c[j];
	for(j=b->n-1;j>=i-1;j--)
		b->keys[j+1] = b->keys[j];
	b->keys[i-1] = y->keys[t-1];
	b->n+=1;
}
void btreeInsertNonfull(btree *b,int key)
{
	int i;
	i = b->n-1;
	if(b->leaf)
	{
		while(i>=0 && key<b->keys[i])
		{
			b->keys[i+1] = b->keys[i];
			i-=1;
		}
		b->keys[i+1]=key;
		b->n+=1;
	}
	else
	{
		while(i>=0 && key<b->keys[i])
		{
			i-=1;
		}
		i+=1;
		if(b->c[i]->n==2*t-1)
		{
			btreeSplit(b,i);
			if(key>b->keys[i])
				i+=1;
		}
		btreeInsertNonfull(b->c[i],key);
	}
}
