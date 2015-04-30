#include <stdio.h>
#include <stdlib.h>

static inline int countLines(FILE *fp)
{
	char c;
	int count=0;
	do
	{
		c=fgetc(fp);
		if(c == '\n')
		count++;
	}
	while (c!= EOF);
	return count;
}

int main(int argc, char *argv[])
{
	FILE *fp;
	int line_count, i,j, **g,*visited;
	if(argc != 2)
	{
		fprintf(stderr, "Usage: %s <filename>", argv[0]);
		exit(-1);
	}
	fp= fopen(argv[1], "r");
	line_count = countLines (fp);
	rewind(fp);
	
	g = (int *)malloc(sizeof(int *)*line_count);
	visited = malloc(sizeof(int)*line_count);
	
	for(i=0;i<line_count;i++)
	{
		g[i] = malloc(sizeof(int)*line_count);
	}
	for (i=0; i< line_count; i++)
	{
		visited[i]=0;
		for(j=0;j<line_count;j++)
		{
			if(!feof(fp))
			{
				fscanf(fp,"%d",&g[i][j]);
			}
		}
	}
	
	int sum=0;
	
	dfs(0,g,visited,line_count,&sum);
	printf("\n%d\n",sum);
	
	bfs(0,g,line_count);
	
	fclose(fp);
	return 1;
}
