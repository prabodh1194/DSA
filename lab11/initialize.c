#include <stdlib.h>

void initializeArr(int **k,int n)
{
	int i;
	*k = malloc(sizeof(int)*n);
	for(i=0;i<n;i++)
	{
		(*k)[i]=0;
	}
}
