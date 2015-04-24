#ifndef __BTREE_H
#define __BTREE_H

int t;

struct btree
{
	int *keys;
	int n;
	int leaf;
	struct btree **c;
};

typedef struct btree btree;

void allocate(btree *b);
void btreeInsert(btree *b,int key);
void btreeSplit(btree *b,int i);
void btreeInsertNonfull(btree *b,int key);
#endif
