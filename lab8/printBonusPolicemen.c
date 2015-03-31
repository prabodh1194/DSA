#include "PoliceTreeOps.h"


static inline int getMaxamount(PoliceTree root)
{
		PoliceTree p=root;
		if(p == NULL)
				return 0;

		if(p->right  == NULL)
				return p->amount;
		while(p->right !=NULL)
		{
			p=p->right;
		}
		return p->amount;
}

void printBonusPolicemen(PoliceTree root)
{
	PoliceTree p = root;
	FILE *ofp;
	ofp = fopen("bonus.txt","w");
	int maxAmount = abs(getMaxamount(root)*0.9);
	while(p->left!=NULL)
		p=p->left;
	while(p!=NULL)
	{
		if(p->amount>=maxAmount)
			fprintf(ofp,"%d,%d\n",p->id,p->amount);
		p=p->succ;
	}
	fclose(ofp);
	return;
}
