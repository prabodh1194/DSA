#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
	FILE *fp,*ofp;
	fp = fopen(argv[1],"r");
	int i,n,m,**a,x,y,*k,j;
	fscanf(fp,"%d",&n);
	fscanf(fp,"%d",&m);
	a = (int *)malloc(sizeof(int *)*n);
	for(i=0;i<n;i++)
	{
		a[i] = malloc(sizeof(int)*n);
	}
	while(!feof(fp))
	{
		fscanf(fp,"%d %d",&x,&y);
		a[x-1][y-1] = 1;
	}
	
	fclose(fp);
	
	ofp = fopen("output.txt","w");
	
	for(i=0;i<n;i++)
	{
		if(k[i]==0)
		{
			initializeArr(&k,n);
			int count = 0;
			findComp(a,n,i,k);
			for(j=0;j<n;j++)
			{
				if(k[j]==1)
					fprintf(ofp,"%d ",j+1);
			}
			fprintf(ofp,"\n");
		}
	}
	fclose(ofp);
	return 1;
}
