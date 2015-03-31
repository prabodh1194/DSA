#include <stdio.h>
#include <stdio.h>

void merge(int *arr, int p, int q, int r)
{
	int n1 = q-p+1;
	int n2 = r-q;
	//printf("\n**** %d,%d\n",n1,n2);
	int *left,*right;
	left = malloc((n1+1)*sizeof(int));
	right = malloc((n2+1)*sizeof(int));
	int k,i,j;
	for(i=0;i<n1;i++)
	{
		left[i]=arr[p+i];
	}
	left[n1]=10000000;
	for(j=0;j<n2;j++)
	{
		right[j]=arr[q+j+1];
	}
	right[n2]=10000000;
	i=0;
	j=0;
	for(k=p;k<=r;k++)
	{
		if(left[i]<=right[j])
			arr[k]=left[i++];
		else
			arr[k]=right[j++];
	}
}

void sort(int *arr, int beg, int top)
{
	int mid = (beg+top)/2;
	if(beg<top)
	{
		sort(arr, beg, mid);
		sort(arr, mid+1, top);
		merge(arr, beg, mid, top);
	}
}
