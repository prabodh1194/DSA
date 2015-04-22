#ifndef __TRIES_H
#define __TRIES_H

typedef Node * node;
struct Node
{
	char a;
	node children[26];
};

void insert(node *root, char *word);
#endif
