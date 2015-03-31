#include<stdio.h>

//partition using last element
int Partition(int *arr, int p, int r)
{
	int j,temp,x,i;
	x = arr[r];
	i = p-1;
	for(j=p;j<r;j++)
	{
		if(arr[j]<=x)
		{
			i+=1;
			temp=arr[j];
			arr[j]=arr[i];
			arr[i]=temp;
		}
	}
	temp=arr[i+1];
	arr[i+1]=arr[r];
	arr[r]=temp;
	return i+1;
}	
