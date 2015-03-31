#include <stdio.h>

int main(int argc, char *argv[])
{
	FILE *fp;
	fp = fopen(argv[1],"r");
	int a,j;
	char c[9];
	while(!feof(fp))
	{
		fscanf(fp,"%d %s %d",&a,c,&j);
		printf("%d %s %d\n",a,c,j);
	}
	return 1;
}

