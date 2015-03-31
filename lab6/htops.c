#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "htops.h"

int prime(int a)
{
	int i,flag=0,j;
	for(j=a;;j++)
	{
		for(i=2;i<=a/2;i++)
		{
			if(j%i==0)
			{
				flag=1;
				break;
			}
		}
		if(flag==0)
			return a;
	}
}

int sumOfDigits(int num)
{
	int sum=0;
	while(num!=0)
	{
		sum+=num%10;
		num/=10;
	}
	return sum;
}

int hash1(char *key, int size)
{
	int sum,i,p;
	sum=0;
	for(i=0;i<8;i++)
		sum+=key[i];
	p = prime(size+1);
	return (sum%p)%size;
}

int hash2(int key, int size)
{
	return sumOfDigits(key)%size;
}


Hash_item * populateHashTable(char *filename)
{
	Hash_item *ht;
	Node node;
	SIZE_T = 100;
	ht = malloc(sizeof(Hash_item )*SIZE_T);
	int h1,h2,i,j;
	FILE *fp;
	char c[9];
	fp = fopen(filename,"r");
	while(!feof(fp))
	{
		fscanf(fp,"%d %s %d",&i,c,&j);
		node.cust_id = i;
		strcpy(node.item_code,c);
		node.item_cost = j;
		h1 = hash1(node.item_code,SIZE_T);
		h2 = hash2(node.cust_id,20);
		if(ht[h1].CSIZE!=20)
		{
			ht[h1].CSIZE = 20;
			ht[h1].hashId = malloc(sizeof(Hash_id)*20);
		}
		ht[h1].hashId[h2]=node;
	}
	return ht;
}

void printHT(Hash_item *ht, int htsize, FILE *fp)
{
	int i,j;
	Node node;
	for(i=0;i<htsize;i++)
	{
		fprintf(fp,"\nHash_item %d\n\n",(i+1));
		if(ht[i].CSIZE==20)
			for(j=0;j<ht[i].CSIZE;j++)
			{
				node = ht[i].hashId[j];
				if(node.cust_id!=0)
					fprintf(fp,"custid %d  item code %s  item cost %d\n",node.cust_id,node.item_code,node.item_cost);
			}
	}
}
