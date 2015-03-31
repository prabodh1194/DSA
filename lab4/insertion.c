#include<stdio.h>

void sort(int* arr, long int N)
{
	int i,j;
	int key;
	for(i=1;i<N;i++)
	{
		key = arr[i];
		j = i-1;
		while(j>=0 && arr[j]>key)
		{
			arr[j+1] = arr[j];
			j--;
		}
		arr[j+1] = key;
	}
}
