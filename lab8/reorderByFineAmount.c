#include "PoliceTreeOps.h"

static inline PoliceTree createTreeNode(PoliceId id, int amount)
{
	PoliceTree new = (PoliceTree) malloc(sizeof(PoliceTreeNode));
	if(new == NULL)
	{
		fprintf(stderr, "\nOut of memory while inserting in in_BST\n");
		exit(-1);
	}

	new->succ=NULL;
	new->left=NULL;
	new->right = NULL;
	new->amount = amount;
	new->id=id;
	return new;
}

static inline PoliceTree insertByFine(PoliceTree root, PoliceTree new)
{
	PoliceTree p, prev, succ;
	p=prev=succ = NULL;
	if(root == NULL)
	{
		PoliceTree new2=createTreeNode(new->id, new->amount);
		return new2;
	}
	p=root;
	while (p != NULL)
	{
		if(new->amount <= p->amount) // search left tree
		{
			succ = p;
			if (p->left == NULL)
			{
				PoliceTree new2= createTreeNode(new->id, new->amount);
				p->left = new2;
				//						new2->succ = succ;
				if(prev != NULL)
				{
					new2->succ = prev->succ;
					prev->succ = new2;
				}
				else
					new2->succ=succ;
				return root;
			}
			p=p->left;
		}
		else // search right tree
		{
			prev=p;
			if (p->right== NULL)
			{
				PoliceTree new2= createTreeNode(new->id, new->amount);
				p->right = new2;
				if(prev != NULL)
				{
					new2->succ = prev->succ;
					prev->succ = new2;
				}
				else
					new2->succ=succ;

				/*
				   new2->succ = prev->succ;
				   prev->succ = new2;
				   */
				return root;
			}
			p=p->right;
		}
	}
	return root;
}

PoliceTree reorderByFineAmount(PoliceTree root)
{
	PoliceTree p = root;
	PoliceTree q=NULL;
	while(p->left!=NULL)
		p=p->left;
	while(p!=NULL)
	{
		q=insertByFine(q,p);
		p=p->succ;
	}
	return q;
}
