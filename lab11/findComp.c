void findComp(int **a,int n,int r,int *k)
{
	int i,j;
	if((k)[r]==0)
	{
		(k)[r]=1;
		for(j=0;j<n;j++)
		{
			if(a[r][j]==1)
			{
				findComp(a,n,j,k);
			}
		}
	}
}
