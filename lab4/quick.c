#include<stdio.h>

void sort(int* arr, int p, int r)
{
	if(p<r)
	{
		int q = Partition(arr, p, r);
		sort(arr,p,q-1);
		sort(arr,q+1,r);
	}
}
