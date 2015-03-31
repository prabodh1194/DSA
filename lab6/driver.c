#include <stdio.h>
#include <stdlib.h>
#include "htops.h"

int main(int argc, char *args[])
{
	FILE *fp;
	Hash_item *ht;
	ht = populateHashTable(args[1]);
	fp = fopen(args[2],"w");
	printHT(ht,100,fp);
	return 1;
}
